#include "app.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Application::Application() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    _window =
        SDL_CreateWindow("FUT Game", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, 810, 810, SDL_WINDOW_SHOWN);

    _renderer = SDL_CreateRenderer(_window, -1, 0);

    _font = TTF_OpenFont("Roboto-Regular.ttf", 46);

    load_db_players();
    load_db_users();
    load_db_cards();
}

Application::~Application() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Application::load_db_players() {
    std::ifstream file;
    file.open("db/clean_player_db.csv");

    if (!file) {
        std::cerr << "Can not open file \n" << std::endl;
        exit(1);
    }

    else {
        std::string delim = ",";
        std::string line;
        getline(file, line);

        // Parsing the CSV file containing all the information and generating the player according to it
        while (getline(file, line)) {
            std::vector<std::string> vect_string;
            for (uint8_t i = 0; i < 12; i++) {
                vect_string.push_back(line.substr(0, line.find(delim)));
                line.erase(0, line.find(delim) + delim.length());
            }

            if (vect_string[4] == "GK") {
                Goalkeeper new_player = Goalkeeper(
                    std::stoi(vect_string[0]), vect_string[1], vect_string[2],
                    vect_string[3], std::stoi(vect_string[5]),
                    std::stoi(vect_string[6]), std::stoi(vect_string[7]),
                    std::stoi(vect_string[8]), std::stoi(vect_string[9]),
                    std::stoi(vect_string[10]), std::stoi(vect_string[11]));
                db_players.push_back(new_player);
            }
            else {
                FieldPlayer new_player = FieldPlayer(
                    std::stoi(vect_string[0]), vect_string[1], vect_string[2],
                    vect_string[3], vect_string[4], std::stoi(vect_string[5]),
                    std::stoi(vect_string[6]), std::stoi(vect_string[7]),
                    std::stoi(vect_string[8]), std::stoi(vect_string[9]),
                    std::stoi(vect_string[10]), std::stoi(vect_string[11]));
                db_players.push_back(new_player);
            }

            vect_string.clear();
        }
    }

    file.close();
}

void Application::load_db_users() {
    std::ifstream file;
    file.open("db/user_db.csv");

    if (!file) {
        std::cerr << "Can not open file \n" << std::endl;
        exit(1);
    }

    else {
        uint8_t cpt = 0;
        std::string delim = ",";
        std::string line;
        std::vector<std::vector<std::string>> vect_vect_string(10);

        uint64_t id;
        std::string name;
        std::vector<Player*> team;
        std::vector<Player*> players;
        std::vector<Card*> cards;

        // Parsing the CSV file containing all the information and generating the Users according to it, note : cpt is counting the line. SO if the amount of line change you have to change cpt here.
        while (getline(file, line)) {
            for (uint8_t i = 0; i < 255; i++) {
                if (line.substr(0, line.find(delim)) == "id") {
                    vect_vect_string[cpt].push_back(
                        line.substr(0, line.find(delim)));
                    line.erase(0, line.find(delim) + delim.length());
                }

                else if (line.substr(0, line.find(delim)) != "\\") {
                    vect_vect_string[cpt].push_back(
                        line.substr(0, line.find(delim)));
                    line.erase(0, line.find(delim) + delim.length());
                }

                else {
                    cpt += 1;
                    line.erase(0, line.find(delim) + delim.length());
                    break;
                }
            }
            // When cpt it 7, we have all the information to generate the User. Otherwise we keep reading and deserialize the User
            if (cpt == 7) {
                team.clear();
                players.clear();
                cards.clear();

                // std::cout << "CREATION OF THE USER RIGHT HERE\n\n";
                for (std::vector<std::vector<std::string>>::size_type i = 0;
                    i < vect_vect_string.size(); i++) {
                    switch (i) {
                    case 0:
                        id = std::stoi(vect_vect_string[i].back());
                        break;

                    case 1:
                        name = vect_vect_string[i].back();
                        break;

                        // We should have used maps, so that we could
                        // have easily used ids to find anything.I
                    case 2:
                        for (std::vector<
                            std::vector<std::string>>::size_type j = 1;
                            j < vect_vect_string[i].size(); j++) {

                            team.push_back(get_player_by_id(
                                std::stoi(vect_vect_string[i][j])));
                        }

                        break;
                    case 5:

                        for (std::vector<
                            std::vector<std::string>>::size_type j = 1;
                            j < vect_vect_string[i].size(); j++) {
                            players.push_back(get_player_by_id(
                                std::stoi(vect_vect_string[i][j])));
                        }
                        break;
                    }

                    for (std::vector<std::vector<std::string>>::size_type j =
                        vect_vect_string[i].size();
                        j > 0; j--) {
                        vect_vect_string[i].pop_back();
                    }
                }

                Team* new_team = new Team(team, cards);

                User new_user = User(id, name, new_team, players, cards);
                db_users.push_back(new_user);
                cpt = 0;
                // std::cout << "END OF THE USER\n\n";
            }
        }
    }

    file.close();
}

void Application::load_db_cards() {
    for (auto& player : db_players) {
        db_cards.push_back(Card(&player));
    }
}

void Application::select_user(uint64_t user_id) {
    if (user_id > db_users.size()) {
        std::cerr << "ERROR : The user_id you are looking for is not "
            "attributed < select_user , app.cpp >\n"
            << std::endl;
    }
    else {
        current_user = &db_users[user_id];
    }
}

Player* Application::get_player_by_id(uint64_t id) {
    for (u_int32_t i = 0; i < db_players.size(); i++) {
        if (db_players[i].get_id() == id) {
            return &db_players[i];
        }
    }
    return NULL;
}

Card* Application::get_card_by_id(uint64_t id) {
    for (u_int32_t i = 0; i < db_cards.size(); i++) {
        if (db_cards[i].get_id() == id) {
            return &db_cards[i];
        }
    }
    return NULL;
}

Player* Application::get_rand_player() {
    return &db_players.at(std::rand() % db_players.size());
}

void Application::print_db_players() {
    for (std::vector<User>::size_type i = 0; i < db_players.size(); i++) {
        db_players[i].print_player();
    }
    std::cout << std::endl;
}

void Application::print_db_users() {
    for (std::vector<User>::size_type i = 0; i < db_users.size(); i++) {
        db_users[i].get_name();
    }
    std::cout << std::endl;
}

void Application::draw_cards_collection(uint32_t page) {
    for (std::vector<Card>::size_type i = page * 20;
        i < page * 20 + 20 && i < current_user->get_vect_cards().size(); i++) {
        draw_button(162 * ((i - page * 20) % 5), 202 * ((i - page * 20) / 5),
            162, 202, " ");
        current_user->get_vect_cards()[i]->draw(
            _renderer, 162 * ((i - page * 20) % 5), 202 * ((i - page * 20) / 5),
            162, 202);
    }
}

void Application::draw_team() {
    int position[11][4]{
        {243, 0, 162, 202},   {405, 0, 162, 202},   {81, 202, 162, 202},
        {243, 202, 162, 202}, {405, 202, 162, 202}, {567, 202, 162, 202},
        {81, 404, 162, 202},  {243, 404, 162, 202}, {405, 404, 162, 202},
        {567, 404, 162, 202}, {324, 606, 162, 202} };

    for (int i = 0; i < 11; i++) {
        draw_button(position[i][0], position[i][1], position[i][2],
            position[i][3], " ");
        current_user->get_team()->get_vect_card()[10 - i]->draw(
            _renderer, position[i][0], position[i][1], position[i][2],
            position[i][3]);
    }
}

void Application::draw_button(int button_x, int button_y, int button_w,
    int button_h, std::string text) {
    SDL_Rect rect;
    rect.x = button_x;
    rect.y = button_y;
    rect.w = button_w;
    rect.h = button_h;

    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(_renderer, &rect);

    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(_renderer, &rect);

    SDL_Color color = { 255, 255, 255, 255 };
    SDL_Surface* surface = TTF_RenderText_Solid(_font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);

    SDL_Rect rect_text;
    rect_text.x = button_x + button_w / 2 - surface->w / 2;
    rect_text.y = button_y + button_h / 2 - surface->h / 2;
    rect_text.w = surface->w;
    rect_text.h = surface->h;

    SDL_RenderCopy(_renderer, texture, NULL, &rect_text);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Application::draw_blank_card() {
    SDL_Surface* card = IMG_Load("Sources/Assets/rare-gold-23.png");
    SDL_Texture* card_texture = SDL_CreateTextureFromSurface(_renderer, card);
    SDL_Rect rect_card = { 334, 304, 142, 202 };
    SDL_RenderCopy(_renderer, card_texture, NULL, &rect_card);
    SDL_FreeSurface(card);
    SDL_DestroyTexture(card_texture);
}

Card* Application::open_pack() {
    Player* player = get_rand_player();
    current_user->add_player(player);
    Card* card = get_card_by_id(player->get_id());
    current_user->add_card(card);
    return card;
}

void Application::draw_pack_button() {
    SDL_Surface* card = IMG_Load("Sources/Assets/rare-gold-23.png");
    SDL_Texture* card_texture = SDL_CreateTextureFromSurface(_renderer, card);
    SDL_Rect rect_card = { 0, 0, 50, 70 };
    SDL_RenderCopy(_renderer, card_texture, NULL, &rect_card);
    SDL_FreeSurface(card);
    SDL_DestroyTexture(card_texture);
}

// erase card in team, add it to collection and vice versa
void Application::swap_card(int index_team, int index_collection) {
    if (index_team < (int)current_user->get_team()->get_vect_card().size() &&
        index_collection < (int)current_user->get_vect_cards().size()) {
        Card* team_card = new Card(*current_user->get_team()->get_vect_card()[index_team]);
        Card* collection_card = new Card(*current_user->get_vect_cards()[index_collection]);

        current_user->remove_card(current_user->get_vect_cards()[index_collection]);
        current_user->remove_player(team_card->get_player());
        current_user->get_team()->remove_card(current_user->get_team()->get_vect_card()[index_team]);
        current_user->get_team()->remove_from_team(collection_card->get_player());
        

        current_user->add_card(team_card);
        current_user->add_player(collection_card->get_player());
        current_user->get_team()->add_card(collection_card, index_team);
        current_user->get_team()->add_to_team(team_card->get_player());

    }
}

void Application::run() {
    bool quit = false;
    int screen = 1;
    int page = 0;
    int index_team = 0;
    int index_collection = 0;
    int swap = 0;
    Card* card = NULL;
    while (!quit) {
        while (SDL_PollEvent(&_event)) {
            switch (_event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (_event.key.keysym.sym) {
                case SDLK_LEFT:
                    if (screen == 1) {
                        if (page > 0) {
                            page--;
                        }
                    }
                    break;
                case SDLK_RIGHT:
                    if (screen == 1) {
                        if (page < 23) {
                            page++;
                        }
                    }
                    break;
                case SDLK_RETURN:
                    if (screen == 1) {
                        screen = 2;
                        break;
                    }
                    if (screen == 2) {
                        screen = 1;
                        break;
                    }
                    if (screen == 3) {
                        screen = 4;
                        break;
                    }
                    if (screen == 5) {
                        screen = 2;
                        break;
                    }
                    break;
                }

            case SDL_MOUSEBUTTONDOWN:
                if (_event.button.button == SDL_BUTTON_LEFT) {
                    int x = _event.button.x;
                    int y = _event.button.y;
                    if (screen == 2) {
                        if (x > 0 && x < 50 && y > 0 && y < 70) {
                            screen = 3;
                        }
                        else if (x > 243 && x < 405 && y > 0 && y < 202) {
                            index_team = 10;
                            screen = 1;
                        }
                        else if (x > 405 && x < 567 && y > 0 && y < 202) {
                            index_team = 9;
                            screen = 1;
                        }
                        else if (x > 81 && x < 243 && y > 202 &&
                            y < 404) {
                            index_team = 8;
                            screen = 1;
                        }
                        else if (x > 243 && x < 405 && y > 202 &&
                            y < 404) {
                            index_team = 7;
                            screen = 1;
                        }
                        else if (x > 405 && x < 567 && y > 202 &&
                            y < 404) {
                            index_team = 6;
                            screen = 1;
                        }
                        else if (x > 567 && x < 729 && y > 202 &&
                            y < 404) {
                            index_team = 5;
                            screen = 1;
                        }
                        else if (x > 81 && x < 243 && y > 404 &&
                            y < 606) {
                            index_team = 4;
                            screen = 1;
                        }
                        else if (x > 243 && x < 405 && y > 404 &&
                            y < 606) {
                            index_team = 3;
                            screen = 1;
                        }
                        else if (x > 405 && x < 567 && y > 404 &&
                            y < 606) {
                            index_team = 2;
                            screen = 1;
                        }
                        else if (x > 567 && x < 729 && y > 404 &&
                            y < 606) {
                            index_team = 1;
                            screen = 1;
                        }
                        else if (x > 324 && x < 486 && y > 606 &&
                            y < 808) {
                            index_team = 0;
                            screen = 1;
                        }
                    }
                    else if (screen == 1) {
                        if (x > 0 && x < 162 && y > 0 && y < 202) {
                            index_collection = 0 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 162 && x < 324 && y > 0 && y < 202) {
                            index_collection = 1 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 324 && x < 486 && y > 0 && y < 202) {
                            index_collection = 2 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 486 && x < 648 && y > 0 && y < 202) {
                            index_collection = 3 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 648 && x < 810 && y > 0 && y < 202) {
                            index_collection = 4 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 0 && x < 162 && y > 202 && y < 404) {
                            index_collection = 5 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 162 && x < 324 && y > 202 &&
                            y < 404) {
                            index_collection = 6 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 324 && x < 486 && y > 202 &&
                            y < 404) {
                            index_collection = 7 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 486 && x < 648 && y > 202 &&
                            y < 404) {
                            index_collection = 8 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 648 && x < 810 && y > 202 &&
                            y < 404) {
                            index_collection = 9 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 0 && x < 162 && y > 404 && y < 606) {
                            index_collection = 10 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 162 && x < 324 && y > 404 &&
                            y < 606) {
                            index_collection = 11 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 324 && x < 486 && y > 404 &&
                            y < 606) {
                            index_collection = 12 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 486 && x < 648 && y > 404 &&
                            y < 606) {
                            index_collection = 13 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 648 && x < 810 && y > 404 &&
                            y < 606) {
                            index_collection = 14 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 0 && x < 162 && y > 606 && y < 808) {
                            index_collection = 15 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 162 && x < 324 && y > 606 &&
                            y < 808) {
                            index_collection = 16 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 324 && x < 486 && y > 606 &&
                            y < 808) {
                            index_collection = 17 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 486 && x < 648 && y > 606 &&
                            y < 808) {
                            index_collection = 18 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                        else if (x > 648 && x < 810 && y > 606 &&
                            y < 808) {
                            index_collection = 19 + 20 * page;
                            screen = 2;
                            swap = 1;
                        }
                    }
                }
                break;
            }

            SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

            SDL_RenderClear(_renderer);

            switch (screen) {
            case 1:
                draw_cards_collection(page);
                break;

            case 2:
                if (swap == 1) {
                    std::cout << "swap" << std::endl;
                    std::cout << index_collection << std::endl;
                    std::cout << index_team << std::endl;
                    swap_card(index_team, index_collection);
                    swap = 0;
                }
                draw_pack_button();
                draw_team();
                break;

            case 3:
                draw_blank_card();
                break;

            case 4:
                card = open_pack();
                screen = 5;
                break;

            case 5:
                card->draw(_renderer, 324, 304, 162, 202);
                break;
            }
            SDL_RenderPresent(_renderer);
        }
    }
}
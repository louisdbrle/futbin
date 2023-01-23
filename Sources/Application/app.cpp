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
                         SDL_WINDOWPOS_UNDEFINED, 850, 850, SDL_WINDOW_SHOWN);

    _renderer = SDL_CreateRenderer(_window, -1, 0);

    load_db_players();
    load_db_users();
    load_db_cards();
}

Application::~Application() {
    // delete [] current_user;
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
            } else {
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
    // std::cerr << "TODO : Not implemented yet < load_db_users , app.cpp >\n"
    // << std::endl; std::cerr << "---- Have to take sometime to think about
    // that, as it is harder due to pointer usage --- \n" << std::endl;

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
                            // std::cout << "Id : " << id << "\n";
                            break;

                        case 1:
                            name = vect_vect_string[i].back();
                            // std::cout << "Name : " << name << "\n";
                            break;

                        case 2:
                            // std::cout << "Team1 : ";
                            for (std::vector<
                                     std::vector<std::string>>::size_type j = 1;
                                 j < vect_vect_string[i].size(); j++) {
                                // We should have used maps, so that we could
                                // have easily used ids to find anything.
                                team.push_back(get_player_by_id(
                                    std::stoi(vect_vect_string[i][j])));
                                // std::cout << vect_vect_string[i][j] << " ";
                            }
                            // std::cout << "\n";
                            break;
                        case 5:
                            // std::cout << "Players : ";
                            for (std::vector<
                                     std::vector<std::string>>::size_type j = 1;
                                 j < vect_vect_string[i].size(); j++) {
                                // We should have used maps, so that we could
                                // have easily used ids to find anything.
                                players.push_back(get_player_by_id(
                                    std::stoi(vect_vect_string[i][j])));
                                // std::cout << vect_vect_string[i][j] << " ";
                            }
                            // std::cout << "\n";
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

                // std::cout << "\n";
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
    } else {
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
        db_users[i].print_user();
    }
    std::cout << std::endl;
}

void Application::draw_cards_collection() {
    for (std::vector<Card>::size_type i = 0;
         i < current_user->get_vect_cards().size(); i++) {
        current_user->get_vect_cards()[i]->draw(_renderer, 162 * i,
                                                202 * (i % 3), 162, 202);
    }
}

void Application::run() {
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&_event)) {
            if (_event.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
        SDL_RenderClear(_renderer);

        draw_cards_collection();

        SDL_RenderPresent(_renderer);
    }
}
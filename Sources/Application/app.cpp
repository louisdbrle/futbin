#include "app.hpp"

Application::Application() {
    this->load_db_users();
    this->load_db_players();
    this->load_db_coachs();
}

Application::~Application() {
    delete [] current_user;
}

void Application::load_db_users() {
    std::cerr << "TODO : Not implemented yet < load_db_players , app.cpp >\n" << std::endl;
}

void Application::load_db_players() {
    std::cerr << "TODO : Not implemented yet < load_db_players , app.cpp >\n" << std::endl;
}

void Application::load_db_coachs() {
    std::cerr << "TODO : Not implemented yet < load_db_players , app.cpp >\n" << std::endl;
}

void Application::select_user(uint64_t user_id) {
    if (user_id > db_users.size()) {
        std::cerr << "ERROR : The user_id you are looking for is not attributed < select_user , app.cpp >\n" << std::endl;
    }
    else {
        current_user = &db_users[user_id];
    }

}


Player* Application::get_rand_player() {
    return &db_players.at(std::rand() % db_players.size());
}

std::vector<Player*> Application::draw_player_card() {

    std::vector<Player*> vect;
    vect.reserve(6);

    for (u_int32_t i = 0; i < vect.size(); i++) {
        vect.push_back(get_rand_player());
    }
    return vect;
}

std::vector<Player*> Application::draw_player_card(uint8_t nb_card) {

    std::vector<Player*> vect;
    vect.reserve(nb_card);

    for (u_int32_t i = 0; i < vect.size(); i++) {
        vect.push_back(get_rand_player());
    }
    return vect;
}

Coach* Application::get_rand_coach() {
    return &db_coachs.at(std::rand() % db_coachs.size());
}

std::vector<Coach*> Application::draw_coach_card() {

    std::vector<Coach*> vect;
    vect.reserve(3);

    for (u_int32_t i = 0; i < vect.size(); i++) {
        vect.push_back(get_rand_coach());
    }
    return vect;
}

std::vector<Coach*> Application::draw_coach_card(uint8_t nb_card) {

    std::vector<Coach*> vect;
    vect.reserve(nb_card);

    for (u_int32_t i = 0; i < vect.size(); i++) {
        vect.push_back(get_rand_coach());
    }
    return vect;
}


void Application::print_db_players() {
    for (std::vector<User>::size_type i = 0; i < db_players.size(); i++) {
        db_players[i].print_player();
    }
    std::cout << std::endl;
}

void Application::print_db_coachs() {
    for (std::vector<User>::size_type i = 0; i < db_coachs.size(); i++) {
        db_coachs[i].print_coach();
    }
    std::cout << std::endl;
}

void Application::print_db_users() {
    for (std::vector<User>::size_type i = 0; i < db_users.size(); i++) {
        db_users[i].print_user();
    }
    std::cout << std::endl;
}

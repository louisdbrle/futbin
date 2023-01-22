#include <fstream>
#include <iostream>

#include "Sources/Application/app.hpp"
#include "Sources/FieldPlayer/fieldplayer.hpp"
#include "Sources/GoalKeeper/goalkeeper.hpp"
#include "Sources/Team/team.hpp"
#include "Sources/User/user.hpp"

#define TEST true

// Db loading function segment
std::vector<Player> load_db_players() {
    // read in json a player, create new players, add in at the end of the
    // vect_db_player
    std::vector<Player> vect;
    vect.reserve(6);

    std::cerr << "TODO : Not implemented yet < load_db_players , main.cpp >\n"
              << std::endl;

    return vect;
}

std::vector<Coach> load_db_coachs() {
    // read in json a user, create new user, add in at the end of the
    // vect_db_user
    std::vector<Coach> vect;
    vect.reserve(6);

    std::cerr << "TODO : Not implemented yet < load_db_coachs , main.cpp >\n"
              << std::endl;

    return vect;
}

std::vector<User> load_db_users() {
    // read in json a user, create new user, add in at the end of the
    // vect_db_user
    std::vector<User> vect;
    vect.reserve(6);

    std::cerr << "TODO : Not implemented yet < load_db_users , main.cpp >\n"
              << std::endl;

    return vect;
}

// Draw cards function segment
Player* get_rand_player(std::vector<Player>* db_players) {
    // std::cerr << "TODO : Not implemented yet < get_rand_player , main.cpp >"
    // << std::endl;
    return &db_players->at(std::rand() % db_players->size());
}

std::vector<Player*> draw_player_card(std::vector<Player>* db_players) {
    std::vector<Player*> vect;
    vect.reserve(6);

    for (u_int32_t i = 0; i < vect.size(); i++) {
        vect.push_back(get_rand_player(db_players));
    }
    return vect;
}

Coach* get_rand_coach(std::vector<Coach>* db_coachs) {
    // std::cerr << "TODO : Not implemented yet < get_rand_coach , main.cpp >"
    // << std::endl;
    return &db_coachs->at(std::rand() % db_coachs->size());
}

std::vector<Coach*> draw_coach_card(std::vector<Coach>* db_coachs) {
    std::vector<Coach*> vect;
    vect.reserve(3);

    for (u_int32_t i = 0; i < vect.size(); i++) {
        vect.push_back(get_rand_coach(db_coachs));
    }
    return vect;
}

// Debug printing function
void print_db_players(std::vector<Player>* db_players) {
    for (std::vector<User>::size_type i = 0; i < db_players->size(); i++) {
        (*db_players)[i].print_player();
    }
    std::cout << std::endl;
}

void print_db_users(std::vector<User>* db_users) {
    for (std::vector<User>::size_type i = 0; i < db_users->size(); i++) {
        (*db_users)[i].print_user();
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    // srand(time(NULL));

    // Application variable
    std::vector<Player> Db_players = load_db_players();
    std::vector<Coach> Db_coachs = load_db_coachs();
    std::vector<User> Db_users = load_db_users();
    User* current_user;

    if (TEST) {
        // Object creation for testing purpuses
        Goalkeeper goal = Goalkeeper(12, "GOALKEEPER", "_", 255, "FRENCH",
                                     "FC JUSSIEU", "FRANCE");
        FieldPlayer fieldplayer =
            FieldPlayer(12, "FIELDPLAYER", "_", 255, "FRENCH", "FC JUSSIEU",
                        "FRANCE", "ST");
        // Application variable update
        Db_players.push_back(goal);
        Db_players.push_back(fieldplayer);

        // ---Application variable--- //
        Application app = Application();

        User user_1 = User();
        User user_2 = User();
        app.db_users.push_back(user_1);
        app.db_users.push_back(user_2);

        // ---User selection usage--- //
        // app.select_user(0);
        // std::cout << app.current_user->get_name() << "\n" << std::endl;

        // ---Db printing--- //
        app.print_db_players();
        app.print_db_users();  //
        current_user = &Db_users[0];
        std::cout << current_user->get_name() << "\n" << std::endl;

        // ---Add of player in the team 0 of the current_user--- //
        // app.current_user->get_vect_team()[0]->add_to_team(&goal);

        // ---Printing of team 0's current_user for debugging--- //
        // app.current_user->get_vect_team()[0]->print_team();

        std::cout << " --- END of the programme running in test mode --- \n\n\n"
                  << std::endl;
    } else {
        std::cout
            << " --- START of the programme running in release mode --- \n\n\n"
            << std::endl;

        // ---Application variable--- //
        Application app = Application();

        std::cout
            << " --- END of the programme running in release mode --- \n\n\n"
            << std::endl;
    }

    return 0;
}

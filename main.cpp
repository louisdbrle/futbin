#include <iostream>

#include "Sources/Team/team.hpp"
#include "Sources/GoalKeeper/goalkeeper.hpp"
#include "Sources/FieldPlayer/fieldplayer.hpp"

#define TEST false

// Db loading function segment
std::vector<Player> load_db_players() {
    // read in json a player, create new players, add in at the end of the vect_db_player
    std::vector<Player> vect;
    vect.reserve(6);

    std::cerr << "TODO : Not implemented yet < load_db_players , main.cpp >\n" << std::endl;

    return vect;
}

std::vector<Coach> load_db_coachs() {
    // read in json a user, create new user, add in at the end of the vect_db_user
    std::vector<Coach> vect;
    vect.reserve(6);

    std::cerr << "TODO : Not implemented yet < load_db_coachs , main.cpp >\n" << std::endl;

    return vect;
}

std::vector<User> load_db_users() {
    // read in json a user, create new user, add in at the end of the vect_db_user
    std::vector<User> vect;
    vect.reserve(6);

    std::cerr << "TODO : Not implemented yet < load_db_users , main.cpp >\n" << std::endl;

    return vect;
}

// Draw cards function segment
Player* get_rand_player(std::vector<Player>* db_players) {
    //std::cerr << "TODO : Not implemented yet < get_rand_player , main.cpp >" << std::endl;
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
    //std::cerr << "TODO : Not implemented yet < get_rand_coach , main.cpp >" << std::endl;
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

void print_db_coachs(std::vector<Coach>* db_coachs) {
    for (std::vector<User>::size_type i = 0; i < db_coachs->size(); i++) {
        (*db_coachs)[i].print_coach();
    }
    std::cout << std::endl;
}

void print_db_users(std::vector<User>* db_users) {
    for (std::vector<User>::size_type i = 0; i < db_users->size(); i++) {
        (*db_users)[i].print_user();
    }
    std::cout << std::endl;
}




// Main function
int main(int argc, char** argv) {

    srand(time(NULL));

    // Application variable
    std::vector<Player> Db_players = load_db_players();
    std::vector<Coach> Db_coachs = load_db_coachs();
    std::vector<User> Db_users = load_db_users();
    User* current_user;

    if (TEST) {
        // Object creation for testing purpuses
        Goalkeeper goal = Goalkeeper("GOALKEEPER", "_", 255, "FRENCH", "FC JUSSIEU", "FRANCE");
        FieldPlayer fieldplayer = FieldPlayer("FIELDPLAYER", "_", 255, "FRENCH", "FC JUSSIEU", "FRANCE", ST);
        Coach coach = Coach("COACH", "_", 255, "FRENCH", "FRANCE");

        User user_1 = User();
        User user_2 = User();

        // Application variable update
        Db_players.push_back(goal);
        Db_players.push_back(fieldplayer);

        Db_coachs.push_back(coach);

        Db_users.push_back(user_1);
        Db_users.push_back(user_2);


        current_user = &Db_users[0];
        std::cout << current_user->get_name() << "\n" << std::endl;

        print_db_players(&Db_players);
        print_db_coachs(&Db_coachs);
        print_db_users(&Db_users);

        get_rand_player(&Db_players)->print_player();
        std::cout << "\n" << std::endl;

        current_user->get_vect_team()[0]->add_to_team(&goal);
        current_user->get_vect_team()[0]->add_to_team(&goal);

        current_user->get_vect_team()[0]->print_team();
    }


    return 0;
}

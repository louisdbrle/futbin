#include "user.hpp"

User::User() {
    _vect_team.reserve(3);
    _vect_player.reserve(30);
    _vect_coach.reserve(3);
    _vect_historic_game.reserve(10);
    _name = "COACH NAME";
}

void User::print_collection() {
    std::cout << "TODO : Not implemented yet < print_collection(), user.cpp >" << std::endl;
}
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
void User::print_user() {
    //std::cout << "TODO : Not implemented yet < print_user(), user.cpp >" << std::endl;
    std::cout << "Coach : name = " << _name << std::endl;
    //std::cout << "Coach : name = " << _name << ",  vector_team = " << _vect_team << ", vector_coach = " << _vect_coach;
    //std::cout << ", vector_player = " << _vect_player << ", vector_histo = " << _vect_historic_game << std::endl;
}
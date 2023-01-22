#include "user.hpp"

User::User() {
    _vect_team.reserve(3);
    _vect_player.reserve(30);
    _vect_coach.reserve(3);
    _name = "COACH NAME";

    _vect_team.push_back(new Team());
    _vect_team.push_back(new Team());
    _vect_team.push_back(new Team());
}
User::User(uint64_t id, std::string name, Team* team1, Team* team2, Team* team3, std::vector <Player*> vect_player, std::vector <Coach*> vect_coach)
    : _id(id), _name(name), _vect_player(vect_player), _vect_coach(vect_coach) {
    _vect_team.push_back(team1);
    _vect_team.push_back(team2);
    _vect_team.push_back(team3);
}

User::User(std::string name): _name(name) {
    _vect_team.reserve(3);
    _vect_player.reserve(30);
    _vect_coach.reserve(3);
}
void User::print_collection() {
    //std::cout << "TODO : Not implemented yet < print_collection(), user.cpp >" << std::endl;
    std::cout << "Player collection : \n\n" << std::endl;
    for (auto player : _vect_player) {
        player->print_player();
    }
    std::cout << "Coach collection : \n\n" << std::endl;
    for (auto coach : _vect_coach) {
        coach->print_coach();
    }

}
void User::print_user() {
    //std::cout << "TODO : Not implemented yet < print_user(), user.cpp >" << std::endl;
    std::cout << "User : name = " << _name << std::endl;
    //std::cout << "Coach : name = " << _name << ",  vector_team = " << _vect_team << ", vector_coach = " << _vect_coach;
    //std::cout << ", vector_player = " << _vect_player << ", vector_histo = " << _vect_historic_game << std::endl;
}
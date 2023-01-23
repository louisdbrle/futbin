#include "user.hpp"

User::User() {
    _players.reserve(100);
    _cards.reserve(100);
    _name = "COACH NAME";
}

User::User(uint64_t id, std::string name, Team* team,
           std::vector<Player*> vect_player, std::vector<Card*> vect_cards)
    : _id(id),
      _name(name),
      _team(team),
      _players(vect_player),
      _cards(vect_cards) {}

User::User(std::string name) : _name(name) {
    _players.reserve(100);
    _cards.reserve(100);
}

void User::print_collection() {
    // std::cout << "TODO : Not implemented yet < print_collection(), user.cpp
    // >" << std::endl;
    std::cout << "Player collection : \n\n" << std::endl;
    for (auto player : _players) {
        player->print_player();
    }
}

void User::print_user() {
    // std::cout << "TODO : Not implemented yet < print_user(), user.cpp >" <<
    // std::endl;
    std::cout << "User : name = " << _name << std::endl;
    // vector_player = " << _vect_player << ", vector_histo = " <<
    // _vect_historic_game << std::endl;
}
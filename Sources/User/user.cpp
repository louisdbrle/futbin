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

void User::add_player(Player* player) { _players.push_back(player); }

void User::remove_player(Player* player) {
    std::vector<Player*>::iterator it = _players.begin();
    for (auto i : _players) {
        if (i == player) {
            _players.erase(it);
        }
        it++;
    }
}

void User::add_card(Card* card) { _cards.push_back(card); }

void User::remove_card(Card* card) {
    std::vector<Card*>::iterator it = _cards.begin();
    for (auto i : _cards) {
        if (i == card) {
            _cards.erase(it);
        }
        it++;
    }
}

#include "team.hpp"

Team::Team() {
    _vect_player.reserve(11);
    _vect_card.reserve(11);
}

Team::Team(std::vector<Player*>& vect_player, std::vector<Card*>& vect_card)
    : _vect_player(vect_player), _vect_card(vect_card) {}

Team::Team(Team& team) : _vect_player(team._vect_player) {}

void Team::print_team() {
    for (std::vector<Player*>::size_type i = 0; i < _vect_player.size(); i++) {
        _vect_player[i]->print_player();
    }
    std::cout << "\n" << std::endl;
}

void Team::add_to_team(Player* player) { _vect_player.push_back(player); }

void Team::remove_from_team(Player* player) {
    std::vector<Player*>::iterator it = _vect_player.begin();
    for (auto i : _vect_player) {
        if (i == player) {
            _vect_player.erase(it);
        }
        it++;
    }
}

void Team::add_card(Card* card, int index) {
    _vect_card.insert(_vect_card.begin() + index, card);
}

void Team::remove_card(Card* card) {
    std::vector<Card*>::iterator it = _vect_card.begin();
    for (auto i : _vect_card) {
        if (i == card) {
            _vect_card.erase(it);
        }
        it++;
    }
}

Team::~Team() {
    for (std::vector<Player*>::size_type i = 0; i < _vect_player.size(); i++) {
        delete _vect_player[i];
    }
    for (std::vector<Card*>::size_type i = 0; i < _vect_card.size(); i++) {
        delete _vect_card[i];
    }
}

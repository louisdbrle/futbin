#include "team.hpp"

Team::Team() {
    _vect_player.reserve(24);
    _vect_historic_match.reserve(10);
    _ptr_coach = NULL;
}

Team::Team(Team& team)
    : _vect_player(team._vect_player), _vect_historic_match(team._vect_historic_match), _ptr_coach(team._ptr_coach) {
}

Team::Team(Coach& coach) {
    _vect_player.reserve(24);
    _vect_historic_match.reserve(10);
    _ptr_coach = &coach;
}

void Team::print_team() {

    for (std::vector<Player*>::size_type i = 0; i < _vect_player.size(); i++) {
        _vect_player[i]->print_player();
    }
    std::cout << "\n" << std::endl;
}

void Team::add_to_team(Player* player) {
    _vect_player.push_back(player);
}

void Team::remove_from_team(Player* player) {
    std::vector<Player*>::iterator it = _vect_player.begin();
    for (auto i : _vect_player) {
        if (i == player) {
            _vect_player.erase(it);
        }
        it++;
    }
    //std::cout << "TODO : Not implemented yet < remove_from_team(), team.cpp >" << std::endl;
}
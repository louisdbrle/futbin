#pragma once

class Player;
class Match;
class Coach;

#include <iostream>
#include <vector>

#include "../Player/player.hpp"

class Team {
   public:
    Team();
    Team(std::vector<Player*>& vect_player);
    Team(Team& team);
    ~Team();

    std::vector<Player*> get_vect_player() { return _vect_player; }
    std::vector<Match*> get_vect_historic_match() {
        return _vect_historic_match;
    }

    void print_team();
    void add_to_team(Player* player);
    void remove_from_team(Player* player);

   private:
    std::vector<Player*> _vect_player;
    std::vector<Match*> _vect_historic_match;
};

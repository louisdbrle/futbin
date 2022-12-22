#pragma once

class Player;
class Match;
class Coach;

#include <iostream>
#include <vector>
#include "../Player/player.hpp"
#include "../Match/match.hpp"
#include "../Coach/coach.hpp"


class Team
{
public:
    Team();
    Team(Team& team);
    Team(Coach& _coach);
    //~Team();

    std::vector<Player*> get_vect_player() { return _vect_player; }
    std::vector<Match*> get_vect_historic_match() { return _vect_historic_match; }
    Coach* get_coach() { return _ptr_coach; }

private:
    std::vector<Player*> _vect_player;
    std::vector<Match*> _vect_historic_match;
    Coach* _ptr_coach;
};

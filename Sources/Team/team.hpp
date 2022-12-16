#pragma once

#include <iostream>
#include <vector>
#include "../Player/player.hpp"
#include "../Match/match.hpp"
#include "../Coach/coach.hpp"
//class Match;


class Team{
    public:
        Team();
        Team(std::vector<Player> vect_player, Coach &coach);
        //~Team();

        std::vector<Player> get_vect_player(){ return _vect_player;}
        std::vector<Match> get_vect_historic_match(){ return _vect_historic_match;}
        Coach get_coach(){ return _coach;}

    private:
        std::vector<Player> _vect_player;
        std::vector<Match> _vect_historic_match;
        Coach _coach;
        
};



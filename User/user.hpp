#pragma once

#include <iostream>

#include "../Team/team.hpp"
#include "../Player/player.hpp"
#include "../Coach/coach.hpp"

class User{
    public:
        User();
        //~User();

        Team get_team(){return _team;}
        Player* get_tab_player(){ return _tab_player;}
        Coach* get_tab_coach(){ return _tab_coach;}

    private:
        Team _team;
        Player _tab_player[30];
        Coach _tab_coach[30];
        
};

#pragma once

#include <iostream>
#include "../Player/player.hpp"
#include "../Coach/coach.hpp"


class Team{
    public:
        Team();
        //~Team();

        Player* get_tab_player(){ return _tab_player;}
        Coach get_coach(){ return _coach;}

    private:
        Player _tab_player[11];
        Coach _coach;
        
};

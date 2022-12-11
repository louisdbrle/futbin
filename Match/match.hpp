#pragma once

#include <iostream>
#include "../Team/team.hpp"


class Match{
    public:
        Match();
        //~Match();

        Team get_team_dom(){ return _team_dom;}
        Team get_team_ext(){ return _team_ext;}

    private:
        Team _team_dom;
        Team _team_ext;
        
};

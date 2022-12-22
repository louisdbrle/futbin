#pragma once

#include <iostream>
#include "../Team/team.hpp"
#include "../User/user.hpp"



class Match
{
public:
    Match();
    //~Match();

    Team* get_team_dom() { return _ptr_team_dom; }
    Team* get_team_ext() { return _ptr_team_ext; }

private:
    Team*  _ptr_team_dom;
    Team* _ptr_team_ext;
    User* _ptr_winner;
};

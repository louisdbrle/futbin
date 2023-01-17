#pragma once

#include <iostream>
#include "../Team/team.hpp"
#include "../User/user.hpp"



class Match {
public:
    //Match();
    Match(Team* ptr_team_dom, Team* ptr_team_ext);
    //~Match();

    Team* get_ptr_team_dom() { return _ptr_team_dom; }
    Team* get_ptr_team_ext() { return _ptr_team_ext; }
    Team* get_ptr_team_win() { return _ptr_team_win; }

private:
    Team* _ptr_team_dom;
    Team* _ptr_team_ext;
    Team* _ptr_team_win;
};

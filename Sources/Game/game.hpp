#pragma once

class User;

#include <iostream>
#include "../User/user.hpp"

class Game {
public:
    //Game();
    Game(User* ptr_user_dom, User* ptr_user_ext);
    //~Game();

    User* get_user_dom() { return _ptr_user_dom; }
    User* get_user_ext() { return _ptr_user_ext; }
    User* get_winner() { return _ptr_winner; }

    //void play_game(int index_team_dom, int index_team_ext);

private:
    User* _ptr_user_dom;
    User* _ptr_user_ext;
    User* _ptr_winner;
};

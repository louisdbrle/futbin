#pragma once
#include <iostream>
#include "../User/user.hpp"

class User;

class Game
{
public:
    Game();
    //~Game();

    User get_user_dom() { return _user_dom; }
    User get_user_ext() { return _user_ext; }
    User get_winner() { return _winner; }

private:
    User _user_dom;
    User _user_ext;
    User _winner;
};

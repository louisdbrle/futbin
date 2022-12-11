#pragma once

#include <iostream>
#include "../Player/player.hpp"

class Goalkeeper : public Player{
    public:
        Goalkeeper(std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national): Player(name, last_name, age, nationality, club, national, GK){};
        //~Player();

    private:

};

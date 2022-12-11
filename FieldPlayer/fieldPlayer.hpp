#pragma once

#include <iostream>
#include "../Player/player.hpp"

class FieldPlayer : public Player{
    public:
        FieldPlayer(std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national, poste_t position): Player(name, last_name, age, nationality, club, national){};
        //~Player();

        poste_t get_position(){ return _position;}

    private:
        poste_t _position = ST;

};

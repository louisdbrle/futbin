#include "player.hpp"

Player::Player() 
    : People(), _club("Club"), _national("National"), _position(LW)
{
}

Player::Player(std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national, poste_t position)
    : People(name, last_name, age, nationality), _club(club), _national(national), _position(position)
{
}

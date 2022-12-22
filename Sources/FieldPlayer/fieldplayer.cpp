#include "fieldplayer.hpp"

FieldPlayer::FieldPlayer()
    : Player()
{
    _stats->at(RATING) = 255;
 
    _stats->at(PACE) = 255;
    _stats->at(SHOOTING) = 255;
    _stats->at(PASSING) = 255;
 
    _stats->at(DRIBBLING) = 255;
    _stats->at(DEFENDING) = 255;
    _stats->at(PHYSICALITY) = 255;

}

// TODO : might need to had a pointer to a array containing the stats.

// Do we give a pointer to a array, or a map ? 
FieldPlayer::FieldPlayer(std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national, poste_t position)
    : Player(name, last_name, age, nationality, club, national, position)
{
    // Default value for now, until implementation of the pointer
    _stats->at(RATING) = 255;
 
    _stats->at(PACE) = 255;
    _stats->at(SHOOTING) = 255;
    _stats->at(PASSING) = 255;
 
    _stats->at(DRIBBLING) = 255;
    _stats->at(DEFENDING) = 255;
    _stats->at(PHYSICALITY) = 255;
}
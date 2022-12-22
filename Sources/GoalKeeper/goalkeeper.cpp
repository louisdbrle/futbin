#include "goalkeeper.hpp"

Goalkeeper::Goalkeeper()
    : Player()
{
    _stats->at(RATING) = 255;
 
    _stats->at(DIVING) = 255;
    _stats->at(HANDLING) = 255;
    _stats->at(KICKING) = 255;
 
    _stats->at(REFLEXES) = 255;
    _stats->at(SPEED) = 255;
    _stats->at(POSITIONING) = 255;

}

// TODO : might need to had a pointer to a array containing the stats.
Goalkeeper::Goalkeeper(std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national) 
    : Player(name, last_name, age, nationality, club, national, GK)
{
    // Default value for now, until implementation of the pointer
    _stats->at(RATING) = 255;
 
    _stats->at(DIVING) = 255;
    _stats->at(HANDLING) = 255;
    _stats->at(KICKING) = 255;
 
    _stats->at(REFLEXES) = 255;
    _stats->at(SPEED) = 255;
    _stats->at(POSITIONING) = 255;
}
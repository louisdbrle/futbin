#include "team.hpp"

Team::Team()
{
    _vect_player.resize(11);
    _vect_historic_match.resize(10);
}

Team::Team(std::vector<Player> vect_player, Coach &coach)
{
    coach = coach;

    if ( vect_player.size() > 11)
    {
        _vect_player = vect_player;
    }
    else
    {
        _vect_player.resize(11);
    }
    
    _vect_historic_match.resize(10);
}
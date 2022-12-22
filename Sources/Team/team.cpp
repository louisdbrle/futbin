#include "team.hpp"

Team::Team()
{
    _vect_player.reserve(24);
    _vect_historic_match.reserve(10);
    _ptr_coach = NULL;
}

Team::Team(Team& team) 
    : _vect_player(team._vect_player), _vect_historic_match(team._vect_historic_match), _ptr_coach(team._ptr_coach)
{
}

Team::Team(Coach& coach)
{
    _vect_player.reserve(24);
    _vect_historic_match.reserve(10);
    _ptr_coach = &coach;
}
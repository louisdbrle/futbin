#pragma once

class Team;
class Player;
class Coach;
class Game;


#include <iostream>
#include "../Team/team.hpp"
#include "../Player/player.hpp"
#include "../Coach/coach.hpp"
#include "../Match/match.hpp"
#include "../Game/game.hpp"


class User {
public:
    User();
    //~User();

    std::vector <Team*>  get_vect_team() { return _vect_team; }
    std::vector <Player*> get_vect_player() { return _vect_player; }
    std::vector <Coach*> get_vect_coach() { return _vect_coach; }
    std::vector <Game*> get_vect_historic_game() { return _vect_historic_game; }
    std::string get_name() { return _name; }

    void print_user();
    void print_collection();

private:
    std::vector <Team*> _vect_team;
    std::vector <Player*> _vect_player;
    std::vector <Coach*> _vect_coach;
    std::vector <Game*> _vect_historic_game;
    std::string _name;
};

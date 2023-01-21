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
    User(uint64_t id, std::string name, Team* team1, Team* team2, Team* team3, std::vector <Player*> vect_player, std::vector <Coach*> vect_coach);
    User(std::string name);
    //~User();

    std::vector <Team*>  get_vect_team() { return _vect_team; }
    std::vector <Player*> get_vect_player() { return _vect_player; }
    std::vector <Coach*> get_vect_coach() { return _vect_coach; }
    std::string get_name() { return _name; }

    void print_user();
    void print_collection();

private:
    uint64_t _id;
    std::string _name;
    std::vector <Team*> _vect_team;
    std::vector <Player*> _vect_player;
    std::vector <Coach*> _vect_coach;
};


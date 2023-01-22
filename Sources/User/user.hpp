#pragma once

class Team;
class Player;
class Coach;
class Game;

#include <iostream>

#include "../Card/card.hpp"
#include "../Game/game.hpp"
#include "../Player/player.hpp"
#include "../Team/team.hpp"

class User {
   public:
    User();
    User(uint64_t id, std::string name, Team* team1, Team* team2, Team* team3,
         std::vector<Player*> vect_player, std::vector<Card*> vect_cards);
    User(std::string name);
    //~User();

    std::vector<Team*> get_vect_team() { return _vect_team; }

    std::vector<Player*> get_vect_player() { return _players; }

    std::vector<Card*> get_vect_cards() { return _cards; }

    std::string get_name() { return _name; }

    void print_user();
    void print_collection();

   private:
    uint64_t _id;
    std::string _name;
    std::vector<Team*> _vect_team;
    std::vector<Card*> _cards;

    std::vector<Player*> _players;
};

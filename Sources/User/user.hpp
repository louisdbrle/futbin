#pragma once

class Team;
class Player;
class Coach;
class Game;

#include <iostream>

#include "../Card/card.hpp"
#include "../Player/player.hpp"
#include "../Team/team.hpp"

class User {
   public:
    User();
    User(uint64_t id, std::string name, Team* team,
         std::vector<Player*> vect_player, std::vector<Card*> vect_cards);
    User(std::string name);
    //~User();

    Team* get_team() { return _team; }

    std::vector<Player*> get_vect_player() { return _players; }

    std::vector<Card*> get_vect_cards() { return _cards; }

    std::string get_name() { return _name; }

    void print_user();
    void print_collection();

    void add_player(Player* player);
    void remove_player(Player* player);

    void add_card(Card* card);
    void remove_card(Card* card);

   private:
    uint64_t _id;
    std::string _name;
    Team* _team;
    std::vector<Card*> _cards;
    std::vector<Player*> _players;
};

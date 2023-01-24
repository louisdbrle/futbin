#pragma once

class Player;

#include <iostream>
#include <vector>

#include "../Card/card.hpp"
#include "../Player/player.hpp"

class Team {
public:
    Team();
    Team(std::vector<Player*>& vect_player, std::vector<Card*>& vect_card);
    //~Team();

    std::vector<Player*> get_vect_player() { return _vect_player; }
    std::vector<Card*> get_vect_card() { return _vect_card; }

    void print_team();
    void add_to_team(Player* player);
    void remove_from_team(Player* player);

    void add_card(Card* card, int index);
    void remove_card(Card* card);
    std::ostream& operator<<(std::ostream& out);



private:
    std::vector<Player*> _vect_player;
    std::vector<Card*> _vect_card;
};

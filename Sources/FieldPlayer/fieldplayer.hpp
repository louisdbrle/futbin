#pragma once

#include <iostream>
#include <map>
#include "../Player/player.hpp"

typedef enum stat_FP_t {
    RATING_FP, PACE, SHOOTING, PASSING, DRIBBLING, DEFENDING, PHYSICALITY
}stat_FP_t;

class FieldPlayer: public Player {
public:
    FieldPlayer();

    // TODO : might need to had a pointer to a array containing the stats.
    FieldPlayer(uint64_t id, std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national, std::string position);
    //~FieldPlayer();

    std::map<stat_FP_t, char>* get_stats() { return _stats; }

private:

    std::map<stat_FP_t, char> _stats[7];
};

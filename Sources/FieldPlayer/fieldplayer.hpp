#pragma once

#include <iostream>
#include <map>

#include "../Player/player.hpp"

class FieldPlayer: public Player {
public:
    FieldPlayer();

    FieldPlayer(uint64_t id, std::string name, std::string common_name,
        std::string nation, std::string position, int general, int pace,
        int shooting, int passing, int dribbling, int defending,
        int physical);
    //~FieldPlayer();

    std::map<std::string, int>* get_stats() { return _stats; }

private:
    std::map<std::string, int> _stats[7];
};

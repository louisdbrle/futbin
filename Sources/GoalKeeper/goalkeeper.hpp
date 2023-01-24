#pragma once

#include <iostream>
#include <map>

#include "../Player/player.hpp"

class Goalkeeper: public Player {
public:
    Goalkeeper();

    // TODO : might need to had a pointer to a array containing the stats.
    Goalkeeper(uint64_t id, std::string name, std::string common_name,
        std::string nation, int general, int diving, int handling,
        int kicking, int reflexes, int speed, int positioning);
    //~Goalkeeper();

    std::map<std::string, int>* get_stats() { return _stats; }

private:
    std::map<std::string, int> _stats[7];
};

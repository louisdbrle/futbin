#pragma once

#include <iostream>
#include <map>
#include "../Player/player.hpp"

// Not sure about hte physicality though ...
typedef enum stat_GK_t {
    RATING, DIVING, HANDLING, KICKING, REFLEXES, SPEED, POSITIONING
}stat_GK_t;

class Goalkeeper : public Player{
    public:
        Goalkeeper();

        // TODO : might need to had a pointer to a array containing the stats.
        Goalkeeper(std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national);  
        //~Goalkeeper();

        std::map<stat_GK_t,char>* get_stats(){ return _stats;}
    private:
    
        std::map<stat_GK_t,char> _stats[7];

};

#pragma once

#include <iostream>
#include <map>
#include "../Player/player.hpp"

typedef enum stat_GK_t {
    RATING, DIVING, HANDLING, KICKING, REFLEXES, SPEED, POSITIONING, PHYSICALITY
}stat_GK_t;

class Goalkeeper : public Player{
    public:
        Goalkeeper(std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national): Player(name, last_name, age, nationality, club, national, GK){};
        //~Goalkeeper();

        std::map<stat_GK_t,int>* get_stats(){ return _stats;}
    private:
    
        std::map<stat_GK_t,int> _stats[7];

};

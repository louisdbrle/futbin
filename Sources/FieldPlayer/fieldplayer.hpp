#pragma once

#include <iostream>
#include <map>
#include "../Player/player.hpp"

typedef enum stat_FP_t {
    RATING, PACE, SHOOTING, PASSING, DRIBBLING, DEFENDING, PHYSICALITY
}stat_FP_t;

class FieldPlayer : public Player{
    public:
        FieldPlayer();
        FieldPlayer(std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national, poste_t position);
        //~FieldPlayer();

        std::map<stat_FP_t,int>* get_stats(){ return _stats;}

    private:
        
        std::map<stat_FP_t,int> _stats[7];
};

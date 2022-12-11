#pragma once

#include <iostream>
#include "../People/people.hpp"

typedef enum poste_t {
    GK, RB, RWB, LB, LWB, CB, CDM, CM, CAM, LM, LW, LF, RM, RW, RF, VF, ST
};

class Player : public People{
    public:
        Player(std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national): People(name, last_name, age, nationality), _club(club), _national(national){};
        //~Player();

        std::string get_club(){ return _club;}
        std::string get_national(){ return _national;}

    private:
        std::string _club = "Club";
        std::string _national = "National";
};

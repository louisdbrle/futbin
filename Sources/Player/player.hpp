#pragma once

#include <iostream>
#include "../People/people.hpp"

typedef enum poste_t {
    GK,
    RB,
    RWB,
    LB,
    LWB,
    CB,
    CDM,
    CM,
    CAM,
    LM,
    LW,
    LF,
    RM,
    RW,
    RF,
    VF,
    ST
} poste_t;

class Player: public People {
public:
    Player();
    Player(uint64_t id, std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national, std::string position);
    //~Player();

    std::string get_club() { return _club; }
    std::string get_national() { return _national; }
    poste_t get_position() { return _position; }

    void print_player();

private:
    std::string _club;
    std::string _national;
    poste_t _position;
};

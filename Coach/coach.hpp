#pragma once

#include <iostream>
#include "../People/people.hpp"

class Coach : public People{
    public:
        Coach(std::string name, std::string last_name, u_short age, std::string nationality, std::string team): People(name, last_name, age, nationality), _team(team){};
        //~Coach();

        std::string get_team(){ return _team;}

    private:
        std::string _team = "Team";
};

#include "coach.hpp"

Coach::Coach() 
    : People(), _team("Team")
{
}

Coach::Coach(std::string name, std::string last_name, u_short age, std::string nationality, std::string team)
    : People(name, last_name, age, nationality), _team(team) 
{
}
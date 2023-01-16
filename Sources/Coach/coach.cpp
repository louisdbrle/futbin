#include "coach.hpp"

Coach::Coach() 
    : People(), _team("Team")
{
}

Coach::Coach(std::string name, std::string last_name, u_short age, std::string nationality, std::string team)
    : People(name, last_name, age, nationality), _team(team) 
{
}

void Coach::print_coach() {
    std::cout << "TODO : Not implemented yet < print_coach(), coach.cpp >"  << std::endl;
}

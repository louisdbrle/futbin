#include "coach.hpp"

Coach::Coach()
    : People(), _team("Team") {
}

Coach::Coach(std::string name, std::string last_name, u_short age, std::string nationality, std::string team)
    : People(name, last_name, age, nationality), _team(team) {
}

void Coach::print_coach() {
    std::cout << "Coach : name = " << _name << ", last name = " << _last_name;
    std::cout << ", age = " << _age << ", nationality = " << _nationality << ", team = " << _team << std::endl;
}

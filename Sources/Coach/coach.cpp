#include "coach.hpp"

Coach::Coach()
    : People(), _team("Team") {
}

Coach::Coach(uint64_t id, std::string name, std::string last_name, u_short age, std::string nationality, std::string team)
    : People(id, name, last_name, age, nationality), _team(team) {
}

void Coach::print_coach() {
    std::cout << "Coach : id = " << _id <<", name = " << _name << ", last name = " << _last_name;
    std::cout << ", age = " << _age << ", nationality = " << _nationality << ", team = " << _team << std::endl;
}

#include "coach.hpp"

Coach::Coach()
    : People(), _team("Team") {
}

Coach::Coach(std::string name, std::string last_name, u_short age, std::string nationality, std::string team)
    : People(name, last_name, age, nationality), _team(team) {
}

void Coach::print_coach() {
    std::cout << "Coach : name = " << this->get_name() << ", last name = "<< this->get_last_name();
    std::cout << ", age = " << this->get_age() << ", nationality = "<< this->get_nationality() << ", team = " << this->get_team() << std::endl;
}

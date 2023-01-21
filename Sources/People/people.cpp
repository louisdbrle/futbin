#include "people.hpp"

People::People()
    : _name("Name"), _last_name("Last_Name"), _age(255), _nationality("Nationality") {
}

People::People(uint64_t id, std::string name, std::string last_name, u_short age, std::string nationality)
    : _id(id), _name(name), _last_name(last_name), _age(age), _nationality(nationality) {
}
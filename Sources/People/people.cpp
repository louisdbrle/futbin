#include "people.hpp"

People::People() : _name("Name"), _common_name("common_name") {}

People::People(uint64_t id, std::string name, std::string common_name)
    : _id(id), _name(name), _common_name(common_name) {}
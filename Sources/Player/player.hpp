#pragma once

#include <iostream>

#include "../People/people.hpp"

class Player: public People {
public:
       Player();
       Player(uint64_t id, std::string name, std::string common_name,
              std::string nation, std::string position);

       std::string get_nation() { return _nation; }
       std::string get_position() { return _position; }

       void print_player();
       std::ostream& operator<<(std::ostream& out);

protected:
       std::string _nation;
       std::string _position;
};

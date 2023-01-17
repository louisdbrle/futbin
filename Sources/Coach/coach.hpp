#pragma once

#include <iostream>
#include "../People/people.hpp"

class Coach: public People {
public:
	Coach();
	Coach(std::string name, std::string last_name, u_short age, std::string nationality, std::string team);
	//~Coach();

	std::string get_team() { return _team; }

	void print_coach();

private:
	std::string _team;
};

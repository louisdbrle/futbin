#pragma once

#include <iostream>

class People {
public:
    People();
    People(std::string name, std::string last_name, u_short age, std::string nationality);
    //~People();

    std::string get_name() { return _name; }
    std::string get_last_name() { return _last_name; }
    u_short get_age() { return _age; }
    std::string get_nationality() { return _nationality; }

protected:
    std::string _name;
    std::string _last_name;
    u_short _age;
    std::string _nationality;
};

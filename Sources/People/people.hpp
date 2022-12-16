#pragma once

#include <iostream>

class People{
    public:
        People(std::string name, std::string last_name, u_short age, std::string nationality): _name(name), _last_name(last_name), _age(age), _nationality(nationality){};
        //~People();

        std::string get_name(){ return _name;}
        std::string get_last_name(){ return _last_name;}
        u_short get_age(){ return _age;}
        std::string get_nationality(){ return _nationality;}

    private:
        std::string _name = "Name";
        std::string _last_name = "Last_Name";
        u_short _age = 255;
        std::string _nationality = "Nationality";

};

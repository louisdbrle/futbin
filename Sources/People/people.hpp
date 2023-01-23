#pragma once

#include <iostream>

class People {
   public:
    People();
    People(uint64_t _id, std::string name, std::string common_name);
    //~People();

    uint64_t get_id() { return _id; }
    std::string get_name() { return _name; }
    std::string get_last_name() { return _common_name; }

   protected:
    uint64_t _id;
    std::string _name;
    std::string _common_name;
};

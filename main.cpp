#include <iostream>

#include "Sources/Team/team.hpp"

int main(int argc, char** argv){
    std::cout << " Start of the programme" << "\n\n" ;

    Coach coach;
    Team test(coach);
    std::cout << test.get_coach()->get_team() << "\n\n" ;

    std::cout << " End of the programme" << "\n\n" ;
    return 0;
}
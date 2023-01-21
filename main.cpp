#include <iostream>

#include "Sources/Application/app.hpp"

#define TEST true

// ---Main function--- //
int main(int argc, char** argv) {

    // srand(time(NULL));

    if (TEST) {
        std::cout << " --- START of the programme running in test mode --- \n\n\n" << std::endl;

        // ---Application variable--- //
        Application app = Application();

        //User user_1 = User();                                                                                                 
        //User user_2 = User();                                                                                                                                                                                    
        //app.db_users.push_back(user_1);                                                                                       
        //app.db_users.push_back(user_2);                                                                                       

        // ---User selection usage--- //
        //app.select_user(0);
        //std::cout << app.current_user->get_name() << "\n" << std::endl;

        // ---Db printing--- //
        //app.print_db_players();
        //app.print_db_coachs();
        app.print_db_users(); 

        // ---Add of player in the team 0 of the current_user--- //
        //app.current_user->get_vect_team()[0]->add_to_team(&goal);
        
        // ---Printing of team 0's current_user for debugging--- //
        //app.current_user->get_vect_team()[0]->print_team();

        std::cout << " --- END of the programme running in test mode --- \n\n\n" << std::endl;
    }
    else{
        std::cout << " --- START of the programme running in release mode --- \n\n\n" << std::endl;

        // ---Application variable--- //
        Application app = Application();

        std::cout << " --- END of the programme running in release mode --- \n\n\n" << std::endl;
    }

    return 0;
}

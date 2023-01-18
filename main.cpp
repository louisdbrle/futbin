#include <iostream>

#include "Sources/Application/app.hpp"

#define TEST true

// ---Main function--- //
int main(int argc, char** argv) {

    // srand(time(NULL));

    if (TEST) {
        std::cout << " START of the programme running in test mode \n\n\n" << std::endl;

        // ---Application variable--- //
        Application app = Application();

        // ---Object creation for testing purpuses--- //                                                                    // This whole code is not supposed to happen this way.
        Goalkeeper goal = Goalkeeper("GOALKEEPER", "_", 255, "FRENCH", "FC JUSSIEU", "FRANCE");                             // The Application app = Application () issupposed to do this job.
        FieldPlayer fieldplayer = FieldPlayer("FIELDPLAYER", "_", 255, "FRENCH", "FC JUSSIEU", "FRANCE", ST);               //  
        Coach coach = Coach("COACH", "_", 255, "FRENCH", "FRANCE");                                                         // 
        User user_1 = User();                                                                                               //
        User user_2 = User();                                                                                               //
                                                                                                                            //
        // ---Application variable update--- //                                                                             //
        app.db_players.push_back(goal);                                                                                     //
        app.db_players.push_back(fieldplayer);                                                                              //
        app.db_coachs.push_back(coach);                                                                                     //
        app.db_users.push_back(user_1);                                                                                     //
        app.db_users.push_back(user_2);                                                                                     //

        // ---User selection usage--- //
        app.select_user(0);
        std::cout << app.current_user->get_name() << "\n" << std::endl;

        // ---Db printing--- //
        app.print_db_players();
        app.print_db_coachs();
        app.print_db_users();

        // ---Add of player in the team 0 of the current_user--- //
        app.current_user->get_vect_team()[0]->add_to_team(&goal);
        
        // ---Printing of team 0's current_user for debugging--- //
        app.current_user->get_vect_team()[0]->print_team();

        std::cout << " END of the programme running in test mode \n\n\n" << std::endl;
    }
    else{
        std::cout << " START of the programme running in release mode \n\n\n" << std::endl;

        // ---Application variable--- //
        Application app = Application();

        std::cout << " END of the programme running in release mode \n\n\n" << std::endl;
    }

    return 0;
}

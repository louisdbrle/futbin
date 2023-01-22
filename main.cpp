#include <fstream>
#include <iostream>

#include "Sources/Application/app.hpp"
#include "Sources/FieldPlayer/fieldplayer.hpp"
#include "Sources/GoalKeeper/goalkeeper.hpp"
#include "Sources/Team/team.hpp"
#include "Sources/User/user.hpp"

#define TEST true

int main(int argc, char** argv) {
    // srand(time(NULL));

    if (TEST) {
        // ---Application variable--- //
        Application app = Application();

        // ---User selection usage--- //
        // app.select_user(0);
        // std::cout << app.current_user->get_name() << "\n" << std::endl;

        // ---Db printing--- //
        app.print_db_players();
        app.print_db_users();  //

        // app.run();
        // ---Add of player in the team 0 of the current_user--- //
        // app.current_user->get_vect_team()[0]->add_to_team(&goal);

        // ---Printing of team 0's current_user for debugging--- //
        // app.current_user->get_vect_team()[0]->print_team();

        std::cout << " --- END of the programme running in test mode --- \n\n\n"
                  << std::endl;
    } else {
        std::cout
            << " --- START of the programme running in release mode --- \n\n\n"
            << std::endl;

        // ---Application variable--- //
        Application app = Application();

        std::cout
            << " --- END of the programme running in release mode --- \n\n\n"
            << std::endl;
    }

    return 0;
}

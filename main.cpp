#include <iostream>

#include "Sources/Team/team.hpp"
#include "Sources/GoalKeeper/goalkeeper.hpp"
#include "Sources/FieldPlayer/fieldplayer.hpp"

void load_db_players(std::vector<Player>* vect_db_player){
    // read in json a player, create new players, add in at the end of the vect_db_player
}

void load_db_users(std::vector<User>* vect_db_users){
    // read in json a user, create new user, add in at the end of the vect_db_user
}


int main(int argc, char** argv){

    std::vector<Player> Db_players;
    load_db_players(&Db_players);

    std::vector<User> Db_users;
    load_db_users(&Db_users);

    User user_1 = User();
    User user_2 = User();
    Db_users.push_back(user_1);
    Db_users.push_back(user_2);

    Goalkeeper goal = Goalkeeper("GOALKEEPER", "_", u_short(255), "FRENCH", "FC JUSSIEU", "FRANCE");
    FieldPlayer fieldplayer = FieldPlayer("GOALKEEPER", "_", u_short(255), "FRENCH", "FC JUSSIEU", "FRANCE", ST);

    std::cout << goal.get_age() << std::endl;
    
    return 0;
}

/*
    - draw_cards()
    - select_user()

    - get_users()
    - get_team()
    - get_collection()


    - print_users()
    - print_team()
    - print_collection()
    - print_player()
    - print_coach()


    - add_to_team()
    - remove_from_team()
*/

#include <iostream>

#include "Sources/Team/team.hpp"
#include "Sources/GoalKeeper/goalkeeper.hpp"
#include "Sources/FieldPlayer/fieldplayer.hpp"

// Db loading function segment
std::vector<Player> load_db_players()
{
    // read in json a player, create new players, add in at the end of the vect_db_player
    std::vector<Player> vect;
    vect.reserve(6);

    std::cerr << "TODO : Not implemented yet < load_db_players , main.cpp >" << std::endl;

    return vect;
}

std::vector<User> load_db_users()
{
    // read in json a user, create new user, add in at the end of the vect_db_user
    std::vector<User> vect;
    vect.reserve(6);

    std::cerr << "TODO : Not implemented yet < load_db_users , main.cpp >" << std::endl;

    return vect;
}

// Draw cards function segment
Player *get_rand_player()
{
    std::cerr << "TODO : Not implemented yet < get_rand_player , main.cpp >" << std::endl;
    return NULL;
}

std::vector<Player *> draw_player_card()
{

    std::vector<Player *> vect;
    vect.reserve(6);

    for (u_int32_t i = 0; i < vect.size(); i++)
    {
        vect.push_back(get_rand_player());
    }
    return vect;
}

Coach *get_rand_coach()
{
    std::cerr << "TODO : Not implemented yet < get_rand_coach , main.cpp >" << std::endl;
    return NULL;
}

std::vector<Coach *> draw_coach_card()
{

    std::vector<Coach *> vect;
    vect.reserve(3);

    for (u_int32_t i = 0; i < vect.size(); i++)
    {
        vect.push_back(get_rand_coach());
    }
    return vect;
}

// Debug printing function
void print_users(std::vector<User> *db_users)
{
    for (std::vector<User>::size_type i = 0; i < db_users->size(); i++)
    {
        std::cout << "Le nom du coach " << i << " est : " << (*db_users)[i].get_name() << "\n";
    }
    std::cout << std::endl;
}

// Main function
int main(int argc, char **argv)
{

    std::vector<Player> Db_players = load_db_players();
    std::vector<User> Db_users = load_db_users();
    User *current_user;

    Goalkeeper goal = Goalkeeper("GOALKEEPER", "_", u_short(255), "FRENCH", "FC JUSSIEU", "FRANCE");
    FieldPlayer fieldplayer = FieldPlayer("FIELDPLAYER", "_", u_short(255), "FRENCH", "FC JUSSIEU", "FRANCE", ST);
    std::cout << goal.get_national() << std::endl;

    Db_players.push_back(goal);
    Db_players.push_back(fieldplayer);

    User user_1 = User();
    User user_2 = User();

    Db_users.push_back(user_1);
    Db_users.push_back(user_2);

    current_user = &Db_users[0];
    std::cout << current_user->get_name() << std::endl;

    print_users(&Db_users);
    return 0;
}

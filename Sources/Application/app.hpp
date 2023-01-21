#pragma once

#include "../Team/team.hpp"
#include "../GoalKeeper/goalkeeper.hpp"
#include "../FieldPlayer/fieldplayer.hpp"

class Application {
public:
    Application();
    ~Application();

    std::vector<Player> db_players;
    std::vector<Coach> db_coachs;
    std::vector<User> db_users;
    User* current_user;

    // ---Function around App variable --- //
    void load_db_players();
    void load_db_coachs();
    void load_db_users();
    void select_user(uint64_t user_id);

    // ---Draw cards function segment--- //
    Player* get_rand_player();
    std::vector<Player*> draw_player_card();
    std::vector<Player*> draw_player_card(uint8_t nb_card);

    Coach* get_rand_coach();
    std::vector<Coach*> draw_coach_card();
    std::vector<Coach*> draw_coach_card(uint8_t nb_card);

    void print_db_players();
    void print_db_coachs();
    void print_db_users();
};

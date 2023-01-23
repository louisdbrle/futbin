#pragma once

#include "../Card/card.hpp"
#include "../FieldPlayer/fieldplayer.hpp"
#include "../GoalKeeper/goalkeeper.hpp"
#include "../Team/team.hpp"
#include "../User/user.hpp"

class Application {
   public:
    Application();
    ~Application();

    std::vector<Player> db_players;
    std::vector<User> db_users;
    std::vector<Card> db_cards;
    User* current_user;

    // ---Function around App variable --- //
    void load_db_players();
    void load_db_users();
    void load_db_cards();
    void select_user(uint64_t user_id);

    Player* get_player_by_id(uint64_t id);
    Player* get_rand_player();

    void print_db_players();
    void print_db_users();

    void draw_cards_collection();

    void run();

   private:
    SDL_Renderer* _renderer;
    SDL_Window* _window;
    SDL_Event _event;
};

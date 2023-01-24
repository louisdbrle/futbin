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

    Card* get_card_by_id(uint64_t id);

    void print_db_players();
    void print_db_users();

    void draw_cards_collection(uint32_t page);
    void draw_team();

    void draw_blank_card();

    void draw_pack_button();

    void swap_card(int index_team, int index_collection);

    Card* open_pack();

    void draw_button(int x, int y, int w, int h, std::string text);

    void run();

    SDL_Renderer* get_renderer() { return _renderer; }
    SDL_Window* get_window() { return _window; }

   private:
    SDL_Renderer* _renderer;
    SDL_Window* _window;
    SDL_Event _event;
    TTF_Font* _font;
};

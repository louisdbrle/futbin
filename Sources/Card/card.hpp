#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "../Player/player.hpp"

class Card {
   public:
    Card(Player* player);
    void draw(SDL_Renderer* renderer, int x, int y, int w, int h);
    Player* get_player() { return _player; }
    uint64_t get_id() { return _id; }

   private:
    Player* _player;
    std::string _path;
    uint64_t _id;
};
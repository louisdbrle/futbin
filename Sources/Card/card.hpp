#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "../Player/player.hpp"

class Card {
   public:
    Card(Player* player, SDL_Renderer* renderer);
    void draw(int* position);

   private:
    Player* player;
    SDL_Texture* card_texture;
    SDL_Texture* text_texture;
    SDL_Renderer* renderer;
};

Card::Card(Player* player, SDL_Renderer* renderer)
    : player(player), renderer(renderer) {
    std::string path = "../Assets/";
    path += player->get_id();
    path += "_card.png";
    SDL_Surface* card = IMG_Load(path.c_str());
    card_texture = SDL_CreateTextureFromSurface(renderer, card);
    SDL_FreeSurface(card);
}

void Card::draw(int* position) {
    SDL_Rect rect_card = {position[0], position[1], position[2], position[3]};
    SDL_RenderCopy(renderer, card_texture, NULL, &rect_card);
}
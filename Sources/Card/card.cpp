#include "card.hpp"

Card::Card(Player* player) : _player(player) {
    _path = "Sources/Assets/";
    _path += std::to_string(player->get_id());
    _id = player->get_id();
    _path += "_card.png";
}

void Card::draw(SDL_Renderer* renderer, int x, int y, int w, int h) {
    SDL_Surface* card = IMG_Load(_path.c_str());
    SDL_Texture* card_texture = SDL_CreateTextureFromSurface(renderer, card);
    SDL_Rect rect_card = {x, y, w, h};
    SDL_RenderCopy(renderer, card_texture, NULL, &rect_card);
    SDL_FreeSurface(card);
    SDL_DestroyTexture(card_texture);
}
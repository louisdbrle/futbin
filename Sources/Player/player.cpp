#include "player.hpp"

Player::Player() : People(), _nation("Nation"), _position("LW") {}

Player::Player(uint64_t id, std::string name, std::string common_name,
               std::string nation, std::string position)
    : People(id, name, common_name), _nation(nation), _position(position) {}

void Player::print_player() {
    std::cout << "Player : id = " << _id << ", name = " << _name
              << ", Common Name = " << _common_name << ", nation = " << _nation
              << ", position = " << _position << std::endl;
}

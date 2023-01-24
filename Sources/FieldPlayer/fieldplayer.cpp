#include "fieldplayer.hpp"

FieldPlayer::FieldPlayer(): Player() {
    _stats->insert(std::pair<std::string, int>("general", 0));
    _stats->insert(std::pair<std::string, int>("pace", 0));
    _stats->insert(std::pair<std::string, int>("shooting", 0));
    _stats->insert(std::pair<std::string, int>("passing", 0));
    _stats->insert(std::pair<std::string, int>("dribbling", 0));
    _stats->insert(std::pair<std::string, int>("defending", 0));
    _stats->insert(std::pair<std::string, int>("physical", 0));
}

FieldPlayer::FieldPlayer(uint64_t id, std::string name, std::string common_name,
    std::string nation, std::string position, int general,
    int pace, int shooting, int passing, int dribbling,
    int defending, int physical)
    : Player(id, name, common_name, nation, position) {
    _stats->insert(std::pair<std::string, int>("general", general));
    _stats->insert(std::pair<std::string, int>("pace", pace));
    _stats->insert(std::pair<std::string, int>("shooting", shooting));
    _stats->insert(std::pair<std::string, int>("passing", passing));
    _stats->insert(std::pair<std::string, int>("dribbling", dribbling));
    _stats->insert(std::pair<std::string, int>("defending", defending));
    _stats->insert(std::pair<std::string, int>("physical", physical));
}
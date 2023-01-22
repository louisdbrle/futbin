#include "fieldplayer.hpp"

FieldPlayer::FieldPlayer()
    : Player() {
    _stats->insert(std::pair<stat_FP_t, char>(RATING_FP, 255));

    _stats->insert(std::pair<stat_FP_t, char>(PACE, 255));
    _stats->insert(std::pair<stat_FP_t, char>(SHOOTING, 255));
    _stats->insert(std::pair<stat_FP_t, char>(PASSING, 255));

    _stats->insert(std::pair<stat_FP_t, char>(DRIBBLING, 255));
    _stats->insert(std::pair<stat_FP_t, char>(DEFENDING, 255));
    _stats->insert(std::pair<stat_FP_t, char>(PHYSICALITY, 255));
}

// TODO : might need to had a pointer to a array containing the stats.

// Do we give a pointer to a array, or a map ?
FieldPlayer::FieldPlayer(uint64_t id, std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national, std::string position)
    : Player(id, name, last_name, age, nationality, club, national, position) {
    // Default value for now, until implementation of the pointer
    _stats->insert(std::pair<stat_FP_t, char>(RATING_FP, 255));

    _stats->insert(std::pair<stat_FP_t, char>(PACE, 255));
    _stats->insert(std::pair<stat_FP_t, char>(SHOOTING, 255));
    _stats->insert(std::pair<stat_FP_t, char>(PASSING, 255));

    _stats->insert(std::pair<stat_FP_t, char>(DRIBBLING, 255));
    _stats->insert(std::pair<stat_FP_t, char>(DEFENDING, 255));
    _stats->insert(std::pair<stat_FP_t, char>(PHYSICALITY, 255));
}
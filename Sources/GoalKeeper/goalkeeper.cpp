#include "goalkeeper.hpp"

Goalkeeper::Goalkeeper() : Player() {
    _stats->insert(std::pair<std::string, int>("general", 0));
    _stats->insert(std::pair<std::string, int>("diving", 0));
    _stats->insert(std::pair<std::string, int>("handling", 0));
    _stats->insert(std::pair<std::string, int>("kicking", 0));
    _stats->insert(std::pair<std::string, int>("reflexes", 0));
    _stats->insert(std::pair<std::string, int>("speed", 0));
    _stats->insert(std::pair<std::string, int>("positioning", 0));
}

// TODO : might need to had a pointer to a array containing the stats.
Goalkeeper::Goalkeeper(uint64_t id, std::string name, std::string common_name,
                       std::string nation, int general, int diving,
                       int handling, int kicking, int reflexes, int speed,
                       int positioning)
    : Player(id, name, common_name, nation, "GK") {
    _stats->insert(std::pair<std::string, int>("general", general));
    _stats->insert(std::pair<std::string, int>("diving", diving));
    _stats->insert(std::pair<std::string, int>("handling", handling));
    _stats->insert(std::pair<std::string, int>("kicking", kicking));
    _stats->insert(std::pair<std::string, int>("reflexes", reflexes));
    _stats->insert(std::pair<std::string, int>("speed", speed));
    _stats->insert(std::pair<std::string, int>("positioning", positioning));
}

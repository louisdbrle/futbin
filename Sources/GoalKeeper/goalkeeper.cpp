#include "goalkeeper.hpp"

Goalkeeper::Goalkeeper()
    : Player()
{
    _stats->insert(std::pair<stat_GK_t,char>(RATING_GK,255));

    _stats->insert(std::pair<stat_GK_t,char>(DIVING,255));
    _stats->insert(std::pair<stat_GK_t,char>(HANDLING,255));
    _stats->insert(std::pair<stat_GK_t,char>(KICKING,255));

    _stats->insert(std::pair<stat_GK_t,char>(REFLEXES,255));
    _stats->insert(std::pair<stat_GK_t,char>(SPEED,255));
    _stats->insert(std::pair<stat_GK_t,char>(POSITIONING,255));
}

// TODO : might need to had a pointer to a array containing the stats.
Goalkeeper::Goalkeeper(std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national)
    : Player(name, last_name, age, nationality, club, national, GK)
{
    // Default value for now, until implementation of the pointer

    _stats->insert(std::pair<stat_GK_t,char>(RATING_GK,255));

    _stats->insert(std::pair<stat_GK_t,char>(DIVING,255));
    _stats->insert(std::pair<stat_GK_t,char>(HANDLING,255));
    _stats->insert(std::pair<stat_GK_t,char>(KICKING,255));

    _stats->insert(std::pair<stat_GK_t,char>(REFLEXES,255));
    _stats->insert(std::pair<stat_GK_t,char>(SPEED,255));
    _stats->insert(std::pair<stat_GK_t,char>(POSITIONING,255));
}
#include "match.hpp"

// TODO : add a fonction to compute the winning team.
Match::Match(Team* ptr_team_dom, Team* ptr_team_ext): _ptr_team_dom(ptr_team_dom), _ptr_team_ext(ptr_team_ext) {
    _ptr_team_win = ptr_team_dom;
}

Match::~Match() {
    delete[] _ptr_team_dom;
    delete[] _ptr_team_ext;
    delete[] _ptr_team_win;
}
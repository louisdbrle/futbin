#include "game.hpp"

// TODO : add a fonction to launch the match, and select the team to play the match
Game::Game(User* ptr_user_dom, User* ptr_user_ext) : _ptr_user_dom(ptr_user_dom), _ptr_user_ext(ptr_user_ext)
{
    _ptr_winner = _ptr_user_dom;
}

/* Methode to use the match class in order to designate a winner User  : 

play_game(int index_team_dom, int index_team_ext){

    Team* team_dom = _ptr_user_dom -> _vect_team.at(index_team_dom);
    Team* team_ext = _ptr_user_ext -> _vect_team.at(index_team_ext);

    Match match = new Match(team_dom, team_ext);

    if (team_dom ==  match.get_ptr_team_win() ) {
        _ptr_winner = _ptr_user_dom;
    }
    else { 
        _ptr_winner = _ptr_user_ext;
    }

}
    
*/


#include "player.hpp"

Player::Player()
    : People(), _club("Club"), _national("National"), _position(LW) {
}

Player::Player(uint64_t id, std::string name, std::string last_name, u_short age, std::string nationality, std::string club, std::string national, std::string position)
    : People(id, name, last_name, age, nationality), _club(club), _national(national) {
        
        if (position == "RB") {
            _position = RB;
        }
        else if (position == "RWB"){
            _position = RB;
        }
        else if (position == "LB"){
            _position = LB;
        }
        else if (position == "LWB"){
            _position = LWB;
        }
        else if (position == "CB"){
            _position = CB;
        }
        else if (position == "CDM"){
            _position = CDM;
        }
        else if (position == "CM"){
            _position = CM;
        }
        else if (position == "CAM"){
            _position = CAM;
        }
        else if (position == "LM"){
            _position = LM;
        }
        else if (position == "LW"){
            _position = LW;
        }
        else if (position == "LF"){
            _position = LF;
        }
        else if (position == "RM"){
            _position = RM;
        }
        else if (position == "RW"){
            _position = RW;
        }
        else if (position == "RF"){
            _position = RF;
        }
        else if (position == "VF"){
            _position = VF;
        }
        else if (position == "ST"){
            _position = ST;
        }
        else {
            _position = GK;
        }

}

void Player::print_player() {
    //std::cout << "TODO : Not implemented yet < print_player(), player.cpp >" << std::endl;
    std::cout << "Player : id = " << _id <<", name = " << _name << ", Last name = " << _last_name << ", age = " << _age << ", nationality = " << _nationality;
    std::cout << ", position = " << _position << ", club = " << _club << ", national team = " << _national << std::endl;
}

#include <iostream>
#include <fstream>

#include "app.hpp"


Application::Application() {
    this->load_db_players();
    this->load_db_coachs();
    this->load_db_users();
}

Application::~Application() {
    //delete [] current_user;
}


void Application::load_db_players() {

    std::ifstream file;
    file.open("db/clean_player_db.csv");

    if (!file) {
        std::cerr << "Can not open file \n" << std::endl;
        exit(1);
    }

    else {

        std::string delim = ",";
        std::string line;
        while (getline(file, line)) {

            std::vector<std::string> vect_string;
            for (uint8_t i = 0; i < 12; i++) {

                vect_string.push_back(line.substr(0, line.find(delim)));
                line.erase(0, line.find(delim) + delim.length());
            }

            if (vect_string[0] == "id") {

            }
            else if (vect_string[4] == "GK") {
                Goalkeeper new_player = Goalkeeper(std::stoi(vect_string[0]), vect_string[1], "-", 255, vect_string[2], "-", "-");
                db_players.push_back(new_player);
            }
            else {
                FieldPlayer new_player = FieldPlayer(std::stoi(vect_string[0]), vect_string[1], "-", 255, vect_string[2], "-", "-", vect_string[4]);
                db_players.push_back(new_player);
            }

            vect_string.clear();
        }
    }

    file.close();
}

void Application::load_db_users() {
    //std::cerr << "TODO : Not implemented yet < load_db_users , app.cpp >\n" << std::endl;
    //std::cerr << "---- Have to take sometime to think about that, as it is harder due to pointer usage --- \n" << std::endl;

    std::ifstream file;
    file.open("db/user_db.csv");

    if (!file) {
        std::cerr << "Can not open file \n" << std::endl;
        exit(1);
    }

    else {

        uint8_t cpt = 0;
        std::string delim = ",";
        std::string line;
        std::vector<std::vector<std::string>> vect_vect_string(10);

        uint64_t id;
        std::string name;
        std::vector<Player*> team1;
        std::vector<Player*> team2;
        std::vector<Player*> team3;
        std::vector<Player*> players;
        std::vector<Coach*> coachs;

        while (getline(file, line)) {

            for (uint8_t i = 0; i < 255; i++) {

                if (line.substr(0, line.find(delim)) == "id") {
                    vect_vect_string[cpt].push_back(line.substr(0, line.find(delim)));
                    line.erase(0, line.find(delim) + delim.length());
                }

                else if (line.substr(0, line.find(delim)) != "\\") {
                    vect_vect_string[cpt].push_back(line.substr(0, line.find(delim)));
                    line.erase(0, line.find(delim) + delim.length());
                }

                else {
                    cpt += 1;
                    line.erase(0, line.find(delim) + delim.length());
                    break;
                }


            }


            if (cpt == 7) {

                team1.clear();
                team2.clear();
                team3.clear();
                players.clear();
                coachs.clear();

                //std::cout << "CREATION OF THE USER RIGHT HERE\n\n";

                for (std::vector<std::vector<std::__cxx11::basic_string<char> > >::size_type i = 0; i < vect_vect_string.size(); i++) {

                    switch (i) {
                    case 0:
                        id = std::stoi(vect_vect_string[i].back());
                        //std::cout << "Id : " << id << "\n";
                        break;

                    case 1:
                        name = vect_vect_string[i].back();
                        //std::cout << "Name : " << name << "\n";
                        break;

                    case 2:
                        //std::cout << "Team1 : ";
                        for (std::vector<std::vector<std::__cxx11::basic_string<char> > >::size_type j = 1; j < vect_vect_string[i].size(); j++) {
                            // We should have used maps, so that we could have easily used ids to find anything.
                            team1.push_back(get_player_by_id(std::stoi(vect_vect_string[i][j])));
                            //std::cout << vect_vect_string[i][j] << " ";
                        }
                        //std::cout << "\n";
                        break;

                    case 3:
                        //std::cout << "Team2 : ";
                        for (std::vector<std::vector<std::__cxx11::basic_string<char> > >::size_type j = 1; j < vect_vect_string[i].size(); j++) {
                            // We should have used maps, so that we could have easily used ids to find anything.
                            team2.push_back(get_player_by_id(std::stoi(vect_vect_string[i][j])));
                            //std::cout << vect_vect_string[i][j] << " ";
                        }
                        //std::cout << "\n";
                        break;

                    case 4:
                        //std::cout << "Team3 : ";
                        for (std::vector<std::vector<std::__cxx11::basic_string<char> > >::size_type j = 1; j < vect_vect_string[i].size(); j++) {
                            // We should have used maps, so that we could have easily used ids to find anything.
                            team3.push_back(get_player_by_id(std::stoi(vect_vect_string[i][j])));
                            //std::cout << vect_vect_string[i][j] << " ";
                        }
                        //std::cout << "\n";
                        break;

                    case 5:
                        //std::cout << "Players : ";
                        for (std::vector<std::vector<std::__cxx11::basic_string<char> > >::size_type j = 1; j < vect_vect_string[i].size(); j++) {
                            // We should have used maps, so that we could have easily used ids to find anything.
                            players.push_back(get_player_by_id(std::stoi(vect_vect_string[i][j])));
                            //std::cout << vect_vect_string[i][j] << " ";
                        }
                        //std::cout << "\n";
                        break;

                    case 6:
                        //std::cout << "Coachs : ";
                        for (std::vector<std::vector<std::__cxx11::basic_string<char> > >::size_type j = 1; j < vect_vect_string[i].size(); j++) {
                            // We should have used maps, so that we could have easily used ids to find anything.
                            coachs.push_back(get_coach_by_id(std::stoi(vect_vect_string[i][j])));
                            //std::cout << vect_vect_string[i][j] << " ";
                        }
                        //std::cout << "\n";
                        break;
                    }

                    for (std::vector<std::vector<std::__cxx11::basic_string<char> > >::size_type j = vect_vect_string[i].size(); j > 0; j--) {
                        vect_vect_string[i].pop_back();
                    }


                }

                Team* new_team1 = new Team(team1);
                Team* new_team2 = new Team(team2);
                Team* new_team3 = new Team(team3);

                User new_user = User(id, name, new_team1, new_team2, new_team3, players, coachs);
                db_users.push_back(new_user);

                //std::cout << "\n";
                cpt = 0;
                //std::cout << "END OF THE USER\n\n";
            }
        }
    }

    file.close();
}

void Application::load_db_coachs() {

    std::ifstream file;
    file.open("db/clean_coach_db_sample.csv");

    if (!file) {
        std::cerr << "Can not open file \n" << std::endl;
        exit(1);
    }

    else {

        std::string delim = ",";
        std::string line;
        while (getline(file, line)) {

            std::vector<std::string> vect_string;
            for (uint8_t i = 0; i < 6; i++) {

                vect_string.push_back(line.substr(0, line.find(delim)));
                line.erase(0, line.find(delim) + delim.length());
            }

            if (vect_string[0] == "id") {

            }
            else {
                Coach new_coach = Coach(std::stoi(vect_string[0]), vect_string[1], vect_string[2], std::stoi(vect_string[3]), vect_string[4], vect_string[5]);
                db_coachs.push_back(new_coach);
            }
            vect_string.clear();
        }
    }

    file.close();

}

void Application::select_user(uint64_t user_id) {
    if (user_id > db_users.size()) {
        std::cerr << "ERROR : The user_id you are looking for is not attributed < select_user , app.cpp >\n" << std::endl;
    }
    else {
        current_user = &db_users[user_id];
    }

}

Player* Application::get_player_by_id(uint64_t id) {
    for (u_int32_t i = 0; i < db_players.size(); i++) {
        if (db_players[i].get_id() == id) {
            return &db_players[i];
        }
    }
    return NULL;
}

Player* Application::get_rand_player() {
    return &db_players.at(std::rand() % db_players.size());
}

std::vector<Player*> Application::draw_player_card() {

    std::vector<Player*> vect;
    vect.reserve(6);

    for (u_int32_t i = 0; i < vect.size(); i++) {
        vect.push_back(get_rand_player());
    }
    return vect;
}

std::vector<Player*> Application::draw_player_card(uint8_t nb_card) {

    std::vector<Player*> vect;
    vect.reserve(nb_card);

    for (u_int32_t i = 0; i < vect.size(); i++) {
        vect.push_back(get_rand_player());
    }
    return vect;
}


Coach* Application::get_coach_by_id(uint64_t id) {
    for (u_int32_t i = 0; i < db_coachs.size(); i++) {
        if (db_coachs[i].get_id() == id) {
            return &db_coachs[i];
        }
    }
    return NULL;
}

Coach* Application::get_rand_coach() {
    return &db_coachs.at(std::rand() % db_coachs.size());
}

std::vector<Coach*> Application::draw_coach_card() {

    std::vector<Coach*> vect;
    vect.reserve(3);

    for (u_int32_t i = 0; i < vect.size(); i++) {
        vect.push_back(get_rand_coach());
    }
    return vect;
}

std::vector<Coach*> Application::draw_coach_card(uint8_t nb_card) {

    std::vector<Coach*> vect;
    vect.reserve(nb_card);

    for (u_int32_t i = 0; i < vect.size(); i++) {
        vect.push_back(get_rand_coach());
    }
    return vect;
}


void Application::print_db_players() {
    for (std::vector<User>::size_type i = 0; i < db_players.size(); i++) {
        db_players[i].print_player();
    }
    std::cout << std::endl;
}

void Application::print_db_coachs() {
    for (std::vector<User>::size_type i = 0; i < db_coachs.size(); i++) {
        db_coachs[i].print_coach();
    }
    std::cout << std::endl;
}

void Application::print_db_users() {
    for (std::vector<User>::size_type i = 0; i < db_users.size(); i++) {
        db_users[i].print_user();
    }
    std::cout << std::endl;
}

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "../Sources/Application/app.hpp"

TEST_CASE("1 : Test Creation player") {
    Player player = Player(255, "Louis Dubarle", "Bombarde", "France", "GK");

    REQUIRE(player.get_id() == 255);
    REQUIRE(player.get_name() == "Louis Dubarle");
    REQUIRE(player.get_last_name() == "Bombarde");
    REQUIRE(player.get_nation() == "France");
    REQUIRE(player.get_position() == "GK");
}

TEST_CASE("2 : Test Creation Fieldplayer") {
    FieldPlayer fieldplayer = FieldPlayer(255, "Louis Dubarle", "Bombarde", "France", "ST", 85, 43, 23, 56, 35, 22, 42);

    REQUIRE(fieldplayer.get_id() == 255);
    REQUIRE(fieldplayer.get_name() == "Louis Dubarle");
    REQUIRE(fieldplayer.get_last_name() == "Bombarde");
    REQUIRE(fieldplayer.get_nation() == "France");
    REQUIRE(fieldplayer.get_position() == "ST");
    REQUIRE(fieldplayer.get_stats()->at("general") == 85);
    REQUIRE(fieldplayer.get_stats()->at("pace") == 43);
    REQUIRE(fieldplayer.get_stats()->at("shooting") == 23);
    REQUIRE(fieldplayer.get_stats()->at("passing") == 56);
    REQUIRE(fieldplayer.get_stats()->at("dribbling") == 35);
    REQUIRE(fieldplayer.get_stats()->at("defending") == 22);
    REQUIRE(fieldplayer.get_stats()->at("physical") == 42);
}

TEST_CASE("3 : Test Creation GoaldKeeper") {
    Goalkeeper goalkeeper = Goalkeeper(255, "Louis Dubarle", "Bombarde", "France", 85, 43, 23, 56, 35, 22, 42);

    REQUIRE(goalkeeper.get_id() == 255);
    REQUIRE(goalkeeper.get_name() == "Louis Dubarle");
    REQUIRE(goalkeeper.get_last_name() == "Bombarde");
    REQUIRE(goalkeeper.get_nation() == "France");
    REQUIRE(goalkeeper.get_position() == "GK");
    REQUIRE(goalkeeper.get_stats()->at("general") == 85);
    REQUIRE(goalkeeper.get_stats()->at("diving") == 43);
    REQUIRE(goalkeeper.get_stats()->at("handling") == 23);
    REQUIRE(goalkeeper.get_stats()->at("kicking") == 56);
    REQUIRE(goalkeeper.get_stats()->at("reflexes") == 35);
    REQUIRE(goalkeeper.get_stats()->at("speed") == 22);
    REQUIRE(goalkeeper.get_stats()->at("positioning") == 42);
}

TEST_CASE("4 : Team Manipulation") {
    
    Team team = Team();
    FieldPlayer fieldplayer = FieldPlayer(255, "Louis Dubarle", "Bombarde", "France", "LW", 85, 43, 23, 56, 35, 22, 42);
    Card card = Card(&fieldplayer);

    team.add_to_team(&fieldplayer);
    team.add_card(&card, 0);
    team.print_team();

    team.remove_from_team(&fieldplayer);
    team.remove_card(&card);
    team.print_team();
}

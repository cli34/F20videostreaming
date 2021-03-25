/*
  Stream_t.cpp

  Test program for class Stream
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Stream.hpp"

TEST_CASE( "TV show KN", "[Stream]" ) {
    constexpr auto episodes = 32;
    const auto KN = TVSHOW("Kitchen Nightmares", 1, 0, 50, episodes);
    const auto NOP = Stream(KN, 10);

    REQUIRE(NOP.viewings() == 10);

    REQUIRE(NOP.tvshow().episodes() == episodes);
    REQUIRE(NOP.tvshow().hours() == 0);
    REQUIRE(NOP.tvshow().Minutes() == 50);
    REQUIRE(NOP.tvshow().type() == 1);
    REQUIRE(NOP.tvshow().title() == "Kitchen Nightmares");
}

TEST_CASE("TV show GA", "[Stream]"){
    constexpr auto episodes = 100;
    const auto GA  = TVSHOW("Grey's Anatomy", 1, 0, 50, episodes);
    const auto NOP = Stream(GA, 10);

    REQUIRE(NOP.viewings() == 10);

    REQUIRE(NOP.tvshow().episodes() == episodes);
    REQUIRE(NOP.tvshow().hours() == 0);
    REQUIRE(NOP.tvshow().Minutes() == 50);
    REQUIRE(NOP.tvshow().type() == 1);
    REQUIRE(NOP.tvshow().title() == "Grey's Anatomy");
}

TEST_CASE("Movie DS", "[Stream]"){
    const auto DS  = MOVIE("Doctor Sleep", 0, 1, 32, 2);
    const auto NOP = Stream(DS, 2);

    REQUIRE(NOP.viewings() == 2);

    REQUIRE(NOP.movie().episodes() == 0);
    REQUIRE(NOP.movie().hours() == 1);
    REQUIRE(NOP.movie().Minutes() == 32);
    REQUIRE(NOP.movie().type() == 0);
    REQUIRE(NOP.movie().title() == "Doctor Sleep");
}

TEST_CASE("TV show BB", "[Stream]") {
    constexpr auto episodes = 20;
    auto BB = TVSHOW("Breaking Bad", 1, 0, 30, episodes);
    constexpr auto views = 1000;
    const auto NFLX = Stream(BB, views);

    REQUIRE(NFLX.viewings() == 1000);

    REQUIRE(NFLX.tvshow().episodes() == 20);
    REQUIRE(NFLX.tvshow().hours() == 0);
    REQUIRE(NFLX.tvshow().Minutes() == 30);
    REQUIRE(NFLX.tvshow().type() == 1);
    REQUIRE(NFLX.tvshow().title() == "Breaking Bad");
}

TEST_CASE("Movie Batman", "[Stream]") {
    auto BB = MOVIE("Batman", 0, 2, 30, 99);
    constexpr auto views = 1;
    const auto NFLX = Stream(BB, views);

    REQUIRE(NFLX.viewings() == 1);

    REQUIRE(NFLX.movie().episodes() == 0);
    REQUIRE(NFLX.movie().hours() == 2);
    REQUIRE(NFLX.movie().Minutes() == 30);
    REQUIRE(NFLX.movie().type() == 0);
    REQUIRE(NFLX.movie().title() == "Batman");
}

/*
  Video_t.cpp

  Test program for class Video
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Video.hpp"

TEST_CASE( "TV Show KN", "[Video]" ) {

    // MOVIE    = 0
    // TVSHOW   = 1
    // ORIGINAL = 2

    //Tests for adding TV Shows
    constexpr auto episodes = 91;
    const auto KN = TVSHOW("Kitchen Nightmares", 1, 0, 50, episodes);

    REQUIRE(KN.title() == "Kitchen Nightmares");
    REQUIRE(KN.type() == 1);
    REQUIRE(KN.hours() == 0);
    REQUIRE(KN.Minutes() == 50);
    REQUIRE(KN.episodes() == 91);
}

TEST_CASE( "TV Show HH", "[Video]" ) {

    // MOVIE    = 0
    // TVSHOW   = 1
    // ORIGINAL = 2

    //Tests for adding TV Shows
    constexpr auto episodes = 32;
    const auto HH = TVSHOW("Hotel Hell", 1, 0, 50, episodes);

    REQUIRE(HH.title() == "Hotel Hell");
    REQUIRE(HH.type() == 1);
    REQUIRE(HH.hours() == 0);
    REQUIRE(HH.Minutes() == 50);
    REQUIRE(HH.episodes() == 32);
}

TEST_CASE( "Movie SB", "[Video]" ) {

    // MOVIE    = 0
    // TVSHOW   = 1
    // ORIGINAL = 2

    //Tests for adding Movies
    const auto SB = MOVIE("Spongebob Squarepants The Movie", 0, 1, 27, 1);

    REQUIRE(SB.title() == "Spongebob Squarepants The Movie");
    REQUIRE(SB.type() == 0);
    REQUIRE(SB.hours() == 1);
    REQUIRE(SB.Minutes() == 27);
    //Test to make sure episodes was changed to 0
    // Don't need that anymore
}

TEST_CASE( "Movie SOW", "[Video]" ) {

    // MOVIE    = 0
    // TVSHOW   = 1
    // ORIGINAL = 2

    //Tests for adding Movies
    const auto SOW = MOVIE("Spongebob Squarepants: Sponge Out of Water", 0, 1, 32, 2);

    REQUIRE(SOW.title() == "Spongebob Squarepants: Sponge Out of Water");
    REQUIRE(SOW.type() == 0);
    REQUIRE(SOW.hours() == 1);
    REQUIRE(SOW.Minutes() == 32);
    //Test to make sure episodes was changed to 0
    //REQUIRE(SOW.episodes() == 0);
}

TEST_CASE( "Original C", "[Video]" ) {

    // MOVIE    = 0
    // TVSHOW   = 1
    // ORIGINAL = 2

    //Tests for adding Originals
    constexpr auto episodes = 30;
    const auto C = ORIGINAL("Castlevania", 2, 0, 30, episodes);

    REQUIRE(C.title() == "Castlevania");
    REQUIRE(C.type() == 2);
    REQUIRE(C.hours() == 0);
    REQUIRE(C.Minutes() == 30);
    REQUIRE(C.episodes() == 30);
}

TEST_CASE( "Original TK", "[Video]" ) {

    // MOVIE    = 0
    // TVSHOW   = 1
    // ORIGINAL = 2

    //Tests for adding Originals
    constexpr auto episodes = 8;
    const auto TK = ORIGINAL("Tiger King", 2, 0, 45, episodes);

    REQUIRE(TK.title() == "Tiger King");
    REQUIRE(TK.type() == 2);
    REQUIRE(TK.hours() == 0);
    REQUIRE(TK.Minutes() == 45);
    REQUIRE(TK.episodes() == 8);
}

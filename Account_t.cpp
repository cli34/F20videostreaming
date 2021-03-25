/*
  Account_t.cpp

  Test program for class Account
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Account.hpp"

#include <iostream>

TEST_CASE( "No streaming", "[Account]" )
{
  Account customer("Fred");

  REQUIRE(customer.name() == "Fred");
  REQUIRE(customer.data() == "");
}

// Test .addStream() method - single stream
TEST_CASE(".addStream() - single stream", "[Account]")
{
  int episodes = 10;
  const auto video = TVSHOW("Pawn Stars", 1, 0, 30, episodes);
  const auto stream = Stream(video, 25);
  auto customer = Account("Fred");

  // Add "Pawn Stars" as stream into the customer's account
  customer.addStream(stream);

  // Check .data()
  // name, type, title, hours, minutes, num of times
  REQUIRE(customer.data() == "Fred,TVSHOW,Pawn Stars,0,750,25\n");
}

// Test .addStream - many streams
TEST_CASE(".addStream() - multi stream", "[Account]")
{
  auto customer = Account("Gimli");

  const auto video1 = MOVIE("The Lord of the Rings: The Fellowship of the Ring", 0, 3, 18, 1);
  const auto stream1 = Stream(video1, 1);
  customer.addStream(stream1);

  // name, type, title, hours, minutes, num of times
  REQUIRE(customer.data() == "Gimli,MOVIE,The Lord of the Rings: The Fellowship of the Ring,3,18,3\n");

  const auto video2 = MOVIE("The Lord of the Rings: The Two Towers", 0, 3, 19, 1);
  const auto stream2 = Stream(video2, 1);
  customer.addStream(stream2);

  REQUIRE(customer.data() == "Gimli,MOVIE,The Lord of the Rings: The Fellowship of the Ring,3,18,3\nGimli,MOVIE,The Lord of the Rings: The Two Towers,3,19,3\n");

  const auto video3 = MOVIE("The Lord of the Rings: The Return of the King", 0, 3, 20, 1);
  const auto stream3 = Stream(video3, 1);
  customer.addStream(stream3);

  REQUIRE(customer.data() == "Gimli,MOVIE,The Lord of the Rings: The Fellowship of the Ring,3,18,3\nGimli,MOVIE,The Lord of the Rings: The Two Towers,3,19,3\nGimli,MOVIE,The Lord of the Rings: The Return of the King,3,20,3\n");
}

// Test report()
TEST_CASE("Testing report()", "[Account]")
{
  // Gimli's back
  auto customer = Account("Gimli");

  const auto video1 = MOVIE("The Lord of the Rings: The Fellowship of the Ring", 0, 3, 18, 1);
  const auto stream1 = Stream(video1, 1);
  customer.addStream(stream1);

  const auto video2 = MOVIE("The Lord of the Rings: The Two Towers", 0, 3, 19, 1);
  const auto stream2 = Stream(video2, 1);
  customer.addStream(stream2);

  const auto video3 = MOVIE("The Lord of the Rings: The Return of the King", 0, 3, 20, 1);
  const auto stream3 = Stream(video3, 1);
  customer.addStream(stream3);

  REQUIRE(customer.name() == "Gimli");

  REQUIRE(customer.report() == "Stream Report for Account: Gimli\nStreams:\n\tThe Lord of the Rings: The Fellowship of the Ring\t3\n\tThe Lord of the Rings: The Two Towers\t3\n\tThe Lord of the Rings: The Return of the King\t3\n\nTotal Stream Events: 9\nNon-Original Stream Events: 9\nTotal Time: 957\n");
}

// Test report(), even more so
TEST_CASE("Testing report() again", "[Account]")
{
  auto customer = Account("Gimli");

  const auto video1 = ORIGINAL("The Original Movie", 2, 2, 7, 1);
  const auto stream1 = Stream(video1, 1);
  customer.addStream(stream1);

  const auto video2 = TVSHOW("Friends", 1, 0, 26, 236);
  const auto stream2 = Stream(video2, 5);
  customer.addStream(stream2);

  const auto video3 = MOVIE("The Lord of the Rings: The Return of the King", 0, 3, 20, 1);
  const auto stream3 = Stream(video3, 1);
  customer.addStream(stream3);

  REQUIRE(customer.report() == "Stream Report for Account: Gimli\nStreams:\n\tThe Original Movie\t1\n\tFriends\t5\n\tThe Lord of the Rings: The Return of the King\t3\n\nTotal Stream Events: 9\nNon-Original Stream Events: 8\nTotal Time: 737\n");
}

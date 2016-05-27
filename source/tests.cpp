#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <math.h>
#include "List.hpp"
TEST_CASE("1","[one]")
{
List<int> liste {};

REQUIRE(liste.empty());
REQUIRE(liste.size() == 0);
}

TEST_CASE("2","[two]")
{
List<int> liste {};

liste.push_front (27);
REQUIRE(liste.front() == 27);

liste.pop_front();
REQUIRE(liste.empty());

liste.push_back(11);
liste.push_back(12);

REQUIRE(liste.front()==11);
REQUIRE(liste.back()==12);

liste.pop_back();
REQUIRE(liste.size()==1);
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

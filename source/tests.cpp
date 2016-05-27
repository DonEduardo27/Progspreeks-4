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

liste.push_front (45);
REQUIRE(liste.front() == 45);
liste.push_front (67);
REQUIRE(liste.front() == 67);
liste.push_front (2754);
REQUIRE(liste.front() == 2754);
liste.push_front (21);
REQUIRE(liste.front() == 21);
REQUIRE(liste.back()  == 27);
liste.push_back(11);
REQUIRE(liste.back()  == 11);
liste.push_back(12);
REQUIRE(liste.back()  == 12);
liste.push_back(13);
REQUIRE(liste.back()  == 13);
liste.push_back(14);
REQUIRE(liste.back()  == 14);
REQUIRE(liste.size()  == 9);

liste.pop_front();
liste.pop_back();
REQUIRE(liste.front()==2754);
REQUIRE(liste.back()==13);

liste.pop_back();
REQUIRE(liste.size()==6);
}

TEST_CASE("3","[three]")
{
List<int> liste {};

liste.push_front (1);
liste.push_back  (2);
liste.push_front (3);
liste.push_back  (4);

liste.clear();

REQUIRE(liste.empty());

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

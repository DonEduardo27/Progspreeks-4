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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

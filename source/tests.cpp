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
List<int> liste ;

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
//(21,2754,67,45,27,11,12,13,14)
liste.pop_front();
liste.pop_back();

//(2754,67,45,27,11,12,13)

//REQUIRE(liste.front()==2754);
//REQUIRE(liste.back()==13);

liste.pop_back();
REQUIRE(liste.size()==6);

liste.pop_back();
REQUIRE(liste.size()==5);

liste.pop_back();
REQUIRE(liste.size()==4);

liste.pop_back();
REQUIRE(liste.size()==3);

liste.pop_back();
REQUIRE(liste.size()==2);

liste.pop_back();
REQUIRE(liste.size()==1);

REQUIRE(liste.front() == liste.back());
liste.pop_back();
/*}

TEST_CASE("3","[three]")
{
List<int> liste;

liste.push_front (1);
liste.push_back  (2);
liste.push_front (3);
liste.push_back  (4);

liste.clear();

REQUIRE(liste.empty());

}

TEST_CASE("5","[five]")
{
List<int> liste;
auto b = liste.begin ();
auto e = liste.end ();
std::cout<<&b<<" "<<&e<<std::endl;
REQUIRE ( liste.begin () == liste.end () );
REQUIRE ( b == e );
}

TEST_CASE ( " provide acces to the first element with begin " , " [ iterators ] " )
{
/*List < int > list ;
list . push_back (42);
REQUIRE (42 == * list . end ());*/
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

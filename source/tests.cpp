#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <math.h>
#include "List.hpp"

template < typename T >
List<T> reverse(List<T> const& l) 
{
	List<T> n{l};
	n.reverse(); 
	return n;
}

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

REQUIRE(liste.front()==2754);
REQUIRE(liste.back()==13);

liste.pop_back();
REQUIRE(liste.size()==6);
liste.pop_front();
REQUIRE(liste.size()==5);
//(67,45,27,11,12)

REQUIRE(liste.front()==67);
REQUIRE(liste.back()==12);

liste.pop_back();
REQUIRE(liste.size()==4);
liste.pop_front();
REQUIRE(liste.size()==3);
//(45,27,11)

REQUIRE(liste.front()==45);
REQUIRE(liste.back()==11);

liste.pop_back();
REQUIRE(liste.size()==2);
liste.pop_front();
REQUIRE(liste.size()==1);

REQUIRE(liste.front()==liste.back());
REQUIRE(liste.front()==27);
REQUIRE(liste.back()==27);

liste.pop_back();
REQUIRE(liste.empty());
}

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

REQUIRE (liste.begin() == liste.end());
REQUIRE (b == e);
}

TEST_CASE ( " provide acces to the first element with begin " , " [ iterators ] " )
{
List <int>list;
list.push_back (27);
REQUIRE (27==*list.begin ());
list.push_back (28);
list.push_front (29);
REQUIRE (29==*list.begin ());
}

TEST_CASE ( "6" , " [six] " )
{
List <int> liste1;
List <int> liste2;
List <int> liste3;

liste1.push_back (27);
liste1.push_back (28);
liste1.push_front (29);
liste1.push_back (23);
liste1.push_back (22);
liste1.push_front (21);

liste2.push_back (27);
liste2.push_back (28);
liste2.push_front (29);
liste2.push_back (23);
liste2.push_back (22);
liste2.push_front (21);

//21,29,27,28,23,22

liste3.push_back (47);
liste3.push_back (28);
liste3.push_front (29);
liste3.push_back (23);
liste3.push_back (52);
liste3.push_front (21);

REQUIRE (liste1==liste2);
REQUIRE (liste2!=liste3);
REQUIRE (liste3!=liste1);
}

TEST_CASE ( "7" , " [ constructor ] " )
{
List < int > list ;
list . push_front (1);
list . push_front (2);
list . push_front (3);
list . push_front (4);
List < int > list2 { list };

REQUIRE ( list == list2 );
}

TEST_CASE ( "8" , " [insert] " )
{
List <int>list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
list.push_front(5);
list.push_front(6);
list.push_front(7);
list.push_front(8);
ListIterator<int> i = list.begin();
i++;
i++;
list.insert(400 , i);



REQUIRE ( list.size() == 9);
REQUIRE (*list.begin()== 8);
ListIterator<int> a = list.begin();
a++;
REQUIRE ( *a == 7);
a++;
REQUIRE ( *a == 400 );
a=list.end();
a--;
REQUIRE ( *a == 1);
}
TEST_CASE ( "9" , " [reverse] " )
{
List <int>list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
list.push_front(5);
list.push_front(6);
list.push_front(7);
list.push_front(8);
list.push_front(9);
list.push_front(10);
list.push_front(11);
list.push_front(12);
list.push_front(13);
list.push_front(14);
list.push_front(15);
list.push_front(16);

List<int> listorig{list};
list.reverse();

//tests

ListIterator<int> a = list.begin();
ListIterator<int> b = listorig.begin();

REQUIRE(list.size() == listorig.size());

while(a != list.end())
{
REQUIRE ( *b ==(list.size()+1) - *a);
a++;
b++;
}

}

TEST_CASE ( "9.2" , " [reverse alsfreiefunktion] " )
{
List <int>list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
list.push_front(5);
list.push_front(6);
list.push_front(7);
list.push_front(8);
list.push_front(9);
list.push_front(10);
list.push_front(11);
list.push_front(12);
list.push_front(13);
list.push_front(14);
list.push_front(15);
list.push_front(16);

List<int> listnew {reverse(list)};

//tests

REQUIRE(list.size() == listnew.size());
ListIterator<int> a = list.begin();
ListIterator<int> b = listnew.begin();

while(a != list.end())
{
REQUIRE ( *a == 17 - *b);
a++;
b++;
}

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

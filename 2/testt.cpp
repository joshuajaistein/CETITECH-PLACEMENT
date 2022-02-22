#define CATCH_CONFIG_MAIN
#include <iostream>
#include <catch.hpp>

using namespace std;

TEST_CASE("TESTCASE11")
{
   int n=34 , k=15;
   
   REQUIRE(n == 34);
   REQUIRE(k == 15);
}

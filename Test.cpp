#include "doctest.h"
#include <iostream>

using namespace std;

TEST_CASE("Test")
{
    for (int i = 0; i < 100; i++)
        CHECK(true);
};
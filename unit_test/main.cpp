#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include "gtest/gtest.h"

using namespace std;

#define COUT(x) std::cout << #x << ": " << x << std::endl;
#define COUT_DO(x) std::cout << #x << std::endl; x

extern void test_type_sequence();

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    test_type_sequence();

    return RUN_ALL_TESTS();
}

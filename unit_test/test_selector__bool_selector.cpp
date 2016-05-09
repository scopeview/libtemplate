#include <string>
#include <iostream>
#include <utility>
#include "gtest/gtest.h"
#include "libtemplate/_.hpp"

namespace {

using namespace libtemplate;

struct is_active {};
struct is_empty {};
struct is_initialized {};

typedef bool_selector<is_active, is_empty, is_initialized> A_bool_selector;
class A : public A_bool_selector {
};

TEST(test_estd_template, bool_selector)
{
    A a;

    EXPECT_TRUE(a.is_false<is_active>());
    a.set_bool<is_active>(true);
    EXPECT_TRUE(a.is_true<is_active>());
    
    EXPECT_TRUE(a.is_false<is_empty>());
    EXPECT_TRUE(a.get_bool<is_empty>() == false);
    EXPECT_TRUE(a.is_true<is_empty>());
}

}

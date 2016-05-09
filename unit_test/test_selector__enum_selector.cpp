#include <string>
#include <iostream>
#include <utility>
#include "gtest/gtest.h"
#include "libtemplate/_.hpp"

namespace {

using namespace libtemplate;

enum class type_1 {
    A,B,C,
	};
enum class type_2 {
    E,F,G,
	};
enum class type_3 {
    X,Y,Z,
	};

typedef enum_selector<type_1, type_2, type_3> A_enum_selector;
class A : public A_enum_selector {};

TEST(test_estd_template, bool_selector)
{
    A a;

    a.set_enum<type_1>(type_1::A);
    EXPECT_TRUE(a.is_enum<type_1>(type_1::A));
    EXPECT_TRUE(a.get_enum<type_1>() == type_1::A);

    a.set_enum<type_2>(type_2::F);
    EXPECT_TRUE(a.is_enum<type_2>(type_2::F));
    EXPECT_TRUE(a.get_enum<type_2>() == type_2::F);

    a.set_enum<type_3>(type_3::Z);
    EXPECT_TRUE(a.is_enum<type_3>(type_3::Z));
    EXPECT_TRUE(a.get_enum<type_3>() == type_3::Z);
}

}

#include <list>
#include <string>
#include <iostream>
#include <utility>
#include "gtest/gtest.h"
#include "libtemplate/_.hpp"

namespace {

using namespace libtemplate;

struct A {
    std::string a;
    A() {}
    A(const std::string& s) : a(s) {}
    std::string to_string() {return a;}
};

struct B : public std::string,
	   public A
{
    B(const std::string& s1, const std::string& s2)
	: std::string(s1), A(s2)
	{}
};

struct C : public std::list<int>,
	   public B
{
    C(const std::string& s1, const std::string& s2)
	: B(s1, s2)
	{}
};

struct D : public std::list<std::string>,
	   public C
{
    D(const std::string& s1, const std::string& s2)
	: C(s1, s2)
	{}
};


TEST(test_estd_template, static_cast_reference)
{
    std::string s1("1");
    std::string s2("2");
    std::string s3("3");

    //
    B b(s1, s2);
    EXPECT_EQ(s1, (static_cast_reference<B, std::string>(b)));
    EXPECT_EQ(s2, (static_cast_reference<B, A>(b).to_string()));

    // 
    C c(s1, s2);
    EXPECT_EQ(s1, (static_cast_reference<C, B, std::string>(c)));
    EXPECT_EQ(s2, (static_cast_reference<C, B, A>(c).to_string()));

    // 
    D d(s1, s2);
    EXPECT_EQ(s1, (static_cast_reference<D, C, B, std::string>(d)));
    EXPECT_EQ(s2, (static_cast_reference<D, C, B, A>(d).to_string()));
}

}

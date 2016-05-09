#include <string>
#include <iostream>
#include <utility>
#include "gtest/gtest.h"
#include "libtemplate/_.hpp"

#define COUT(x) std::cout << #x << ": " << x << std::endl;
#define COUT_DO(x) std::cout << #x << std::endl; x

namespace {

using namespace libtemplate;

struct A {
    int m_a;
    A() : m_a(1) {}
    A(int n) : m_a(n) {}
    friend std::ostream& operator<<(std::ostream& os, const A& o) {return os << "A: " << o.m_a;}
};
struct B {
    int m_b;
    B() : m_b(2) {}
    B(int n) : m_b(n) {}
    friend std::ostream& operator<<(std::ostream& os, const B& o) {return os << "B: " << o.m_b;}
};
struct C {
    int m_c;
    C() : m_c(3) {}
    C(int n) : m_c(n) {}
    friend std::ostream& operator<<(std::ostream& os, const C& o) {return os << "C: " << o.m_c;}
};

typedef type_selector<A, B, C> container_type_selector;
class Container : public container_type_selector
{};

TEST(test_estd_template, bool_selector)
{
    Container c;
    COUT((c.getter<A>()));
    COUT((c.getter<B>()));
    COUT((c.getter<C>()));

    c.setter<A>(A(10));
    c.setter<B>(B(11));
    c.setter<C>(C(12));

    COUT((c.getter<A>()));
    COUT((c.getter<B>()));
    COUT((c.getter<C>()));
}

}

#include <tuple>
#include <functional>
#include "libtemplate/type_sequence/_.hpp"

using namespace libtemplate::type_sequence;
#define SASSERT(X) static_assert(X, "")

struct A {};
struct B {};
struct C {};
struct D {};
struct E {};
struct F {};
struct G {};

void test_first_rest()
{
    typedef std::tuple<A> one_type;
    typedef std::tuple<A, B> two_type;
    typedef std::tuple<A, B, C> three_type;

    SASSERT((std::is_same<std::tuple<>, std::tuple<>>::value));

    // one type
    SASSERT((std::is_same<A, first<one_type>::type>::value));

    // two type
    SASSERT((std::is_same<A, first<two_type>::type>::value));
    SASSERT((std::is_same<std::tuple<B>, rest<two_type>::type>::value));

    // three type
    SASSERT((std::is_same<A, first<three_type>::type>::value));
    SASSERT((std::is_same<std::tuple<B, C>, rest<three_type>::type>::value));
}

void test_compare()
{
    typedef std::tuple<A> l_1_type;
    typedef std::tuple<A, B> l_2_type;
    typedef std::tuple<C> r_1_type;
    typedef std::tuple<C, D> r_2_type;

    SASSERT((is_same_size<l_1_type, r_1_type>::value));
    SASSERT((is_same_size<l_2_type, r_2_type>::value));
    SASSERT((!is_same_size<l_1_type, r_2_type>::value));
    SASSERT((!is_same_size<l_2_type, r_1_type>::value));
}

void test_concat()
{
    typedef std::tuple<A> first_type;
    typedef std::tuple<B> second_type;
    typedef std::tuple<C, D> third_type;

    SASSERT((std::is_same<std::tuple<A, B>, concat<first_type, second_type>::type>::value));
    SASSERT((std::is_same<std::tuple<A, B, C, D>, concat<first_type, second_type, third_type>::type>::value));
}

void test_drop_left1()
{
    typedef std::tuple<A, B> two_type;
    typedef std::tuple<A, B, C, D> four_type;
    
    SASSERT((std::is_same<std::tuple<B>, drop_left1<two_type>::type>::value));
    SASSERT((std::is_same<std::tuple<B, C, D>, drop_left1<four_type>::type>::value));
}

void test_drop_leftN()
{
    {
	typedef std::tuple<A, B, C, D> four_type;
	typedef typename drop_leftN<four_type, 2>::type result_type;

	SASSERT((std::is_same<std::tuple<C, D>, result_type>::value));
    }
    {
	typedef std::tuple<A, B> type_2;
	// Note
	// this should fail
	// typedef typename drop_leftN<type_2, 2>::type result_type;
    }
}

void test_drop_right1()
{
    {
	typedef std::tuple<A, B> two_type;
	typedef drop_right1<two_type>::type result_type;
	SASSERT((std::is_same<std::tuple<A>, result_type>::value));
    }

    {
	typedef std::tuple<A, B, C, D> four_type;
	typedef drop_right1<four_type>::type result_type;
	SASSERT((std::is_same<std::tuple<A, B, C>, result_type>::value));
    }
}

void test_drop_rightN()
{
    {
	typedef std::tuple<A, B> two_type;
	typedef drop_rightN<two_type, 1>::type result_type;
	SASSERT((std::is_same<std::tuple<A>, result_type>::value));
    }

    {
	typedef std::tuple<A, B, C, D> four_type;
	typedef drop_rightN<four_type, 3>::type result_type;
	SASSERT((std::is_same<std::tuple<A>, result_type>::value));
    }    
}

void test_dup()
{
    typedef std::tuple<A, A, A> expected_type;
    typedef dup<3, A>::type result_type;
    SASSERT((std::is_same<expected_type, result_type>::value));
}

void test_find_first()
{
    typedef std::tuple<A, B, C, A, A, C> type_sequence;
    SASSERT((0 == find_first<type_sequence, A>::value));
    SASSERT((1 == find_first<type_sequence, B>::value));
    SASSERT((2 == find_first<type_sequence, C>::value));
    SASSERT((-1 == find_first<type_sequence, D>::value));
}

void test_find_first_not()
{
    typedef std::tuple<A, B, C> type_sequence;
    SASSERT((1 == find_first_not<type_sequence, A>::value));
    SASSERT((0 == find_first_not<type_sequence, B>::value));
    SASSERT((0 == find_first_not<type_sequence, C>::value));
    SASSERT((0 == find_first_not<type_sequence, D>::value));
}

////////////////
struct Derived : public A {};
template<typename T>
struct is_base_of_A {
    enum {value = std::is_base_of<A, T>::value && !std::is_same<A, T>::value};
};
void test_find_if()
{
    {
	typedef std::tuple<A, B, C, Derived> type_sequence;
	SASSERT((3 == find_if<type_sequence, is_base_of_A>::value));
    }
    {
	typedef std::tuple<A, B, C, D> type_sequence;
	SASSERT((-1 == find_if<type_sequence, is_base_of_A>::value));
    }
}

////////////////
void test_find_last()
{
    typedef std::tuple<A, B, C, C, B, A> type_sequence;
    SASSERT((5 == find_last<type_sequence, A>::value));
    SASSERT((4 == find_last<type_sequence, B>::value));
    SASSERT((3 == find_last<type_sequence, C>::value));
    SASSERT((-1 == find_last<type_sequence, D>::value));
}

void test_find_last_not()
{
    typedef std::tuple<A, A, A, B> type_sequence;
    SASSERT((3 == find_last_not<type_sequence, A>::value));
    SASSERT((2 == find_last_not<type_sequence, B>::value));
    SASSERT((3 == find_last_not<type_sequence, C>::value));
}

void test_has_same_type()
{
    typedef std::tuple<A> type_a;
    typedef std::tuple<A, B, C, D> type_abcd;
    typedef std::tuple<A, A> type_aa;
    typedef std::tuple<A, B, A> type_aba;

    SASSERT((!has_same_type<type_a>::value));
    SASSERT((!has_same_type<type_abcd>::value));
    SASSERT((has_same_type<type_aa>::value));
    SASSERT((has_same_type<type_aba>::value));
}

void test_index_of()
{
    typedef std::tuple<A, B, C, A, A, C> sequence_type;
    SASSERT((0 == index_of<A, sequence_type, 0>::value));
    SASSERT((1 == index_of<B, sequence_type, 0>::value));
    SASSERT((2 == index_of<C, sequence_type, 0>::value));
    SASSERT((-1 == index_of<D, sequence_type, 0>::value));

    SASSERT((3 == index_of<A, sequence_type, 1>::value));
    SASSERT((4 == index_of<A, sequence_type, 4>::value));
}

void test_last_of()
{
    typedef std::tuple<A> type_1;
    typedef std::tuple<A, B> type_2;
    typedef std::tuple<A, B, C> type_3;
    SASSERT((std::is_same<A, last_of<type_1>::type>::value));
    SASSERT((std::is_same<B, last_of<type_2>::type>::value));
    SASSERT((std::is_same<C, last_of<type_3>::type>::value));
}

void test_resplitLR_lessL()
{
    typedef std::tuple<A, B, C, D> left_sequence;
    typedef std::tuple<E, F, G> right_sequence;

    typedef typename resplitLR_lessL<left_sequence, right_sequence, 1>::first_tuple_type resplited_l;
    typedef typename resplitLR_lessL<left_sequence, right_sequence, 1>::second_tuple_type resplited_r;
    
    SASSERT((std::is_same<std::tuple<A, B, C>, resplited_l>::value));
    SASSERT((std::is_same<std::tuple<D, E, F, G>, resplited_r>::value));
}

void test_resplitLR_lessR()
{
    typedef std::tuple<A, B, C, D> type_1;
    typedef std::tuple<E, F, G> type_2;
    typedef resplitLR_lessR<type_1, type_2, 2>::first_tuple_type first_tuple_type;
    typedef resplitLR_lessR<type_1, type_2, 2>::second_tuple_type second_tuple_type;
    typedef std::tuple<A, B, C, D, E, F> expected_first_sequence;
    typedef std::tuple<G> expected_second_sequence;

    SASSERT((std::is_same<expected_first_sequence, first_tuple_type>::value));
    SASSERT((std::is_same<expected_second_sequence, second_tuple_type>::value));
}

void test_result_of()
{
    typedef int(*type_1)();
    typedef char(*type_2)();
    typedef float(*type_3)();
    typedef std::tuple<int, char, float> expected_sequence;

    SASSERT((std::is_same<int, std::result_of<type_1()>::type>::value));
    typedef typename result_of<std::tuple<type_1, type_2, type_3>>::type result_sequence;

    SASSERT((std::is_same<expected_sequence, result_sequence>::value));
}

void test_reverse()
{
    typedef std::tuple<A> type_1;
    typedef std::tuple<A, B> type_2;
    typedef std::tuple<A, B, C> type_3;
    typedef typename reverse<type_1>::type reverse_type_1;
    typedef typename reverse<type_2>::type reverse_type_2;
    typedef typename reverse<type_3>::type reverse_type_3;

    SASSERT((std::is_same<std::tuple<A>, reverse_type_1>::value));
    SASSERT((std::is_same<std::tuple<B, A>, reverse_type_2>::value));
    SASSERT((std::is_same<std::tuple<C, B, A>, reverse_type_3>::value));
}

void test_rotate_left()
{
    typedef std::tuple<A, B, C, D> type;
    typedef typename rotate_left<type>::type rotated_type;
    typedef std::tuple<B, C, D, A> expected_type;
    SASSERT((std::is_same<expected_type, rotated_type>::value));
}

void test_rotate_right()
{
    typedef std::tuple<A, B, C, D> type;
    typedef typename rotate_right<type>::type rotated_type;
    typedef std::tuple<D, A, B, C> expected_type;
    SASSERT((std::is_same<expected_type, rotated_type>::value));
}

void test_sequence_size()
{
    typedef std::tuple<A> type_1;
    typedef std::tuple<A, B> type_2;
    typedef std::tuple<A, B, C> type_3;
    
    SASSERT((std::tuple_size<type_1>::value == 1));
    SASSERT((std::tuple_size<type_2>::value == 2));
    SASSERT((std::tuple_size<type_3>::value == 3));
}

////////////////
namespace test_specialize_template_sequence_ns {
struct A {};
template<typename T>
struct wrapper_1 {
    typedef T internal_type;
    enum {value = 1};
};
template<typename T>
struct wrapper_2 {
    typedef T internal_type;
    enum {value = 2};
};
template<typename T>
struct wrapper_3 {
    typedef T internal_type;
    enum {value = 3};
};
}
void test_specialize_template_sequence()
{
    using A = test_specialize_template_sequence_ns::A;
    typedef typename specialize_template_sequence<A, 
						  test_specialize_template_sequence_ns::wrapper_1, 
						  test_specialize_template_sequence_ns::wrapper_2, 
						  test_specialize_template_sequence_ns::wrapper_3>::type wrapped_sequence;
    typedef std::tuple<test_specialize_template_sequence_ns::wrapper_1<A>, 
	       test_specialize_template_sequence_ns::wrapper_2<A>, 
	       test_specialize_template_sequence_ns::wrapper_3<A>> expected_sequence;
    SASSERT((std::is_same<expected_sequence, wrapped_sequence>::value));
}

////////////////
void test_split1N()
{
    typedef std::tuple<A> type_1;
    typedef std::tuple<A, B> type_2;
    typedef std::tuple<A, B, C> type_3;

    SASSERT((std::is_same<A, split1N<type_1>::first_type>::value));
    SASSERT((std::is_same<std::tuple<A>, split1N<type_1>::first_tuple_type>::value));

    SASSERT((std::is_same<A, split1N<type_2>::first_type>::value));
    SASSERT((std::is_same<std::tuple<A>, split1N<type_2>::first_tuple_type>::value));
    SASSERT((std::is_same<std::tuple<B>, split1N<type_2>::second_tuple_type>::value));

    SASSERT((std::is_same<A, split1N<type_3>::first_type>::value));
    SASSERT((std::is_same<std::tuple<A>, split1N<type_3>::first_tuple_type>::value));
    SASSERT((std::is_same<std::tuple<B, C>, split1N<type_3>::second_tuple_type>::value));
}

void test_split2N()
{
    typedef std::tuple<A, B, C, D> type;
    typedef split2N<type>::first_type	first_type;
    typedef split2N<type>::second_type	second_type;
    typedef split2N<type>::first_tuple_type	first_tuple_type;
    typedef split2N<type>::second_tuple_type	second_tuple_type;

    SASSERT((std::is_same<A, first_type>::value));
    SASSERT((std::is_same<B, second_type>::value));
    SASSERT((std::is_same<std::tuple<A, B>, first_tuple_type>::value));
    SASSERT((std::is_same<std::tuple<C, D>, second_tuple_type>::value));
}

void test_splitN1()
{
    typedef std::tuple<A, B, C, D> type;
    typedef splitN1<type>::last_type last_type;
    typedef splitN1<type>::first_tuple_type first_tuple_type;
    typedef splitN1<type>::second_tuple_type second_tuple_type;

    SASSERT((std::is_same<D, last_type>::value));
    SASSERT((std::is_same<std::tuple<A, B, C>, first_tuple_type>::value));
    SASSERT((std::is_same<std::tuple<D>, second_tuple_type>::value));
}

void test_splitN2()
{
    typedef std::tuple<A, B, C, D> type;
    typedef splitN2<type>::last_type last_type;
    typedef splitN2<type>::before_last_type before_last_type;
    typedef splitN2<type>::first_tuple_type first_tuple_type;
    typedef splitN2<type>::second_tuple_type second_tuple_type;

    SASSERT((std::is_same<D, last_type>::value));
    SASSERT((std::is_same<C, before_last_type>::value));
    SASSERT((std::is_same<std::tuple<A, B>, first_tuple_type>::value));
    SASSERT((std::is_same<std::tuple<C, D>, second_tuple_type>::value));
}

void test_type_of()
{
    typedef std::tuple<A, B, C, D> sequence_type;
    typedef type_of<0, sequence_type>::type type_0;
    typedef type_of<1, sequence_type>::type type_1;
    typedef type_of<2, sequence_type>::type type_2;
    typedef type_of<3, sequence_type>::type type_3;

    SASSERT((std::is_same<A, type_0>::value));
    SASSERT((std::is_same<B, type_1>::value));
    SASSERT((std::is_same<C, type_2>::value));
    SASSERT((std::is_same<D, type_3>::value));
}

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
void test_type_sequence()
{
    test_first_rest();
    test_compare();
    test_concat();
    test_drop_left1();
    test_drop_leftN();
    test_drop_right1();
    test_drop_rightN();
    test_dup();
    test_find_first();
    test_find_first_not();
    test_find_if();
    test_find_last();
    test_find_last_not();
    test_has_same_type();
    test_index_of();
    test_last_of();
    test_resplitLR_lessL();
    test_resplitLR_lessR();
    test_result_of();
    test_reverse();
    test_rotate_left();
    test_rotate_right();
    test_sequence_size();
    test_specialize_template_sequence();
    test_split1N();
    test_split2N();
    test_splitN1();
    test_splitN2();
    test_type_of();
}

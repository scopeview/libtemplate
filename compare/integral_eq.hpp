#ifndef __LIBTEMPLATE_COMPARE_INTEGRAL_EQ_HPP__
#define __LIBTEMPLATE_COMPARE_INTEGRAL_EQ_HPP__

namespace libtemplate {

template<typename T, typename T1, typename T2>
bool integral_eq(const T1& t1, const T2& t2) {
    static_assert(std::is_integral<T>::value, "");
    static_assert(std::is_integral<T1>::value, "");
    static_assert(std::is_integral<T2>::value, "");
    return (T)t1 == (T)t2;
}

}
#endif	/* __LIBTEMPLATE_COMPARE_INTEGRAL_EQ_HPP__ */

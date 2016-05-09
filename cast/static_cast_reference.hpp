#ifndef __LIBTEMPLATE_CAST_STATIC_CAST_REFERENCE_HPP__
#define __LIBTEMPLATE_CAST_STATIC_CAST_REFERENCE_HPP__

namespace libtemplate {

template<typename T, typename C>
C& static_cast_reference(T& t) {
    static_assert(std::is_base_of<C, T>::value, "");
    return static_cast<C&>(t);
}

template<typename T, typename C, typename C1>
C1& static_cast_reference(T& t) {
    static_assert(std::is_base_of<C, T>::value, "");
    static_assert(std::is_base_of<C1, C>::value, "");
    return static_cast<C1&>(static_cast<C&>(t));
}

template<typename T, typename C, typename C1, typename C2>
C2& static_cast_reference(T& t) {
    static_assert(std::is_base_of<C, T>::value, "");
    static_assert(std::is_base_of<C1, C>::value, "");
    static_assert(std::is_base_of<C2, C1>::value, "");
    return static_cast<C2&>(static_cast<C1&>(static_cast<C&>(t)));
}

}
#endif	/* __LIBTEMPLATE_CAST_STATIC_CAST_REFERENCE_HPP__ */

#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_FIRST_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_FIRST_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct first;

template<typename T, typename... Rest>
struct first<std::tuple<T, Rest...>> {
    typedef T type;
};

template<typename T>
struct first<std::tuple<T>> {
    typedef T type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_FIRST_HPP__ */

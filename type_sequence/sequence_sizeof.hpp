#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_SEQUENCE_SIZEOF_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_SEQUENCE_SIZEOF_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct sequence_sizeof;

template<typename T, typename... Rest>
struct sequence_sizeof<std::tuple<T, Rest...>> {
    enum {value = sizeof(T) + sequence_sizeof<std::tuple<Rest...>>::value};
};

template<typename T>
struct sequence_sizeof<std::tuple<T>> {
    enum {value = sizeof(T)};
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_SEQUENCE_SIZEOF_HPP__ */

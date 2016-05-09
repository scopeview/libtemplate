#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_TYPE_OF_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_TYPE_OF_HPP__

#include "libtemplate/type_sequence/first.hpp"

namespace libtemplate { namespace type_sequence {

template<int index, typename Tuple>
struct type_of;

template<int index, typename... T>
struct type_of<index, std::tuple<T...>> {
    typedef typename drop_leftN<std::tuple<T...>, index>::type dropped_tuple_type;
    typedef typename first<dropped_tuple_type>::type type;
};

template<typename... T>
struct type_of<0, std::tuple<T...>> {
    typedef typename first<std::tuple<T...>>::type type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_TYPE_OF_HPP__ */

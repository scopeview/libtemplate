#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_INDEX_OF_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_INDEX_OF_HPP__

#include "libtemplate/type_sequence/drop_leftN.hpp"

namespace libtemplate { namespace type_sequence {

template<typename Find, typename Tuple, int size, int startIndex = 0>
struct index_of_impl;

template<typename Find, typename T, typename... RestT, int size, int startIndex>
struct index_of_impl<Find, std::tuple<T, RestT...>, size, startIndex> {
    static_assert(startIndex < size, "");
    enum {value = (std::is_same<Find, T>::value ?
		   startIndex :
		   index_of_impl<Find, std::tuple<RestT...>, size, startIndex+1>::value)};
};

template<typename Find, typename T, int size, int startIndex>
struct index_of_impl<Find, std::tuple<T>, size, startIndex> {
    enum {value = std::is_same<Find, T>::value ? startIndex : -1};
};

////////////////////////////////////////////////////////////////
template<typename Find, typename Tuple, int startIndex = 0>
struct index_of;

template<typename Find, typename T, typename... RestT, int startIndex>
struct index_of<Find, std::tuple<T, RestT...>, startIndex> {
    typedef std::tuple<T, RestT...> tuple_type;
    typedef typename drop_leftN<tuple_type, startIndex>::type rest_tuple_type;
    enum {indexOfRest = index_of_impl<Find, rest_tuple_type, std::tuple_size<rest_tuple_type>::value>::value};
    enum {value = indexOfRest == -1 ? -1 : startIndex + indexOfRest};
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_INDEX_OF_HPP__ */

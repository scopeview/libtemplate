#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_HAS_SAME_TYPE_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_HAS_SAME_TYPE_HPP__

#include "libtemplate/type_sequence/index_of.hpp"

namespace libtemplate { namespace type_sequence {

template<typename CheckType, typename T>
struct has_same_type_impl;

template<typename CheckType, typename T, typename... RestT>
struct has_same_type_impl<CheckType, std::tuple<T, RestT...>>
{
    enum {value = index_of<CheckType, std::tuple<T, RestT...>, 0>::value != -1 ? 1 :
	  has_same_type_impl<T, std::tuple<RestT...>>::value};
};

template<typename CheckType, typename T>
struct has_same_type_impl<CheckType, std::tuple<T>>
{
    enum {value = std::is_same<CheckType, T>::value};
};

////////////////////////////////////////////////////////////////
template<typename T>
struct has_same_type;

template<typename T, typename... RestT>
struct has_same_type<std::tuple<T, RestT...>> {
    enum {value = has_same_type_impl<T, std::tuple<RestT...>>::value};
};

template<typename T, typename U>
struct has_same_type<std::tuple<T, U>> {
    enum {value = std::is_same<T, U>::value};
};

template<typename T>
struct has_same_type<std::tuple<T>> : std::false_type {};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_HAS_SAME_TYPE_HPP__ */

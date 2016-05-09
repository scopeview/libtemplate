#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_LAST_OF_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_LAST_OF_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct last_of;

template<typename First, typename... RestT>
struct last_of<std::tuple<First, RestT...>> {
    typedef typename last_of<std::tuple<RestT...>>::type type;
};

template<typename T>
struct last_of<std::tuple<T>> {
    typedef T type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_LAST_OF_HPP__ */

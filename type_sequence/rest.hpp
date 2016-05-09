#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_REST_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_REST_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct rest;

template<typename T, typename... Rest>
struct rest<std::tuple<T, Rest...>> {
    typedef std::tuple<Rest...> type;
};

template<typename T>
struct rest<std::tuple<T>> {
    typedef std::tuple<> type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_REST_HPP__ */

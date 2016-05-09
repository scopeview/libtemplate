#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_CONCAT_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_CONCAT_HPP__

namespace libtemplate { namespace type_sequence {

template<typename... T>
struct concat;

template<typename... T1, typename... T2>
struct concat<std::tuple<T1...>, std::tuple<T2...>> {
    typedef std::tuple<T1..., T2...> type;
};

template<typename... T1, typename... T2, typename... T3>
struct concat<std::tuple<T1...>, std::tuple<T2...>, std::tuple<T3...>> {
    typedef std::tuple<T1..., T2..., T3...> type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_CONCAT_HPP__ */

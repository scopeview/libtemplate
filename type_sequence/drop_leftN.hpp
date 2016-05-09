#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_DROP_LEFTN_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_DROP_LEFTN_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T, size_t drop_count>
struct drop_leftN;

////////////////////////////////////////////////////////////////
namespace helper {
template<typename T, size_t drop_count, bool is_zero = drop_count==0>
struct drop_leftN;

template<typename T, typename... RestT, size_t drop_count>
struct drop_leftN<std::tuple<T, RestT...>, drop_count, false> {
    typedef typename drop_leftN<std::tuple<RestT...>, drop_count-1>::type type;
};

template<typename... T>
struct drop_leftN<std::tuple<T...>, 0, true> {
    typedef std::tuple<T...> type;
};

}

////////////////////////////////////////////////////////////////
template<typename T, typename... RestT, size_t drop_count>
struct drop_leftN<std::tuple<T, RestT...>, drop_count> {
    typedef std::tuple<T, RestT...> tuple_type;
    static_assert(drop_count >= 0, "");
    static_assert(drop_count <= std::tuple_size<tuple_type>::value, "");
    typedef typename helper::drop_leftN<tuple_type, drop_count>::type type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_DROP_LEFTN_HPP__ */

#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_DROP_RIGHTN_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_DROP_RIGHTN_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T, size_t drop_count>
struct drop_rightN;

template<typename T, typename... RestT, size_t drop_count>
struct drop_rightN<std::tuple<T, RestT...>, drop_count> {
    typedef std::tuple<T, RestT...> tuple_type;
    static_assert(drop_count < std::tuple_size<tuple_type>::value, "");

    enum {move_count = std::tuple_size<tuple_type>::value - drop_count - 1};
    typedef typename std::conditional<drop_count==0,
				      tuple_type,
				      typename resplitLR_lessR<std::tuple<T>, std::tuple<RestT...>, move_count>::first_tuple_type>::type type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_DROP_RIGHTN_HPP__ */

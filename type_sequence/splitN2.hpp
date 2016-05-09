#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_SPLITN2_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_SPLITN2_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct splitN2;

template<typename T, typename... RestT>
struct splitN2<std::tuple<T, RestT...>> {
    typedef std::tuple<T, RestT...> tuple_type;
    enum {move_count = std::tuple_size<tuple_type>::value - 3};
    typedef resplitLR_lessR<std::tuple<T>, std::tuple<RestT...>, move_count> resplit_result;

    typedef typename resplit_result::first_tuple_type first_tuple_type;
    typedef typename resplit_result::second_tuple_type second_tuple_type;
    typedef typename first<second_tuple_type>::type before_last_type;
    typedef typename first<typename rest<second_tuple_type>::type>::type last_type;
};

template<typename T1, typename T2>
struct splitN2<std::tuple<T1, T2>> {
    typedef std::tuple<T1, T2> second_tuple_type;
    typedef T1 before_last_type;
    typedef T2 last_type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_SPLITN2_HPP__ */

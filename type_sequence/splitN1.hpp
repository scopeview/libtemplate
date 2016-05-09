#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_SPLITN1_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_SPLITN1_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct splitN1;

template<typename T, typename... RestT>
struct splitN1<std::tuple<T, RestT...>> {
    typedef std::tuple<T, RestT...> tuple_type;
    enum {move_count = std::tuple_size<tuple_type>::value - 2};
    typedef resplitLR_lessR<std::tuple<T>, std::tuple<RestT...>, move_count> resplit_result;

    typedef typename resplit_result::first_tuple_type first_tuple_type;
    typedef typename resplit_result::second_tuple_type second_tuple_type;
    typedef typename first<second_tuple_type>::type last_type;
};

template<typename T>
struct splitN1<std::tuple<T>> {
    typedef std::tuple<T> second_tuple_type;
    typedef T last_type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_SPLITN1_HPP__ */

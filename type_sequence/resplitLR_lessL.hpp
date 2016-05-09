#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_RESPLITLR_LESSL_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_RESPLITLR_LESSL_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T1, typename T2, size_t count>
struct resplitLR_lessL;

template<typename TS1First, typename... TS1Rest, typename... TS2, size_t count>
struct resplitLR_lessL<std::tuple<TS1First, TS1Rest...>, std::tuple<TS2...>, count> {
    typedef std::tuple<TS1First, TS1Rest...> tuple_type_left;
    static_assert(count < std::tuple_size<tuple_type_left>::value, "");

    enum {move_count = std::tuple_size<tuple_type_left>::value - count - 1};
    typedef typename resplitLR_lessR<std::tuple<TS1First>, std::tuple<TS1Rest...>, move_count>::first_tuple_type tuple_type_1;
    typedef typename resplitLR_lessR<std::tuple<TS1First>, std::tuple<TS1Rest...>, move_count>::second_tuple_type tuple_type_2;
    typedef std::tuple<TS2...> tuple_type_3;

    typedef tuple_type_1 first_tuple_type;
    typedef typename concat<tuple_type_2, tuple_type_3>::type second_tuple_type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_RESPLITLR_LESSL_HPP__ */

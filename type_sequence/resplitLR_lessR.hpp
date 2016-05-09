#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_RESPLITLR_LESSR_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_RESPLITLR_LESSR_HPP__

#include <cstdlib>

namespace libtemplate { namespace type_sequence {

template<typename T1, typename T2, size_t count>
struct resplitLR_lessR;

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
namespace helper {

template<typename TS1, typename TS2, size_t count, bool is_zero = count==0>
struct resplitLR_lessR;

template<typename... TS1, typename TSFirst2, typename... TSRestT2, size_t count>
struct resplitLR_lessR<std::tuple<TS1...>, std::tuple<TSFirst2, TSRestT2...>, count, false> {
    typedef std::tuple<TS1..., TSFirst2>	first_tuple_type__;
    typedef std::tuple<TSRestT2...>		second_tuple_type__;
    typedef typename resplitLR_lessR<first_tuple_type__, second_tuple_type__, count-1>::first_tuple_type first_tuple_type;
    typedef typename resplitLR_lessR<first_tuple_type__, second_tuple_type__, count-1>::second_tuple_type second_tuple_type;
};

template<typename... TS1, typename... TS2>
struct resplitLR_lessR<std::tuple<TS1...>, std::tuple<TS2...>, 0, true> {
    typedef std::tuple<TS1...>	first_tuple_type;
    typedef std::tuple<TS2...>	second_tuple_type;
};

}

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
template<typename... TS1, typename... TS2, size_t count>
struct resplitLR_lessR<std::tuple<TS1...>, std::tuple<TS2...>, count> {
    typedef std::tuple<TS1...>			tuple_type1;
    typedef std::tuple<TS2...>			tuple_type2;
    static_assert(count < std::tuple_size<tuple_type2>::value, "");

    typedef typename helper::resplitLR_lessR<tuple_type1, tuple_type2, count>::first_tuple_type first_tuple_type;
    typedef typename helper::resplitLR_lessR<tuple_type1, tuple_type2, count>::second_tuple_type second_tuple_type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_RESPLITLR_LESSR_HPP__ */

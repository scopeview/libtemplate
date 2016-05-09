#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_SPLIT2N_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_SPLIT2N_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct split2N;

template<typename T1, typename T2, typename... RestT>
struct split2N<std::tuple<T1, T2, RestT...>> {
    typedef std::tuple<T1, T2>		first_tuple_type;
    typedef std::tuple<RestT...>	second_tuple_type;
    typedef T1			first_type;
    typedef T2			second_type;
};

template<typename T1, typename T2>
struct split2N<std::tuple<T1, T2>> {
    typedef std::tuple<T1, T2>		first_tuple_type;
    typedef T1			first_type;
    typedef T2			second_type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_SPLIT2N_HPP__ */

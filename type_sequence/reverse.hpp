#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_REVERSE_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_REVERSE_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct reverse;

template<typename T, typename... RestT>
struct reverse<std::tuple<T, RestT...>> {
    typedef std::tuple<T, RestT...> tuple_type;
    typedef splitN1<tuple_type> split_result_type;
    typedef typename concat<std::tuple<typename split_result_type::last_type>, 
			    typename reverse<typename split_result_type::first_tuple_type>::type
			    >::type type;
};

template<typename T1, typename T2>
struct reverse<std::tuple<T1, T2>> {
    typedef std::tuple<T2, T1> type;
};

template<typename T>
struct reverse<std::tuple<T>> {
    typedef std::tuple<T> type;
};
    
}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_REVERSE_HPP__ */

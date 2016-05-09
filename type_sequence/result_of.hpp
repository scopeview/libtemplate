#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_RESULT_OF_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_RESULT_OF_HPP__

namespace libtemplate { namespace type_sequence {

// Note
// - type should be _Callable as return_type(*func_type)(void)
template<typename T>
struct result_of;

template<typename T, typename... RestT>
struct result_of<std::tuple<T, RestT...>> {
    typedef std::tuple<typename std::result_of<T()>::type> first_result_type;
    typedef typename result_of<std::tuple<RestT...>>::type rest_result_type;
    typedef typename concat<first_result_type, rest_result_type>::type type;
};

template<typename T>
struct result_of<std::tuple<T>> {
    typedef std::tuple<typename std::result_of<T()>::type> type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_RESULT_OF_HPP__ */

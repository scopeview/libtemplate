#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_FIND_LAST_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_FIND_LAST_HPP__

namespace libtemplate { namespace type_sequence {

template<typename Tuple, typename Find>
struct find_last;

template<typename... T, typename Find>
struct find_last<std::tuple<T...>, Find> {
    typedef std::tuple<T...> tuple_type;
    typedef typename reverse<tuple_type>::type	reversed_tuple_type;
    enum {reversed_value = find_first<reversed_tuple_type, Find>::value};
    enum {value = reversed_value==-1 ? -1 : std::tuple_size<tuple_type>::value - reversed_value - 1};
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_FIND_LAST_HPP__ */

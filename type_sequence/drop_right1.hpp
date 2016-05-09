#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_DROP_RIGHT1_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_DROP_RIGHT1_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct drop_right1;

template<typename T, typename... RestT>
struct drop_right1<std::tuple<T, RestT...>> {
    typedef std::tuple<T, RestT...> tuple_type;
    typedef typename drop_rightN<tuple_type, 1>::type type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_DROP_RIGHT1_HPP__ */

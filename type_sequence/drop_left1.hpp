#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_DROP_LEFT1_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_DROP_LEFT1_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct drop_left1;

template<typename T, typename... RestT>
struct drop_left1<std::tuple<T, RestT...>> {
    typedef std::tuple<T, RestT...> tuple_type;
    typedef typename drop_leftN<tuple_type, 1>::type type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_DROP_LEFT1_HPP__ */

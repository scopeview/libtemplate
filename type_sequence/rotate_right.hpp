#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_ROTATE_RIGHT_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_ROTATE_RIGHT_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct rotate_right;

template<typename T, typename... RestT>
struct rotate_right<std::tuple<T, RestT...>> {
    typedef std::tuple<T, RestT...> tuple_type;
    typedef typename splitN1<tuple_type>::first_tuple_type concat_second_tuple_type__;
    typedef typename splitN1<tuple_type>::second_tuple_type concat_first_tuple_type__;
    typedef typename concat<concat_first_tuple_type__, concat_second_tuple_type__>::type type;
};

template<typename T>
struct rotate_right<std::tuple<T>> {
    typedef std::tuple<T> tuple_type;
    typedef tuple_type type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_ROTATE_RIGHT_HPP__ */

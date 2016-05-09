#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_INT_SEQUENCE_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_INT_SEQUENCE_HPP__

namespace libtemplate { namespace type_sequence {

template<int... I>
struct tis;

template<int I, int... RestI>
struct tis<I, RestI...> {
    typedef tis<I, RestI...>		type;
    enum {first_int = I};
    typedef tis<RestI...>			rest_int_sequence_type;
    enum {size = 1 + sizeof...(RestI)};
    enum {rest_size = sizeof...(RestI)};
};

template<int I>
struct tis<I> {
    typedef tis<I>		type;
    enum {first_int = I};
    typedef tis<>				rest_int_sequence_type;
    enum {size = 1};
    enum {rest_size = 0};
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_INT_SEQUENCE_HPP__ */

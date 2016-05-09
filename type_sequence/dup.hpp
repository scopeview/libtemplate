#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_DUP_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_DUP_HPP__

#include "libtemplate/type_sequence/concat.hpp"

namespace libtemplate { namespace type_sequence {

template<size_t N, typename T>
struct dup {
    typedef typename concat<std::tuple<T>, typename dup<N-1, T>::type>::type type;
};

template<typename T>
struct dup<1, T> {
    typedef std::tuple<T> type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_DUP_HPP__ */

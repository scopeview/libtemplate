#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_FIND_FIRST_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_FIND_FIRST_HPP__

#include "libtemplate/type_sequence/index_of.hpp"

namespace libtemplate { namespace type_sequence {

template<typename Tuple, typename Find>
struct find_first;

template<typename... T, typename Find>
struct find_first<std::tuple<T...>, Find> {
    typedef std::tuple<T...> tuple_type;
    enum {value = index_of<Find, tuple_type, 0>::value};
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_FIND_FIRST_HPP__ */

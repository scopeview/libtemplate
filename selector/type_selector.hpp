#ifndef __LIBTEMPLATE_SELECTOR_TYPE_SELECTOR_HPP__
#define __LIBTEMPLATE_SELECTOR_TYPE_SELECTOR_HPP__

#include <tuple>
#include "libtemplate/type_sequence/_.hpp"

namespace libtemplate {

template<typename... T>
class type_selector {
protected:
    typedef std::tuple<T...> tuple_type;
    static_assert(!type_sequence::has_same_type<tuple_type>::value, "");

    tuple_type m_tuple;

public:
    template<typename U>
    inline U& getter() {
	return std::get<type_sequence::index_of<U, tuple_type, 0>::value>(m_tuple);
    }

    template<typename U>
    inline void setter(const U& u) {
	std::get<type_sequence::index_of<U, tuple_type, 0>::value>(m_tuple) = u;
    }
};

}
#endif	/* __LIBTEMPLATE_SELECTOR_TYPE_SELECTOR_HPP__ */

#ifndef __LIBTEMPLATE_SELECTOR_ENUM_SELECTOR_HPP__
#define __LIBTEMPLATE_SELECTOR_ENUM_SELECTOR_HPP__

#include <tuple>
#include "libtemplate/type_sequence/_.hpp"

namespace libtemplate {

template<typename... T>
class enum_selector {
public:
    typedef std::tuple<T...> tuple_type;

private:
    static_assert(!type_sequence::has_same_type<tuple_type>::value, "");

    tuple_type m_tuple;

public:
    template<typename U>
    bool is_enum(U u) const {
	return std::get<type_sequence::index_of<U, tuple_type, 0>::value>(m_tuple) == u;
    }

    template<typename U>
    U get_enum() const {
	return std::get<type_sequence::index_of<U, tuple_type, 0>::value>(m_tuple);
    }

    template<typename U>
    void set_enum(U u) {
	std::get<type_sequence::index_of<U, tuple_type, 0>::value>(m_tuple) = u;
    }
};

}
#endif	/* __LIBTEMPLATE_SELECTOR_ENUM_SELECTOR_HPP__ */

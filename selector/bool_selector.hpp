#ifndef __LIBTEMPLATE_SELECTOR_BOOL_SELECTOR_HPP__
#define __LIBTEMPLATE_SELECTOR_BOOL_SELECTOR_HPP__

#include <tuple>
#include "libtemplate/type_sequence/_.hpp"

namespace libtemplate {

template<typename... T>
class bool_selector {
private:
    typedef std::tuple<T...> tuple_type;
    static_assert(!type_sequence::has_same_type<tuple_type>::value, "");

    std::array<bool, sizeof...(T)> m_array;

public:
    template<typename U>
    bool is_true() {
	typedef type_sequence::index_of<U, tuple_type> index_type;
	return m_array[index_type::value] == true;
    }

    template<typename U>
    bool is_false() {
	typedef type_sequence::index_of<U, tuple_type> index_type;
	return m_array[index_type::value] == false;
    }

    template<typename U>
    bool get_bool() {
	typedef type_sequence::index_of<U, tuple_type> index_type;
	return m_array[index_type::value];
    }

    template<typename U>
    void set_bool(bool b) {
	typedef type_sequence::index_of<U, tuple_type> index_type;
	m_array[index_type::value] = b;
    }
};

}
#endif	/* __LIBTEMPLATE_SELECTOR_BOOL_SELECTOR_HPP__ */

#ifndef __LIBTEMPLATE_CAST_UNDERLYING_VALUE_HPP__
#define __LIBTEMPLATE_CAST_UNDERLYING_VALUE_HPP__

#include <type_traits>

namespace libtemplate {

template<typename E>
typename std::underlying_type<E>::type underlying_value(E e) {
    return static_cast<typename std::underlying_type<E>::type>(e);
}

}
#endif	/* __LIBTEMPLATE_CAST_UNDERLYING_VALUE_HPP__ */

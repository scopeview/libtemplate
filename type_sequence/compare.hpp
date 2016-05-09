#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_COMPARE_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_COMPARE_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T1, typename T2>
struct is_same_size;

template<typename... T1, typename... T2>
struct is_same_size<std::tuple<T1...>, std::tuple<T2...>> {
    enum {value = sizeof...(T1) == sizeof...(T2)};
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_COMPARE_HPP__ */

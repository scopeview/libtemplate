#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_FIND_FIRST_NOT_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_FIND_FIRST_NOT_HPP__

namespace libtemplate { namespace type_sequence {

template<typename Tuple, typename Find, size_t Skipped_Count=0>
struct find_first_not_impl;

template<typename T, typename... RestT, typename Find, size_t Skipped_Count>
struct find_first_not_impl<std::tuple<T, RestT...>, Find, Skipped_Count> {
    enum {value = !std::is_same<T, Find>::value ? Skipped_Count : find_first_not_impl<std::tuple<RestT...>, Find, Skipped_Count+1>::value};
};

template<typename T, typename Find, size_t Skipped_Count>
struct find_first_not_impl<std::tuple<T>, Find, Skipped_Count> {
    enum {value = !std::is_same<T, Find>::value ? Skipped_Count : -1};
};

////////////////////////////////////////////////////////////////

template<typename Tuple, typename Find>
struct find_first_not;

template<typename... T, typename Find>
struct find_first_not<std::tuple<T...>, Find> {
    typedef std::tuple<T...> tuple_type;
    enum {value = find_first_not_impl<tuple_type, Find, 0>::value};
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_FIND_FIRST_NOT_HPP__ */

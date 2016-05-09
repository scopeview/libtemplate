#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_FIND_IF_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_FIND_IF_HPP__

namespace libtemplate { namespace type_sequence {

template<typename Tuple, template<typename> class Predicate, size_t Skipped_Count=0>
struct find_if_impl;

template<typename T, typename... RestT, template<typename> class Predicate, size_t Skipped_Count>
struct find_if_impl<std::tuple<T, RestT...>, Predicate, Skipped_Count> {
    enum {value = Predicate<T>::value ? Skipped_Count : find_if_impl<std::tuple<RestT...>, Predicate, Skipped_Count+1>::value};
};

template<typename T, template<typename> class Predicate, size_t Skipped_Count>
struct find_if_impl<std::tuple<T>, Predicate, Skipped_Count> {
    enum {value = Predicate<T>::value ? Skipped_Count : -1};
};

////////////////////////////////////////////////////////////////

template<typename Tuple, template<typename> class Predicate>
struct find_if;

template<typename... T, template<typename> class Predicate>
struct find_if<std::tuple<T...>, Predicate> {
    typedef std::tuple<T...> tuple_type;
    enum {value = find_if_impl<tuple_type, Predicate, 0>::value};
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_FIND_IF_HPP__ */

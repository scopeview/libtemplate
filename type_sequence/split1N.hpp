#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_SPLIT1N_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_SPLIT1N_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T>
struct split1N;

template<typename T, typename... RestT>
struct split1N<std::tuple<T, RestT...>> {
    typedef std::tuple<T>		first_tuple_type;
    typedef std::tuple<RestT...>	second_tuple_type;
    typedef T			first_type;
};

template<typename T>
struct split1N<std::tuple<T>> {
    typedef std::tuple<T>		first_tuple_type;
    typedef T			first_type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_SPLIT1N_HPP__ */

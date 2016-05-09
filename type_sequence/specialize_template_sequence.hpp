#ifndef __LIBTEMPLATE_TYPE_SEQUENCE_SPECIALIZE_TEMPLATE_SEQUENCE_HPP__
#define __LIBTEMPLATE_TYPE_SEQUENCE_SPECIALIZE_TEMPLATE_SEQUENCE_HPP__

namespace libtemplate { namespace type_sequence {

template<typename T,
	 template<typename> class Template, 
	 template<typename> class... RestTemplate>
struct specialize_template_sequence {
    typedef std::tuple<Template<T>>		first_specialized_template_type;
    typedef typename specialize_template_sequence<T, RestTemplate...>::type rest_specialized_template_type;
    typedef typename concat<first_specialized_template_type, rest_specialized_template_type>::type type;
};

template<typename T, template<typename> class Template>
struct specialize_template_sequence<T, Template> {
    typedef std::tuple<Template<T>>	type;
};

}}
#endif	/* __LIBTEMPLATE_TYPE_SEQUENCE_SPECIALIZE_TEMPLATE_SEQUENCE_HPP__ */

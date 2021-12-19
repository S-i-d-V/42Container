#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft{

    //Iterators
	template <typename Iterator>
    struct iterator_traits{
        //=======//
		//Typedef//
		//=======//
        typedef typename	Iterator::difference_type           difference_type;
        typedef typename	Iterator::value_type                value_type;
        typedef typename	Iterator::pointer                   pointer;
        typedef typename	Iterator::reference                 reference;
        typedef typename	Iterator::iterator_category         iterator_category;
    };

    //Pointer
	template <typename T>
    struct iterator_traits<T*>{
        //=======//
		//Typedef//
		//=======//
        typedef	typename	std::ptrdiff_t                      difference_type;
        typedef				T                                   value_type;
        typedef				T*                                  pointer;
        typedef				T&                                  reference;
        typedef	typename	std::random_access_iterator_tag     iterator_category;
    };

	//Pointer const
	template <typename T>
    struct iterator_traits<T const*>{
        //=======//
		//Typedef//
		//=======//
        typedef	typename	std::ptrdiff_t                      difference_type;
        typedef				T                                   value_type;
        typedef				T const*                            pointer;
        typedef				T const&                            reference;
        typedef	typename	std::random_access_iterator_tag     iterator_category;
    };
 
}

#endif
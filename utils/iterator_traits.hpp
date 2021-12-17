#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft{

    //Iterators
	template <class Iterator>
    struct iterator_traits{
        //=======//
		//Typedef//
		//=======//
        typedef     Iterator::difference_type           difference_type;
        typedef     Iterator::value_type                value_type;
        typedef     Iterator::pointer                   pointer;
        typedef     Iterator::reference                 reference;
        typedef     Iterator::iterator_category         iterator_category;
    };

    //Pointer
	template <class T>
    struct iterator_traits<T*>{
        //=======//
		//Typedef//
		//=======//
        typedef     std::ptrdiff_t                      difference_type;
        typedef     T                                   value_type;
        typedef     T*                                  pointer;
        typedef     T&                                  reference;
        typedef     std::random_access_iterator_tag     iterator_category;
    };
    
    //Const pointer
	template <class T>
    struct iterator_traits<T*>{
        //=======//
		//Typedef//
		//=======//
        typedef     std::ptrdiff_t                      difference_type;
        typedef     T                                   value_type;
        typedef     T const*                                  pointer;
        typedef     T const&                                  reference;
        typedef     std::random_access_iterator_tag     iterator_category;
    };

}

#endif
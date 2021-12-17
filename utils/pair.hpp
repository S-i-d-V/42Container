#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft{

	template <class T1, class T2>
    struct pair{
        typedef     T1      first_type;
        typedef     T2      second_type;

        first_type          first;
        second_type         second;

        //Default
        pair(){
            first = 0
            second = 0;
            return;
        }

        //Copy
        template<class U,class V>
        pair(pair const<U, V>& pr){
            *this = pr;
            return;
        }

        //Initialization
        pair(first_type const& a, second_type const&b){
            first = a;
            second = b;
            return;
        }

        //Assignation operator overload
        pair& operator=(pair const& pr){
            first = pr.first;
            second = pr.second;
            return (*this);
        }
    };
}

#endif
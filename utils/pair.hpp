#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft{

	template <class T1, class T2>
    struct pair{

        //=======//
		//Typedef//
		//=======//
        typedef     T1      first_type;
        typedef     T2      second_type;

        first_type          first;
        second_type         second;

        //============//
		//Constructors//
		//============//

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

        //==================//
		//Operator overloads//
		//==================//

        //Assignation operator overload
        pair& operator=(pair const& pr){
            first = pr.first;
            second = pr.second;
            return (*this);
        }
    };

    //==============================//
	//Comparaison operator overloads//
	//==============================//

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (!(lhs == rhs));
    }
    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (lhs.first < rhs.first || (!(lhs.first < rhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (!(rhs < lhs));
    }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (!(lhs < rhs));
    }

    //===================//
	//Non-member function//
	//===================//

    template <class T1, class T2>
    pair<T1, T2>       make_pair(T1 x, T2 y){
        return (pair<T1, T2>(x,y));
    }

}

#endif
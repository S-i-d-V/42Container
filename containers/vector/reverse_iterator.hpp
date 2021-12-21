#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "../../utils/iterator_traits.hpp"

//============//
//namespace ft//
//============//
namespace ft{

	//====================//
	//reverse_iterator class//
	//====================//
	template <class Iter>
	class reverse_iterator{

		//==============//
		//Public members//
		//==============//
		public:
			//==================//
			//Typedef / typename//
			//==================//

			typedef		Iter															iterator_type;

			//Iterator traits
			typedef typename	ft::iterator_traits<Iter>::difference_type				difference_type;
			typedef	typename	ft::iterator_traits<Iter>::value_type					value_type;
			typedef typename	ft::iterator_traits<Iter>::reference					reference;
			typedef typename	ft::iterator_traits<Iter>::pointer						pointer;
			typedef	typename	ft::iterator_traits<Iter>::iterator_category			iterator_category;

			//=======================//
			//Constructors/Destructor//
			//=======================//

			//Default constructor
			reverse_iterator(): _base(){
				return;
			}

			explicit reverse_iterator(iterator_type it): _base(it){
				return;
			}

			template <class Iterator>
			reverse_iterator(reverse_iterator<Iterator> const& src){
				*this = src;
				return;
			}

			~reverse_iterator(){
				return;
			}

			//Assignement operator
			reverse_iterator &operator=(reverse_iterator const & rhs){
				_base = rhs.base();
				return (*this);
			}

			//================//
			//Member functions//
			//================//

			iterator_type base() const{
				return (_base);
			}

			//==================//
			//Operator overloads//
			//==================//

				//================//
				//Access overloads//
				//================//

			//Pointer operator
			pointer operator->(){
				iterator_type ret(_base);
				return (&(*ret));
			}

			//Dereferencement pointer operator
			reference operator*(){
				iterator_type ret(_base);
				ret--;
				return (*ret);
			}

				//=============================//
				//Increment/Decrement overloads//
				//=============================//

			//Increment operator prefixe it++;
			reverse_iterator &operator++(){
				--_base;
				return (*this);
			}

			//Increment operator postfixe ++it; 
			reverse_iterator operator++(int){
				reverse_iterator ret(*this);
				++(*this);
				return (ret);
			}

			//Increment operator prefixe it--;
			reverse_iterator &operator--(){
				++_base;
				return (*this);
			}

			//Decrement operator postfixe --it; 
			reverse_iterator operator--(int){
				reverse_iterator ret(*this);
				--(*this);
				return (ret);
			}

			//======================//
			//Assignements overloads//
			//======================//

			reverse_iterator &operator+=(difference_type n){
				_base -= n;
				return (*this);
			}

			reverse_iterator &operator-=(difference_type n){
				_base += n;
				return (*this);
			}

			reverse_iterator &operator+(difference_type n) const{
				reverse_iterator ret(*this);
				ret.base() -= n;
				return (ret);
			}

			reverse_iterator &operator-(difference_type n) const{
				reverse_iterator ret(*this);
				ret.base() += n;
				return (ret);
			}


		//==============//
		//Public members//
		//==============//
		private:
			iterator_type _base;

	}; //End of reverse_iterator class;

	//====================//
	//Non-member overloads//
	//====================//

	//Equal operator
	template<class Iterator>
	bool operator==(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs){
		if (lhs.base() == rhs.base())
			return (true);
		return (false);
	}

	//Non-equal operator
	template<class Iterator>
	bool operator!=(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs){
		if (lhs.base() != rhs.base())
			return (true);
		return (false);
	}

	//Superior or equal operator
	template<class Iterator>
	bool operator>=(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs){
		if (lhs.base() >= rhs.base())
			return (true);
		return (false);
	}

	//Inferior or equal operator
	template<class Iterator>
	bool operator<=(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs){
		if (lhs.base() <= rhs.base())
			return (true);
		return (false);
	}

	//Superior operator
	template<class Iterator>
	bool operator>(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs){
		if (lhs.base() > rhs.base())
			return (true);
		return (false);
	}

	//Inferior operator
	template<class Iterator>
	bool operator<(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs){
		if (lhs.base() < rhs.base())
			return (true);
		return (false);
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, reverse_iterator<Iterator> const &revIt){
		reverse_iterator<Iterator> ret = revIt.base() + n;
		return (ret);
	}
	
	template <class Iterator>
	reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n, reverse_iterator<Iterator> const &revIt){
		reverse_iterator<Iterator> ret = revIt.base() - n;
		return (ret);
	}

} //End of namespace ft

#endif
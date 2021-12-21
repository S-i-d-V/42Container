#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include "../../utils/iterator_traits.hpp"

//============//
//namespace ft//
//============//
namespace ft{

	//====================//
	//reverseIterator class//
	//====================//
	template <class Iter>
	class reverseIterator{

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
			reverseIterator(): _base(){
				return;
			}

			explicit reverseIterator(iterator_type it): _base(it){
				return;
			}

			template <class Iterator>
			reverseIterator(reverseIterator<Iterator> const& src){
				*this = src;
				return;
			}

			~reverseIterator(){
				return;
			}

			//Assignement operator
			reverseIterator &operator=(reverseIterator const & rhs){
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
			reverseIterator &operator++(){
				--_base;
				return (*this);
			}

			//Increment operator postfixe ++it; 
			reverseIterator operator++(int){
				reverseIterator ret(*this);
				++(*this);
				return (ret);
			}

			//Increment operator prefixe it--;
			reverseIterator &operator--(){
				++_base;
				return (*this);
			}

			//Decrement operator postfixe --it; 
			reverseIterator operator--(int){
				reverseIterator ret(*this);
				--(*this);
				return (ret);
			}

			//======================//
			//Assignements overloads//
			//======================//

			reverseIterator &operator+=(difference_type n){
				_base -= n;
				return (*this);
			}

			reverseIterator &operator-=(difference_type n){
				_base += n;
				return (*this);
			}

			reverseIterator &operator+(difference_type n) const{
				reverseIterator ret(*this);
				ret.base() -= n;
				return (ret);
			}

			reverseIterator &operator-(difference_type n) const{
				reverseIterator ret(*this);
				ret.base() += n;
				return (ret);
			}


		//==============//
		//Public members//
		//==============//
		private:
			iterator_type _base;

	}; //End of reverseIterator class;

	//====================//
	//Non-member overloads//
	//====================//

	//Equal operator
	template<class Iterator>
	bool operator==(reverseIterator<Iterator> const& lhs, reverseIterator<Iterator> const& rhs){
		if (lhs.base() == rhs.base())
			return (true);
		return (false);
	}

	//Non-equal operator
	template<class Iterator>
	bool operator!=(reverseIterator<Iterator> const& lhs, reverseIterator<Iterator> const& rhs){
		if (lhs.base() != rhs.base())
			return (true);
		return (false);
	}

	//Superior or equal operator
	template<class Iterator>
	bool operator>=(reverseIterator<Iterator> const& lhs, reverseIterator<Iterator> const& rhs){
		if (lhs.base() >= rhs.base())
			return (true);
		return (false);
	}

	//Inferior or equal operator
	template<class Iterator>
	bool operator<=(reverseIterator<Iterator> const& lhs, reverseIterator<Iterator> const& rhs){
		if (lhs.base() <= rhs.base())
			return (true);
		return (false);
	}

	//Superior operator
	template<class Iterator>
	bool operator>(reverseIterator<Iterator> const& lhs, reverseIterator<Iterator> const& rhs){
		if (lhs.base() > rhs.base())
			return (true);
		return (false);
	}

	//Inferior operator
	template<class Iterator>
	bool operator<(reverseIterator<Iterator> const& lhs, reverseIterator<Iterator> const& rhs){
		if (lhs.base() < rhs.base())
			return (true);
		return (false);
	}

	template <class Iterator>
	reverseIterator<Iterator> operator+(typename reverseIterator<Iterator>::difference_type n, reverseIterator<Iterator> const &revIt){
		reverseIterator<Iterator> ret = revIt.base() + n;
		return (ret);
	}
	
	template <class Iterator>
	reverseIterator<Iterator> operator-(typename reverseIterator<Iterator>::difference_type n, reverseIterator<Iterator> const &revIt){
		reverseIterator<Iterator> ret = revIt.base() - n;
		return (ret);
	}

} //End of namespace ft

#endif
#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

//Headers needed by iterators
#include "../../utils/iterator_traits.hpp"

/*****************************************************************************/
/*                                Namespace FT                               */
/*****************************************************************************/
namespace ft{

	/*****************************************************************************/
	/*                      Class reverse vector iterator                        */
	/*****************************************************************************/
	template <class Iter>
	class reverse_iterator{

		/*****************************************************************************/
		/*                             Public members                                */
		/*****************************************************************************/
		public:
			
			/*****************************************************************************/
			/*                              Members types                                */
			/*****************************************************************************/

			typedef		Iter															iterator_type;
			typedef typename	ft::iterator_traits<Iter>::difference_type				difference_type;
			typedef	typename	ft::iterator_traits<Iter>::value_type					value_type;
			typedef typename	ft::iterator_traits<Iter>::reference					reference;
			typedef typename	ft::iterator_traits<Iter>::pointer						pointer;
			typedef	typename	ft::iterator_traits<Iter>::iterator_category			iterator_category;

			/*****************************************************************************/
			/*                               Constructors                                */
			/*****************************************************************************/

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

			/*****************************************************************************/
			/*                                Destructors                                */
			/*****************************************************************************/

			~reverse_iterator(){
				return;
			}

			/*****************************************************************************/
			/*                             Member function                               */
			/*****************************************************************************/

			iterator_type base() const{
				return (_base);
			}

			/*****************************************************************************/
			/*                           Operators overloads                             */
			/*****************************************************************************/

			//Assignement operator
			reverse_iterator &operator=(reverse_iterator const & rhs){
				_base = rhs.base();
				return (*this);
			}

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

			reverse_iterator &operator+=(difference_type n){
				_base -= n;
				return (*this);
			}

			reverse_iterator &operator-=(difference_type n){
				_base += n;
				return (*this);
			}

			reverse_iterator operator+(difference_type n) const{
				reverse_iterator ret(*this);
				ret.base() = ret.base() - n;
				return (ret);
			}

			reverse_iterator operator-(difference_type n) const{
				reverse_iterator ret(*this);
				ret.base() = ret.base() + n;
				return (ret);
			}

		/*****************************************************************************/
		/*                            Private members                                */
		/*****************************************************************************/
		private:
			iterator_type _base;

	}; //End of reverse_iterator class;

	/*****************************************************************************/
	/*                          Comparaisons overloads                           */
	/*****************************************************************************/

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
		return (revIt + 3);
	}
	
	template <class Iterator>
	reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n, reverse_iterator<Iterator> const &revIt){
		return (revIt - 3);
	}

} //End of namespace ft

#endif//End of the header
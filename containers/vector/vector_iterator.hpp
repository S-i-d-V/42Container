#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

//============//
//namespace ft//
//============//
namespace ft{

	//====================//
	//vector_iterator class//
	//====================//
	template <class T>
	class vector_iterator{

		//==============//
		//Public members//
		//==============//
		public:
			//==================//
			//Typedef / typename//
			//==================//

			typedef typename	std::ptrdiff_t							difference_type;
			typedef				T										value_type;
			typedef 			T&										reference;
			typedef 			T*										pointer;
			typedef	typename	std::random_access_iterator_tag			iterator_category;

			//=======================//
			//Constructors/Destructor//
			//=======================//

			//Default constructor
			vector_iterator(){
				_valPtr = NULL;
				return;
			}

			vector_iterator(T *valPtr){
				_valPtr = valPtr;
				return;
			}

			vector_iterator(vector_iterator const& src){
				*this = src;
				return;
			}

			~vector_iterator(){
				return;
			}

			//==================//
			//Operator overloads//
			//==================//

				//================//
				//Access overloads//
				//================//

			//Assignement operator
			vector_iterator &operator=(vector_iterator const & rhs){
				_valPtr = rhs._valPtr;
				return (*this);
			}

			vector_iterator &operator+=(int n){
				_valPtr += n;
				return (*this);
			}

			vector_iterator &operator-=(int n){
				_valPtr -= n;
				return (*this);
			}

			//Pointer operator
			T &operator->(){
				return (_valPtr);
			}

			//Dereferencement pointer operator
			T &operator*(){
				return (*_valPtr);
			}

				//=============================//
				//Increment/Decrement overloads//
				//=============================//

			//Increment operator prefixe it++;
			vector_iterator &operator++(){
				++_valPtr;
				return (*this);
			}

			//Increment operator postfixe ++it; 
			vector_iterator operator++(T){
				vector_iterator tmp;
				tmp._valPtr = _valPtr++;
				return (tmp);
			}

			//Increment operator prefixe it--;
			vector_iterator &operator--(){
				--_valPtr;
				return (*this);
			}

			//Decrement operator postfixe --it; 
			vector_iterator operator--(T){
				vector_iterator tmp;
				tmp._valPtr = _valPtr--;
				return (tmp);
			}

				//====================//
				//Arythmetic overloads//
				//====================//

			//Addition operator
			difference_type operator+(vector_iterator const &rhs) const{
				return (_valPtr + rhs._valPtr);
			}

			//Substraction operator
			difference_type operator-(vector_iterator const &rhs) const{
				return (_valPtr - rhs._valPtr);
			}

			//Addition operator
			vector_iterator operator+(difference_type n){
				vector_iterator tmp(_valPtr + n);
				return (tmp);
			}

			//Substraction operator
			vector_iterator operator-(difference_type n){
				vector_iterator tmp(_valPtr - n);
				return (tmp);
			}

				//=====================//
				//Comparaison overloads//
				//=====================//

			//Equal operator
			bool operator==(vector_iterator const& rhs) const{
				if (_valPtr == rhs._valPtr)
					return (true);
				return (false);
			}

			//Non-equal operator
			bool operator!=(vector_iterator const& rhs) const{
				if (_valPtr != rhs._valPtr)
					return (true);
				return (false);
			}

			//Superior or equal operator
			bool operator>=(vector_iterator const& rhs) const{
				if (_valPtr >= rhs._valPtr)
					return (true);
				return (false);
			}

			//Inferior or equal operator
			bool operator<=(vector_iterator const& rhs) const{
				if (_valPtr <= rhs._valPtr)
					return (true);
				return (false);
			}

			//Superior operator
			bool operator>(vector_iterator const& rhs) const{
				if (_valPtr > rhs._valPtr)
					return (true);
				return (false);
			}

			//Inferior operator
			bool operator<(vector_iterator const& rhs) const{
				if (_valPtr < rhs._valPtr)
					return (true);
				return (false);
			}

		//==============//
		//Public members//
		//==============//
		private:
			T *_valPtr;

	}; //End of vector_iterator class;

/*
	//====================//
	//Non-member overloads//
	//====================//

	//Equal operator
	template <class T>
	bool operator==(vector_iterator<T> const& lhs, vector_iterator<T> const& rhs){
		if (*lhs == *rhs)
			return (true);
		return (false);
	}

	//Non-equal operator
	template <class T>
	bool operator!=(vector_iterator<T> const& lhs, vector_iterator<T> const& rhs){
		if (*lhs != *rhs)
			return (true);
		return (false);
	}
	
	//Superior or equal operator
	template <class T>
	bool operator>=(vector_iterator<T> const& lhs, vector_iterator<T> const& rhs){
		if (*lhs >= *rhs)
			return (true);
		return (false);
	}

	//Inferior or equal operator
	template <class T>
	bool operator<=(vector_iterator<T> const& lhs, vector_iterator<T> const& rhs){
		if (*lhs <= *rhs)
			return (true);
		return (false);
	}

	//Superior operator
	template <class T>
	bool operator>(vector_iterator<T> const& lhs, vector_iterator<T> const& rhs){
		if (*lhs > *rhs)
			return (true);
		return (false);
	}

	//Inferior operator
	template <class T>
	bool operator<(vector_iterator<T> const& lhs, vector_iterator<T> const& rhs){
		if (*lhs < *rhs)
			return (true);
		return (false);
	}
*/

} //End of namespace ft

#endif
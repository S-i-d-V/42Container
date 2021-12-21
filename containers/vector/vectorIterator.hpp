#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

//============//
//namespace ft//
//============//
namespace ft{

	//====================//
	//vectorIterator class//
	//====================//
	template <class T>
	class vectorIterator{

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
			vectorIterator(){
				_valPtr = NULL;
				return;
			}

			vectorIterator(T *valPtr){
				_valPtr = valPtr;
				return;
			}

			vectorIterator(vectorIterator const& src){
				*this = src;
				return;
			}

			~vectorIterator(){
				return;
			}

			//==================//
			//Operator overloads//
			//==================//

				//================//
				//Access overloads//
				//================//

			//Assignement operator
			vectorIterator &operator=(vectorIterator const & rhs){
				_valPtr = rhs._valPtr;
				return (*this);
			}

			vectorIterator &operator+=(int n){
				_valPtr += n;
				return (*this);
			}

			vectorIterator &operator-=(int n){
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
			vectorIterator &operator++(){
				++_valPtr;
				return (*this);
			}

			//Increment operator postfixe ++it; 
			vectorIterator operator++(T){
				vectorIterator tmp;
				tmp._valPtr = _valPtr++;
				return (tmp);
			}

			//Increment operator prefixe it--;
			vectorIterator &operator--(){
				--_valPtr;
				return (*this);
			}

			//Decrement operator postfixe --it; 
			vectorIterator operator--(T){
				vectorIterator tmp;
				tmp._valPtr = _valPtr--;
				return (tmp);
			}

				//====================//
				//Arythmetic overloads//
				//====================//

			//Addition operator
			T operator+(vectorIterator const &rhs) const{
				vectorIterator tmp(_valPtr + rhs._valPtr);
				return (tmp);
			}

			//Substraction operator
			T operator-(vectorIterator const &rhs) const{
				vectorIterator tmp(_valPtr - rhs._valPtr);
				return (tmp);
			}

				//=====================//
				//Comparaison overloads//
				//=====================//

			//Equal operator
			bool operator==(vectorIterator const& rhs) const{
				if (_valPtr == rhs._valPtr)
					return (true);
				return (false);
			}

			//Non-equal operator
			bool operator!=(vectorIterator const& rhs) const{
				if (_valPtr != rhs._valPtr)
					return (true);
				return (false);
			}

			//Superior or equal operator
			bool operator>=(vectorIterator const& rhs) const{
				if (_valPtr >= rhs._valPtr)
					return (true);
				return (false);
			}

			//Inferior or equal operator
			bool operator<=(vectorIterator const& rhs) const{
				if (_valPtr <= rhs._valPtr)
					return (true);
				return (false);
			}

			//Superior operator
			bool operator>(vectorIterator const& rhs) const{
				if (_valPtr > rhs._valPtr)
					return (true);
				return (false);
			}

			//Inferior operator
			bool operator<(vectorIterator const& rhs) const{
				if (_valPtr < rhs._valPtr)
					return (true);
				return (false);
			}

		//==============//
		//Public members//
		//==============//
		private:
			T *_valPtr;

	}; //End of vectorIterator class;

/*
	//====================//
	//Non-member overloads//
	//====================//

	//Equal operator
	template <class T>
	bool operator==(vectorIterator<T> const& lhs, vectorIterator<T> const& rhs){
		if (*lhs == *rhs)
			return (true);
		return (false);
	}

	//Non-equal operator
	template <class T>
	bool operator!=(vectorIterator<T> const& lhs, vectorIterator<T> const& rhs){
		if (*lhs != *rhs)
			return (true);
		return (false);
	}
	
	//Superior or equal operator
	template <class T>
	bool operator>=(vectorIterator<T> const& lhs, vectorIterator<T> const& rhs){
		if (*lhs >= *rhs)
			return (true);
		return (false);
	}

	//Inferior or equal operator
	template <class T>
	bool operator<=(vectorIterator<T> const& lhs, vectorIterator<T> const& rhs){
		if (*lhs <= *rhs)
			return (true);
		return (false);
	}

	//Superior operator
	template <class T>
	bool operator>(vectorIterator<T> const& lhs, vectorIterator<T> const& rhs){
		if (*lhs > *rhs)
			return (true);
		return (false);
	}

	//Inferior operator
	template <class T>
	bool operator<(vectorIterator<T> const& lhs, vectorIterator<T> const& rhs){
		if (*lhs < *rhs)
			return (true);
		return (false);
	}
*/
} //End of namespace ft

#endif
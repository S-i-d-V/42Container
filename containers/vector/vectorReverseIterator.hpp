#ifndef VECTORREVERSEITERATOR_HPP
#define VECTORREVERSEITERATOR_HPP

//============//
//namespace ft//
//============//
namespace ft{

	//====================//
	//vectorReverseIterator class//
	//====================//
	template <class T>
	class vectorReverseIterator{

		//==============//
		//Public members//
		//==============//
		public:
			//=======================//
			//Constructors/Destructor//
			//=======================//

			//Default constructor
			vectorReverseIterator(){
				_valPtr = nullptr;
				return;
			}

			vectorReverseIterator(T *valPtr){
				_valPtr = valPtr;
				return;
			}

			vectorReverseIterator(vectorReverseIterator const& src){
				*this = src;
				return;
			}

			~vectorReverseIterator(){
				return;
			}

			//==================//
			//Operator overloads//
			//==================//

				//================//
				//Access overloads//
				//================//

			//Assignement operator
			vectorReverseIterator &operator=(vectorReverseIterator const & rhs){
				_valPtr = rhs._valPtr;
				return (*this);
			}

			//Pointer operator
			T &operator->(){
				return (_valPtr);
			}

			//Dereferencement pointer operator
			T operator*(){
				return (*_valPtr);
			}

				//=============================//
				//Increment/Decrement overloads//
				//=============================//

			//Increment operator prefixe it++;
			vectorReverseIterator &operator++(){
				--_valPtr;
				return (*this);
			}

			//Increment operator postfixe ++it; 
			vectorReverseIterator operator++(T){
				vectorReverseIterator tmp;
				tmp._valPtr = _valPtr--;
				return (tmp);
			}

			//Increment operator prefixe it--;
			vectorReverseIterator &operator--(){
				++_valPtr;
				return (*this);
			}

			//Decrement operator postfixe --it; 
			vectorReverseIterator operator--(T){
				vectorReverseIterator tmp;
				tmp._valPtr = _valPtr++;
				return (tmp);
			}

				//====================//
				//Arythmetic overloads//
				//====================//

			//Addition operator
			T operator+(vectorReverseIterator const &rhs) const{
				vectorReverseIterator tmp(_valPtr - rhs._valPtr);
				return (tmp);
			}

			//Substraction operator
			T operator-(vectorReverseIterator const &rhs) const{
				vectorReverseIterator tmp(_valPtr + rhs._valPtr);
				return (tmp);
			}

				//=====================//
				//Comparaison overloads//
				//=====================//

			//Equal operator
			bool operator==(vectorReverseIterator const& rhs) const{
				if (_valPtr == rhs._valPtr)
					return (true);
				return (false);
			}

			//Non-equal operator
			bool operator!=(vectorReverseIterator const& rhs) const{
				if (_valPtr != rhs._valPtr)
					return (true);
				return (false);
			}

			//Superior or equal operator
			bool operator>=(vectorReverseIterator const& rhs) const{
				if (_valPtr >= rhs._valPtr)
					return (true);
				return (false);
			}

			//Inferior or equal operator
			bool operator<=(vectorReverseIterator const& rhs) const{
				if (_valPtr <= rhs._valPtr)
					return (true);
				return (false);
			}

			//Superior operator
			bool operator>(vectorReverseIterator const& rhs) const{
				if (_valPtr > rhs._valPtr)
					return (true);
				return (false);
			}

			//Inferior operator
			bool operator<(vectorReverseIterator const& rhs) const{
				if (_valPtr < rhs._valPtr)
					return (true);
				return (false);
			}

		//==============//
		//Public members//
		//==============//
		private:
			T *_valPtr;

	}; //End of vectorReverseIterator class;

} //End of namespace ft

#endif
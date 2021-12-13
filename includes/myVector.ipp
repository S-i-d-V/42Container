#ifndef MYVECTOR_IPP
//================================================================================//
//                                                                                //
//                             --- Utils functions ---                            //
//             --- Constructors / Destructor / Operators overload ---             //
//                                                                                //
//================================================================================//

//=======================//
//Constructors/Destructor//
//=======================//
    //Default constructor
template < typename _Tp, typename _Allocator = std::allocator<_Tp> >
ft::vector::vector<_Tp, Allocator>(allocator_type const& alloc = allocator_type()) : _alloc(alloc){
    _n = 0;
    _alloc.allocate(_n, 0);
    return;
}

    //Fill constructor
template < typename _Tp, typename _Allocator = std::allocator<_Tp> >
ft::vector::vector<_Tp, Allocator>(size_type n, value_type const& val, allocator_type const& alloc = allocator_type()) : _alloc(alloc){
    _n = n;
    _alloc.allocate(_n, 0);
    return;
}

    //Range constructor
template < typename _Tp, typename _Allocator = std::allocator<_Tp, class inputIterator> >
ft::vector::vector<_Tp, Allocator>(inputIterator first, inputIterator last, allocator_type const& alloc = allocator_type()) : _alloc(alloc){
    unsigned int i = 1;

    while (first != last){
        _alloc.allocate(i);
        _alloc.construct(_array, *first);
        _n = i;
        i++;
        first++;
    }
    return;
}

    //Copy constructor
template < typename _Tp, typename _Allocator = std::allocator<_Tp> >
ft::vector::vector<_Tp, Allocator>(vector const& src){
    this* = src;
    return;
}

    //Destructor
template < typename _Tp, typename _Allocator = std::allocator<_Tp> >
ft::vector::~vector<_Tp, Allocator>(){
    iterator    it = begin();
    iterator    ite = end();
    while (it != ite){
        destroy(it);
        it++;
    }
    _alloc.deallocate(_array, _n);
    return;
}

/*

//==================//
//Operator overloads//
//==================//
    //Assignement operator
vector&                 operator=(vector const& rhs){
    
}

	//Access operator
reference               operator[](size_type n){

}

const_reference	        operator[](size_type n) const{

}

//===========//
// Iterators //
//===========//
	//normal
iterator				begin(){

}

iterator				end(){

}

reverse_iterator		rbegin(){

}

reverse_iterator		rend(){

}

	//const
const_iterator			cbegin()	const{

}

const_iterator			cend()		const{

}

const_reverse_iterator	crbegin()	const{

}

const_reverse_iterator	crend()		const{

}

//================================================================================//
//                                                                                //
//                           --- Members functions ---                            //
//             --- Capacity, Element access, Modifier, Allocator ---              //
//                                                                                //
//================================================================================//

//==========//
// Capacity //
//==========//
	//Return the number of elements of the container
size_type				size()		const{
    return(_n);
}

	//Return max number of element the container can hold
size_type				max_size()	const{
    return (pow(2, sizeof()))
    (2^nativePointerBitWidth)/sizeof(dataType) - 1
}

	//Return the size (in elements) allocated storage capacity in the container
size_type				capacity()	const{

}

	//Return true if empty, false if not
bool					empty()		const{
    if (_n == 0)
        return (true);
    return (false);
}

	//Resize the container so that it contains n elements;
void					resize(size_type n, value_type val = value_type()){

}

	//Request that the container capacity be at least enough to contain n elements
void					reserve(size_type n){

}

	//Reduce the capacity of the container to fit its size (number of elements);
void					shrink_to_fit(){

}

//================//
// Element access //
//================//
	//Return a reference to the elements at positon n in the container
reference				at(size_type n){
    
}

const_reference			at(size_type n)	const{

}

	//Return a reference to the first elements in the container.
reference				front(){

}

const_reference			front()			const{

}

	//Return a reference to the last elements in the container.
reference				back(){

}

const_reference			back()			const{

}

	//Return a direct pointer to the array used internally by the container to store elements.
value_type*				data()			noexcept{

}

const value_type*		data()			noexcept const{

}

//==========//
// Modifier //
//==========//

	//Assign new contents to the vector by replace current content and modifying its size.
		//By range of iterators
template <class inputIterator>
void					assign(inputIterator first, inputIterator last){

}
		//Fill
void					assign(size_type n, value_type const& val){

}

	//Add a new element at the end of the container and increases the storage space only if the new size surpasses the current capacity
void					push_back(value_type const& val){

}

	//Destroy the last element in the container and reduce the size by one.
void					pop_back(value_type const& val){

}

	//Extend the container by inserting new element before the element at specified position and increase the size by the number of elements.
		//Single element
iterator				insert(iterator position, value_type const& val){

}
		//Fill
void					insert(iterator position, size_type n, value_type const& val){

}
		//By range of iterators
template <class inputIterator>
void					insert(iterator position, inputIterator first, inputIterator last){

}

	//Remove 1 or a range of elements from the container and reduce the container size by the number of elements removed.
		//Single element
iterator				erase(iterator position){

}
		//By range of iterators
iterator				erase(iterator first, iterator last){

}

	//Exchanges the content of the container by the content of src which is a container object of the same type.
void					swap(vector& x){

}

	//Remove all elements of the vector and put the size at 0
void					clear(){

}
template <class... Args>
iterator				emplace(const position, Args&&... args){

}

	//Extend the container by inserting a new element at the end right after current last element.
template <class... Args>
iterator				emplace(const position, Args&&... args){

}

//===========//
// Allocator //
//===========//
	//Return a copy of the allocator object associated with the vector;
allocator_type	get_allocator()		const{

}

*/
/*


//================================================================================//
//                                                                                //
//                      --- Non-Members functions/Utils ---                       //
//                      --- Comparaison operators, Swap ---                       //
//                                                                                //
//================================================================================//

//=======================//
// Non-members operators //
//=======================//
	//Comparaison operators
template < class T, class Alloc >
bool	operator==(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){

}

template < class T, class Alloc >
bool	operator!=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){

}

template < class T, class Alloc >
bool	operator<(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){

}

template < class T, class Alloc>
bool	operator<=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){

}

template < class T, class Alloc>
bool	operator>(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){

}

template < class T, class Alloc>
bool	operator>=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){

}

//=======================//
// Non-members functions //
//=======================//
	//Non-member swap
void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y){

}

*/

#endif
#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

template <class T, class A = std::allocator<T>>
class myVector{
    public:
    typedef A allocator_type;
    typedef typename A::value_type      value_type;
    typedef typename A::reference       reference;
    typedef typename A::const_reference const_reference;
    typedef typename A::different_type  different_type;
    typedef typename A::size_type       size_type;

    class iterator{
        public:
            typedef typename A::value_type      value_type;
            typedef typename A::reference       reference;
            typedef typename A::const_reference const_reference;
            typedef typename A::different_type  different_type;
            typedef typename A::size_type       size_type;
    }

    class const_iterator{
        public:
            typedef typename A::value_type      value_type;
            typedef typename A::reference       reference;
            typedef typename A::const_reference const_reference;
            typedef typename A::different_type  different_type;
            typedef typename A::size_type       size_type;
    }
}

#endif
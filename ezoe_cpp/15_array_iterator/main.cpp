template < typename Array >
struct array_iterator
{
	using reference = array_iterator & ;
	using const_reference = array_iterator const & ;
	using size_type = typename Array::size_type ;
	Array & a ;
	size_type i ;
	array_iterator( Array & a, size_type i )
		: a( a ), i(i) {}
	/* Compile Error
	Array::reference operator *()
	{
		return a[0] ;
	}
	*/
	// *
	typename Array::reference operator *() ;
	typename Array::reference operator [] ( size_type n ) const ;
	// ++/-- prefix
	reference operator ++() ;
	reference operator --() ;
	// ++/-- postfix
	array_iterator operator ++(int) ;
	array_iterator operator --(int) ;
	// ==/!=
	bool operator ==( const_reference right ) ;
	bool operator !=( const_reference right ) ;
	// +=/+
	reference operator +=( size_type n ) ;
	array_iterator operator +( size_type n ) const ;
	// -=/-
	reference operator -=( size_type n ) ;
	array_iterator operator -( size_type n ) const ;
	// </<=/>/>=
	bool operator <( const_reference right ) ;
	bool operator <=( const_reference right ) ;
	bool operator >( const_reference right ) ;
	bool operator >=( const_reference right ) ;
} ;

template < typename Array >
array_iterator<Array> array_iterator<Array>::operator -( size_type n ) const
{
	auto copy = *this ;
	copy -= n ;
	return copy ;
}

// *, []
template < typename Array >
typename Array::reference array_iterator<Array>::operator *()
{
	return a[i] ;
}

template < typename Array >
typename Array::reference array_iterator<Array>::operator []( size_type n ) const
{
	// This is better than 
	// return a[i+n] ;
	// if (operator *) or (operator +) are more complicated.
	return *( *this + n ) ;
}

// ++, --, ++, --
template < typename Array >
typename array_iterator<Array>::reference array_iterator<Array>::operator ++()
{
	++i ;
	return *this ;
}

template < typename Array >
typename array_iterator<Array>::reference array_iterator<Array>::operator --()
{
	--i ;
	return *this ;
}

template < typename Array >
array_iterator<Array> array_iterator<Array>::operator ++(int)
{
	array_iterator<Array> copy = *this ;
	++*this ;
	return copy ;
}

template < typename Array >
array_iterator<Array> array_iterator<Array>::operator --(int)
{
	array_iterator<Array> copy = *this ;
	--*this ;
	return copy ;
}

// ==, !=
template < typename Array >
bool array_iterator<Array>::operator ==( const_reference right )
{
	return i == right.i ;

}

template < typename Array >
bool array_iterator<Array>::operator !=( const_reference right )
{
	return i != right.i ;
}

// <, <=, >, >=
template < typename Array >
bool array_iterator<Array>::operator <( const_reference right )
{
	return i < right.i ;
}

template < typename Array >
bool array_iterator<Array>::operator <=( const_reference right )
{
	return i <= right.i ;
}

template < typename Array >
bool array_iterator<Array>::operator >( const_reference right )
{
	return i > right.i ;
}

template < typename Array >
bool array_iterator<Array>::operator >=( const_reference right )
{
	return i >= right.i ;
}

// +=, +, -=, -
template < typename Array >
typename array_iterator<Array>::reference array_iterator<Array>::operator +=( size_type n ) 
{
	i += n ;
	return *this ;
}

template < typename Array >
array_iterator<Array> array_iterator<Array>::operator +( size_type n ) const
{
	auto copy = *this ;
	copy += n ;
	return copy ;
}

template < typename Array >
typename array_iterator<Array>::reference array_iterator<Array>::operator -=( size_type n ) 
{
	i -= n ;
	return *this ;
}

template < typename T, std::size_t N >
struct array
{
	using reference = T & ;
	using const_reference = T const & ;
	using size_type = std::size_t ;
	T storage[N] ;
	using iterator = array_iterator<array> ;
	// []
	reference operator [] ( size_type i ) { return storage[i] ; }
	const_reference operator [] ( size_type i ) const { return storage[i] ; }
	// front/back
	reference front ( ) { return storage[0] ; }
	const_reference front ( ) const { return storage[0] ; }
	reference back ( ) { return storage[N-1] ; }
	const_reference back ( ) const { return storage[N-1] ; }
	// fill
	void fill( const_reference u )
	{
		for ( size_type i = 0 ; i != N ; ++i )
			storage[i] = u ;
		// This doesn't work yet
		// std::fill( begin(), end() , u ) ;
	}
	// begin/end
	iterator begin() { return iterator(*this, 0) ; }
	iterator end() { return iterator(*this, N) ; }
} ;

// T::Y 
//   where 
//     Y is dependent on template parameter(s)
//     AND
//     Y is nested type name
// Put `typename` modifier before Y
template < typename T >
void f()
{
	typename T::Y x = 0 ;
}

struct S
{
	using Y = int ;
} ;

// class name in template
template < typename A, typename B, typename C >
struct S1
{
	void f()
	{
		// S1<A, B, C> is equivalent to it
		S1 s ;
	}
} ;

// `*this` is reference to the class object which called the member function
struct S2
{
	int data {} ;
	// method chain is possible
	S2 & THIS() { return *this ; }
} ;

int	main()
{
	// T::Y and typename modifier
	{
		f<S>() ;
	}
	// 1. using iterator = array_iterator_begin<array>
	// 2. *this
	// 3. iterator(*this)
	{
	}
	{
		std::array<int, 5> a = {1,2,3,4,5} ;

		auto iter = a.begin() ;
		std::cout << *iter << "\n"s ;
		++iter ;
		std::cout << *iter << "\n"s ;
		--iter ;
		std::cout << *iter << "\n"s ;
	}
	{
		array<int, 5> a = {1,2,3,4,5} ;

		auto iter = a.begin() ;
		std::cout << "postfix\n" ;
		std::cout << *iter++ << "\n"s ;
		std::cout << *iter++ << "\n"s ;
		std::cout << *iter-- << "\n"s ;
		std::cout << *iter-- << "\n"s ;
	}
	{
		array<int, 5> a = {1,2,3,4,5} ;

		auto iter = a.begin() ;
		std::cout << "prefix\n" ;
		std::cout << *++iter << "\n"s ;
		std::cout << *++iter << "\n"s ;
		std::cout << *--iter << "\n"s ;
		std::cout << *--iter << "\n"s ;
	}
	// Now it's available in algorithms!
	{
		array<int, 5> a = {1,2,3,4,5} ;

		std::for_each( std::begin(a), std::end(a),
			[](auto x) { std::cout << x ; } ) ;
		std::cout << "\n" ;
	}
	// +=, +
	// -=, -
	{
		array<int, 5> a = {1,2,3,4,5} ;

		auto iter = a.begin() ;
		std::cout << "+=, +\n" ;
		std::cout << *(iter+=2) << "\n"s ;
		std::cout << *iter << "\n"s ;
		std::cout << *(iter+2) << "\n"s ;
		std::cout << *iter << "\n"s ;
		std::cout << "-=, -\n" ;
		std::cout << *(iter-=2) << "\n"s ;
		std::cout << *iter << "\n"s ;
		std::cout << *(iter-2) << "\n"s ;
		std::cout << *iter << "\n"s ;
	}
	// []
	{
		array<int, 5> a = {1,2,3,4,5} ;

		auto iter = a.begin() ;
		std::cout << "[]\n" ;
		std::cout << iter[0] << "\n"s ;
		std::cout << iter[1] << "\n"s ;
		std::cout << iter[2] << "\n"s ;
		std::cout << iter[3] << "\n"s ;
		std::cout << iter[4] << "\n"s ;
	}
	// <, <=, >, >=
	{
		array<int, 5> a = {1,2,3,4,5} ;

		auto i = a.begin() ;
		auto j = i + 1 ;
		std::cout << "<, <=, >, >=\n" << std::boolalpha ;
		std::cout << (i <  j) << "\n"s ;
		std::cout << (i <= j) << "\n"s ;
		std::cout << (i >  j) << "\n"s ;
		std::cout << (i >= j) << "\n"s ;
	}
}

template < typename Array >
struct array_iterator
{
	// type alias
	using iterator = array_iterator ;
	using reference = array_iterator & ;
	using const_reference = array_iterator const & ;
	using size_type = typename Array::size_type ;
	using array_reference = typename Array::reference ;

	// data member
	Array & a ;
	size_type i ;

	// member functions
	array_iterator( Array & a, std::size_t i )
		: a(a), i(i) { }

	// *
	array_reference operator *() ;
	array_reference operator [] ( size_type n ) const ;
	// ++/-- prefix
	reference operator ++() ;
	reference operator --() ;
	// ++/-- postfix
	iterator operator ++(int) ;
	iterator operator --(int) ;
	// ==/!=
	bool operator ==( const_reference right ) ;
	bool operator !=( const_reference right ) ;
	// +=/+
	reference operator +=( size_type n ) ;
	iterator operator +( size_type n ) const ;
	// -=/-
	reference operator -=( size_type n ) ;
	iterator operator -( size_type n ) const ;
	// </<=/>/>=
	bool operator <( const_reference right ) ;
	bool operator <=( const_reference right ) ;
	bool operator >( const_reference right ) ;
	bool operator >=( const_reference right ) ;
} ;

template < typename Array >
struct array_const_iterator
{
	// type alias
	using iterator = array_const_iterator ;
	using reference = array_const_iterator & ;
	using const_reference = array_const_iterator const & ;
	using size_type = typename Array::size_type ;
	using array_reference = typename Array::reference ;
	using array_const_reference = typename Array::const_reference ;

	// data member
	Array const & a ;
	size_type i ;

	// member functions
	array_const_iterator( Array const & a, size_type i )
		: a(a), i(i) { }
	array_const_iterator( const_reference iter )
		: a(iter.a), i(iter.i) { }

	// *, []
	array_const_reference operator *() const ;
	array_const_reference operator [] ( size_type n ) const ;
	// ++/-- prefix
	reference operator ++() ;
	reference operator --() ;
	// ++/-- postfix
	iterator operator ++(int) ;
	iterator operator --(int) ;
	// ==/!=
	bool operator ==( const_reference right ) ;
	bool operator !=( const_reference right ) ;
	// +=/+
	reference operator +=( size_type n ) ;
	iterator operator +( size_type n ) const ;
	// -=/-
	reference operator -=( size_type n ) ;
	iterator operator -( size_type n ) const ;
	// </<=/>/>=
	bool operator <( const_reference right ) ;
	bool operator <=( const_reference right ) ;
	bool operator >( const_reference right ) ;
	bool operator >=( const_reference right ) ;
} ;

template < typename T, std::size_t N >
struct array
{
	// typealias
	using reference = T & ;
	using const_reference = T const & ;
	using iterator = array_iterator<array> ;
	using const_iterator = array_const_iterator<array> ;
	using size_type = std::size_t ;

	T storage[N] ;

	// []
	reference operator [] ( size_type i ) { return storage[i] ; }
	const_reference operator [] ( size_type i ) const { return storage[i] ; }
	// front/back
	reference front ( ) { return storage[0] ; }
	const_reference front ( ) const { return storage[0] ; }
	reference back ( ) { return storage[N-1] ; }
	const_reference back ( ) const { return storage[N-1] ; }
	// fill
	void fill( const_reference u ) { std::fill( begin(), end() , u ) ; }
	// begin/end
	iterator begin() { return iterator(*this, 0) ; }
	iterator end() { return iterator(*this, N) ; }
	// Return const_iterator if array is const
	const_iterator begin() const { return const_iterator(*this, 0) ; }
	const_iterator end() const { return const_iterator(*this, N) ; }
	// Always return const_iterator
	const_iterator cbegin() const { return const_iterator(*this, 0) ; }
	const_iterator cend() const { return const_iterator(*this, N) ; }
} ;

/* -----------------------------------------------------------
 * array
   ----------------------------------------------------------- */

/* -----------------------------------------------------------
 * array_iterator
   ----------------------------------------------------------- */

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

template < typename Array >
array_iterator<Array> array_iterator<Array>::operator -( size_type n ) const
{
	auto copy = *this ;
	copy -= n ;
	return copy ;
}

/* -----------------------------------------------------------
 * array_const_iterator
   ----------------------------------------------------------- */

template < typename Array >
typename Array::const_reference array_const_iterator<Array>::operator *() const
{
	return a[i] ;
}

template < typename Array >
typename Array::const_reference array_const_iterator<Array>::operator []( size_type n ) const
{
	// This is better than 
	// return a[i+n] ;
	// if (operator *) or (operator +) are more complicated.
	return *( *this + n ) ;
}

// ++, --, ++, --
template < typename Array >
typename array_const_iterator<Array>::reference array_const_iterator<Array>::operator ++()
{
	++i ;
	return *this ;
}

template < typename Array >
typename array_const_iterator<Array>::reference array_const_iterator<Array>::operator --()
{
	--i ;
	return *this ;
}

template < typename Array >
array_const_iterator<Array> array_const_iterator<Array>::operator ++(int)
{
	array_const_iterator<Array> copy = *this ;
	++*this ;
	return copy ;
}

template < typename Array >
array_const_iterator<Array> array_const_iterator<Array>::operator --(int)
{
	array_const_iterator<Array> copy = *this ;
	--*this ;
	return copy ;
}

// ==, !=
template < typename Array >
bool array_const_iterator<Array>::operator ==( const_reference right )
{
	return i == right.i ;

}

template < typename Array >
bool array_const_iterator<Array>::operator !=( const_reference right )
{
	return i != right.i ;
}

// <, <=, >, >=
template < typename Array >
bool array_const_iterator<Array>::operator <( const_reference right )
{
	return i < right.i ;
}

template < typename Array >
bool array_const_iterator<Array>::operator <=( const_reference right )
{
	return i <= right.i ;
}

template < typename Array >
bool array_const_iterator<Array>::operator >( const_reference right )
{
	return i > right.i ;
}

template < typename Array >
bool array_const_iterator<Array>::operator >=( const_reference right )
{
	return i >= right.i ;
}

// +=, +, -=, -
template < typename Array >
typename array_const_iterator<Array>::reference array_const_iterator<Array>::operator +=( size_type n ) 
{
	i += n ;
	return *this ;
}

template < typename Array >
array_const_iterator<Array> array_const_iterator<Array>::operator +( size_type n ) const
{
	auto copy = *this ;
	copy += n ;
	return copy ;
}

template < typename Array >
typename array_const_iterator<Array>::reference array_const_iterator<Array>::operator -=( size_type n ) 
{
	i -= n ;
	return *this ;
}

template < typename Array >
array_const_iterator<Array> array_const_iterator<Array>::operator -( size_type n ) const
{
	auto copy = *this ;
	copy -= n ;
	return copy ;
}

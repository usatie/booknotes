template < typename Array >
struct array_iterator
{
	Array & a ;
	std::size_t i ;

	array_iterator( Array & a, std::size_t i )
		: a(a), i(i) { }
} ;

template < typename Array >
struct array_const_iterator
{
	Array const & a ;
	std::size_t i ;

	array_const_iterator( Array const & a, std::size_t i )
		: a(a), i(i) { }
	array_const_iterator( array_iterator<Array> const & iter )
		: a(iter.a), i(iter.i) { }
} ;

template < typename T, std::size_t N >
struct array
{
	using iterator = array_iterator<array> ;
	using const_iterator = array_const_iterator<array> ;

	// Return const_iterator if array is const
	const_iterator begin() const { return const_iterator(*this, 0) ; }
	const_iterator end() const { return const_iterator(*this, N) ; }
	// Always return const_iterator
	const_iterator cbegin() const { return const_iterator(*this, 0) ; }
	const_iterator cend() const { return const_iterator(*this, N) ; }
} ;

int main()
{
}

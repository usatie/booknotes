// Implement array::at
template < typename T, std::size_t N >
struct array
{
	using reference = T & ;
	using size_type = std::size_t ;

	T storage[N] ;

	size_type size() const { return N ; }
	reference at( size_type n )
	{
		if ( n >= size() )
			throw std::out_of_range("Error: Out of Range") ;
		return storage[n] ;
	}
} ;

int	main()
{
	// Throw an error
	{
		std::cout << "Don't type 0. >"s ;

		int input {} ;
		std::cin >> input ;
		
		if ( input == 0 )
			throw 0 ;

		std::cout << "Success!\n"s ;
	}
	// std::out_of_range
	{
		std::out_of_range err("I am an error.") ;

		std::cout << err.what() ;
	}
	// Throw an error
	{
		while (1)
		{
			std::cout << "Enter Index between 0 to 4. >"s ;

			int i {} ;
			std::cin >> i ;
			
			array<int, 5> a = {1,2,3,4,5} ;
			a.at(i) ;
		}
	}
}

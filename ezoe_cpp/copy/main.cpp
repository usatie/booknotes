int	main()
{
	{
		std::vector<int> v = {1} ;
		auto i = std::begin(v) ;
		std::cout << *i << "\n"s ;
		*i = 2 ;
	}
	// copy
	{
		std::vector<int> source = {1,2,3,4,5} ;
		std::vector<int> destination(5) ;

		std::copy( std::begin(source), std::end(source), std::begin(destination) ) ;

		for ( auto i = std::begin(destination) ; i != std::end(destination) ; ++i )
			std::cout << *i << "\n"s ;
	}
	// std::copy returns value
	// dst.begin() + distance(first, last)
	{
		std::vector<int> source = {1,2,3,4,5} ;
		std::vector<int> destination(5) ;
		auto first = std::begin(source) ;
		auto last = std::end(source) ;
		auto result = std::begin(destination) ;

		auto returned = std::copy( std::begin(source), std::end(source), std::begin(destination) ) ;
		bool b = ( returned == (result + (last - first)) ) ;
		std::cout << "b: "s << b << "\n"s ;
	}
	// overlap is not allowed. The result is undefined.
	{
		std::vector<int> v = {1,2,3} ;
		std::copy( std::begin(v), std::end(v), std::begin(v) ) ;
	}
	// Implement std::copy
	// like memcpy() in c
	// Do we have memmove in cpp?
	{
		auto copy = []( auto first, auto last, auto result )
		{
			for ( auto iter = first ; iter != last ; ++iter, ++result )
			{ *result = *iter }
		}
		return result ;
	}
}

int	main()
{
	auto print_vec = []( auto v )
	{
		std::cout << "["s ;
		for ( auto i = std::begin(v) ;  i != std::end(v) ; ++i )
		{
			std::cout << *i << ", "s ;
		}
		std::cout << "]\n"s ;
	} ;
	// fill
	{
		std::vector<int> v = {1,2,3,4,5} ;
		print_vec(v) ;
		std::fill( std::begin(v), std::end(v), 0 ) ;
		print_vec(v) ;
	}
	// fill_n
	{
		std::vector<int> v = {1,2,3,4,5} ;
		print_vec(v) ;
		std::fill_n( std::begin(v), 5, 0 ) ;
		print_vec(v) ;
	}
	// Implement fill and fill_n
	{
		auto fill = []( auto first, auto last, auto value )
		{
			for ( auto i = first ; i != last ; ++i )
				*i = value ;
		} ;
		auto fill_n = [&]( auto first, auto n, auto value )
		{
			return fill(first, first + n, value) ;
		} ;
		// fill
		{
			std::vector<int> v = {1,2,3,4,5} ;
			print_vec(v) ;
			fill( std::begin(v), std::end(v), 0 ) ;
			print_vec(v) ;
		}
		// fill_n
		{
			std::vector<int> v = {1,2,3,4,5} ;
			print_vec(v) ;
			fill_n( std::begin(v), 5, 0 ) ;
			print_vec(v) ;
		}
	}
}

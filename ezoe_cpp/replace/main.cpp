int	main()
{
	auto print_vec = []( auto v )
	{
		std::cout << "["s ;
		for ( auto i = std::begin(v) ; i != std::end(v) ; ++i )
		{
			std::cout << *i << ", "s ;
		}
		std::cout << "]\n"s ;
	} ;
	// replace
	{
		std::vector<int> a = {1,2,3,3,4,5,3,4,5} ;
		print_vec(a) ;
		std::replace( std::begin(a), std::end(a), 3, 0 ) ;
		print_vec(a) ;
	}
	// Implement std::replace
	{
		auto replace = []( auto first, auto last, auto old_value, auto new_value )
		{
			for ( auto iter = first ; iter != last ; ++iter )
			{
				if ( *iter == old_value )
					*iter = new_value ;
			}
		} ;

		std::vector<int> a = {1,2,3,3,4,5,3,4,5} ;
		print_vec(a) ;
		replace( std::begin(a), std::end(a), 3, 0 ) ;
		print_vec(a) ;
	}
}

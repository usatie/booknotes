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
	// remove
	{
		std::vector<int> v = {1,2,3} ;

		auto last = std::remove( std::begin(v), std::end(v), 2 ) ;
		std::for_each( std::begin(v), last,
			[](auto x) { std::cout << x ; } ) ;
		std::cout << "\n"s ;

		std::vector<int> w = {1,2,2,3,2,2,4} ;
		auto last2 = std::remove( std::begin(w), std::end(w), 2 ) ;
		std::for_each( std::begin(w), last2,
			[](auto x) { std::cout << x ; } ) ;
		std::cout << "\n"s ;
	}
	// remove_if
	{
		auto is_even = []( auto x ) { return x%2 == 0 ; } ;
		std::vector v = { 1,2,3,4,5,6,7,8,9 } ;
		auto last = std::remove_if( std::begin(v), std::end(v), is_even ) ;
		std::for_each( std::begin(v), last,
			[](auto x) { std::cout << x ; } ) ;
		std::cout << "\n"s ;
	}
	// Implement remove_if ( incomplete )
	{
		auto remove_if = []( auto first, auto last, auto pred )
		{
			auto removing = std::find_if( first, last, pred ) ;
			if ( removing == last )
				return last ;
			auto remaining = removing ;
			++remaining ;
			for ( ; remaining != last ; ++remaining )
			{
				if ( pred( *remaining ) == false )
				{
					*removing = *remaining ;
					++removing ;
				}
			}
			return removing ;
		} ;
		// remove_if
		{
			auto is_even = []( auto x ) { return x%2 == 0 ; } ;
			std::vector v = { 1,2,3,4,5,6,7,8,9 } ;
			auto last = remove_if( std::begin(v), std::end(v), is_even ) ;
			std::for_each( std::begin(v), last,
				[](auto x) { std::cout << x ; } ) ;
			std::cout << "\n"s ;
		}
	}
}

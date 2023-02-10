auto for_each = []( auto first, auto last, auto f )
{
	for ( auto iter = first ; iter != last ; ++iter )
	{
		// if f takes referencd as an argument, f can change it.
		f( *iter ) ;
	}
} ;

int	main()
{
	// for_each
	{
		std::vector<int> v = {1,2,3,4,5} ;

		auto print_value = []( auto value ) { std::cout << value ; } ;
		auto print_twice = []( auto value ) { std::cout << 2 * value ; } ;
		auto print_with_newline = []( auto value ) { std::cout << value << "\n"s ; } ;
		for_each( std::begin(v), std::end(v), print_value ) ;
		for_each( std::begin(v), std::end(v), print_twice ) ;
		for_each( std::begin(v), std::end(v), print_with_newline ) ;
	}
	// Without variables
	{
		std::vector<int> v = {1,2,3,4,5} ;

		for_each( std::begin(v), std::end(v),
			[]( auto value ) { std::cout << value ; } ) ;
		for_each( std::begin(v), std::end(v),
			[]( auto value ) { std::cout << 2 * value ; } ) ;
		for_each( std::begin(v), std::end(v),
			[]( auto value ) { std::cout << value << "\n"s ; } ) ;
	}
	// std::for_each
	{
		std::vector<int> v = {1,2,3,4,5} ;

		std::for_each( std::begin(v), std::end(v),
			[]( auto value ) { std::cout << value ; } ) ;
		std::for_each( std::begin(v), std::end(v),
			[]( auto value ) { std::cout << 2 * value ; } ) ;
		std::for_each( std::begin(v), std::end(v),
			[]( auto value ) { std::cout << value << "\n"s ; } ) ;
	}
	// c++20
	/*
	{
		std::vector<int> v = {1,2,3,4,5} ;

		std::for_each( v, []( auto value ) { std::cout << value ; } ) ;
		std::for_each( v, []( auto value ) { std::cout << 2 * value ; } ) ;
		std::for_each( v, []( auto value ) { std::cout << value << "\n"s ; } ) ;
	}
	*/
	// for_each reference
	{
		std::vector<int> v = {1,2,3,4,5} ;

		auto twice = [](auto & value){ value = 2 * value ; } ;
		auto print = [](auto & value){ std::cout << value << ", " ; } ;

		std::for_each( std::begin(v), std::end(v), twice) ;
		std::for_each( std::begin(v), std::end(v), print) ;
	}
}

auto all_of = []( auto first, auto last, auto pred )
{
	for ( auto iter = first ; iter != last ; ++iter )
	{
		if ( pred( *iter ) == false )
			return false ;
	}
	return true ;
} ;

auto any_of = []( auto first, auto last, auto pred )
{
	for ( auto iter = first ; iter != last ; ++iter )
	{
		if ( pred( *iter ) )
			return true ;
	}
	return false ;
} ;

auto none_of = []( auto first, auto last, auto pred )
{
	for ( auto iter = first ; iter != last ; ++iter )
	{
		if ( pred( *iter ) )
			return false ;
	}
	return true ;
} ;

auto find = []( auto first, auto last, auto const & value )
{
	for ( auto iter = first ; iter != last; ++iter )
	{
		if ( *iter == value )
			return iter ;
	}
	return last ;
} ;

auto find_if = []( auto first, auto last, auto pred )
{
	for ( auto iter = first ; iter != last ; ++iter )
	{
		if ( pred( *iter ) )
			return iter ;
	}
	return last ;
} ;

int	main()
{
	// all_of
	{
		auto is_all_of_even = []( auto first, auto last )
		{
			return all_of( first, last,
				[]( auto value ) { return value % 2 == 0 ; } ) ;
		} ;

		auto is_all_of_le_100 = []( auto first, auto last )
		{
			return all_of( first, last,
				[]( auto value ) { return value <= 100 ; } ) ;
		} ;

		// Usage
		{
			std::vector<int> v1 = {1,2,3,4,5} ;
			std::vector<int> v2 = {1,3,5,101,103} ;
			std::vector<int> v3 = {2,4,6,102,104} ;

			std::cout << std::boolalpha << is_all_of_even(std::begin(v1), std::end(v1)) << "\n"s ;
			std::cout << std::boolalpha << is_all_of_le_100(std::begin(v1), std::end(v1)) << "\n"s ;
			std::cout << std::boolalpha << is_all_of_even(std::begin(v2), std::end(v2)) << "\n"s ;
			std::cout << std::boolalpha << is_all_of_le_100(std::begin(v2), std::end(v2)) << "\n"s ;
			std::cout << std::boolalpha << is_all_of_even(std::begin(v3), std::end(v3)) << "\n"s ;
			std::cout << std::boolalpha << is_all_of_le_100(std::begin(v3), std::end(v3)) << "\n"s ;
		}
		// Empty
		{
			std::vector<int> v = {} ;
			std::cout << std::boolalpha << is_all_of_even(std::begin(v), std::end(v)) << "\n"s ;
			std::cout << std::boolalpha << is_all_of_le_100(std::begin(v), std::end(v)) << "\n"s ;
		}
	}
	// any_of
	{
		std::vector<int> v = {1,2,3,4,5} ;
		bool has_3 = std::any_of( std::begin(v), std::end(v),
			[]( auto x ) { return x == 3 ; } ) ;
		bool has_10 = std::any_of( std::begin(v), std::end(v),
			[]( auto x ) { return x == 10 ; } ) ;
		std::cout << "any_of:"s << "\n"s ;
		std::cout << has_3 << "\n"s ;
		std::cout << has_10 << "\n"s ;
	}
	// none_of
	{
		std::vector<int> v = {1,2,3,4,5} ;
		auto is_100 = []( auto x ) { return x == 100 ; } ;
		bool b = std::none_of( std::begin(v), std::end(v), is_100 ) ;
		bool c = none_of( std::begin(v), std::end(v), is_100 ) ;
		std::cout << "none_of:"s << "\n"s ;
		std::cout << b << "\n"s ;
		std::cout << c << "\n"s ;
	}
	// find / find_if
	{
		std::vector<int> v = {1,2,3,4,5} ;
		
		auto pos = std::find( std::begin(v), std::end(v), 3 ) ;
		std::cout << *pos << "\n"s ;
	}
	// If not found, returns last
	{
		std::vector<int> v = {1,2,3,4,5} ;
		
		auto pos = std::find( std::begin(v), std::end(v), 0 ) ;
		if ( pos != std::end(v) )
			std::cout << "Found.\n"s ;
		else
			std::cout << "Not Found.\n"s ;
	}
	// find_if
	{
		auto pred = []( auto const & value ) -> bool
		{
			return true ;
		} ;
		std::vector<int> v = {1,2,3,4,5} ;

		auto is_even = []( auto value )
		{
			return value % 2 == 0 ;
		} ;
		auto is_odd = []( auto value )
		{
			return value % 2 == 1 ;
		} ;

		auto even = std::find_if( std::begin(v), std::end(v), is_even ) ;
		auto odd = std::find_if( std::begin(v), std::end(v), is_odd ) ;
		std::cout << "fist even: " << *even << "\n"s ;
		std::cout << "fist odd: " << *odd << "\n"s ;
	}
	// find is a special case of find_if
	{
		std::vector<int> v = {1,2,3,4,5} ;

		auto is_3 = []( auto x ) { return x == 3 ; } ;
		auto i = std::find_if( std::begin(v), std::end(v), is_3 ) ;
		auto j = std::find( std::begin(v), std::end(v), 3 ) ;
		std::cout << "i == j: " << (i == j) << "\n"s ;
	}
	// [=]{} to use outer variable by copy
	{
		int value = 123 ;
		auto f = [=]{ return value ; } ;

		std::cout << f() << "\n"s ;
		value = 124 ;
		std::cout << f() << "\n"s ;
	}
	// [&]{} to use outer variable by reference
	{
		int value = 123 ;
		auto f = [&]{ ++value ; } ;

		std::cout << value << "\n"s ;
		f() ;
		std::cout << value << "\n"s ;
		f() ;
		std::cout << value << "\n"s ;
	}
	// Implement find by find_if
	{
		// 本当のfindと同じようにauto const & valueじゃなくていいのか？
		auto find = []( auto first, auto last, auto value )
		{
			return std::find_if( first, last,
				[&]( auto elem ) { return value == elem ; } ) ;
		} ;
		auto find2 = []( auto first, auto last, auto const & value )
		{
			return std::find_if( first, last,
				[&]( auto elem ) { return value == elem ; } ) ;
		} ;
		std::vector<int> v = {1,2,3,4,5} ;
		
		{
			auto pos = std::find( std::begin(v), std::end(v), 3 ) ;
			std::cout << *pos << "\n"s ;
		}
		{
			auto pos = find( std::begin(v), std::end(v), 3 ) ;
			std::cout << *pos << "\n"s ;
		}
		{
			auto pos = find2( std::begin(v), std::end(v), 3 ) ;
			std::cout << *pos << "\n"s ;
		}
	}
	// count / count_if
	{
		std::vector<int> v = {1,2,1,1,3,3} ;

		auto a = std::count( std::begin(v), std::end(v), 1 ) ;
		auto b = std::count( std::begin(v), std::end(v), 2 ) ;
		auto c = std::count( std::begin(v), std::end(v), 3 ) ;
		std::cout << "a: "s << a << "\n"s ;
		std::cout << "b: "s << b << "\n"s ;
		std::cout << "c: "s << c << "\n"s ;
	}
	{
		auto count = []( auto first, auto last, auto value )
		{
			auto counter = 0u ;
			for ( auto i = first ; i != last ; ++i )
			{
				if ( *i == value )
					++counter ;
			}
			return counter ;
		} ;
		std::vector<int> v = {1,2,1,1,3,3} ;

		auto a = count( std::begin(v), std::end(v), 1 ) ;
		auto b = count( std::begin(v), std::end(v), 2 ) ;
		auto c = count( std::begin(v), std::end(v), 3 ) ;
		std::cout << "a: "s << a << "\n"s ;
		std::cout << "b: "s << b << "\n"s ;
		std::cout << "c: "s << c << "\n"s ;
	}
	{
		auto count_if = []( auto first, auto last, auto pred )
		{
			auto counter = 0u ;
			for ( auto i = first; i != last ; ++i )
			{
				if ( pred(*i) != false )
					++counter ;
			}
			return counter ;
		} ;
		auto count = []( auto first, auto last, auto value )
		{
			return std::count_if( first, last,
				[=]( auto elem ) { return value == elem ; } ) ;
		} ;
		std::vector<int> v = {1,2,1,1,3,3} ;
		auto a = count( std::begin(v), std::end(v), 1 ) ;
		auto b = count( std::begin(v), std::end(v), 2 ) ;
		auto c = count( std::begin(v), std::end(v), 3 ) ;
		std::cout << "a: "s << a << "\n"s ;
		std::cout << "b: "s << b << "\n"s ;
		std::cout << "c: "s << c << "\n"s ;
	}
}

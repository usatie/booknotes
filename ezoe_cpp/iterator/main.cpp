int	main()
{
	// vector.at()
	{
		std::vector<int> v = {1,2,3,4,5} ;

		int x = v.at( 2 ) ;
		std::cout << "x: "s << x << "\n"s ;
		v.at( 2 ) = 0 ;
		std::cout << "v.at(2): "s << v.at(2) << "\n"s ;
	}
	// Dereference Iterator
	{
		std::vector<int> v = {1,2,3,4,5} ;
		auto i = std::begin( v ) ; // iterator

		int x = *i ; // dereference iterator as rvalue
		*i = 0 ; // dereference iterator as lvalue
	}
	// Increment/Decrement Reference of Iterator
	{
		std::vector<int> v = {1,2,3,4,5} ;
		auto i = std::begin( v ) ; // iterator

		std::cout << "Iterate Iterator\n"s ;
		std::cout << *i << "\n"s ;
		++i ;
		std::cout << *i << "\n"s ;
		++i ;
		std::cout << *i << "\n"s ;
		--i ;
		std::cout << *i << "\n"s ;
		--i ;
		std::cout << *i << "\n"s ;
	}
	// Iterate over vector using iterator
	{
		std::vector<int> v = {1,2,3,4,5} ;
		auto iter = std::begin( v ) ;

		std::cout << "Iterate over vector using iterator\n"s ;
		for ( std::size_t i = 0 ; i != std::size(v) ; ++i, ++iter )
		{
			std::cout << *iter << "\n"s ;
		}
	}
	// Compare Iterator
	{
		std::vector<int> v = {1,2,3,4,5} ;
		auto x = std::begin(v) ;
		auto y = x ;

		bool b1 = ( x == y ) ;
		bool b2 = ( x != y ) ;
		++x ;
		bool b3 = ( x == y ) ;
		bool b4 = ( x != y ) ;
		std::cout
			<< std::boolalpha
			<< "b1: "s << b1 << "\n"s
			<< "b2: "s << b2 << "\n"s
			<< "b3: "s << b3 << "\n"s
			<< "b4: "s << b4 << "\n"s ;
	}
	// vector.end()
	{
		std::vector<int> v = { 1,2,3,4,5 } ;
		auto i = std::end( v ) ; // The next of the last

		*i ; // errorのはずでは・・・？
		std::cout << *i << "\n"s ;
		++i ;
		std::cout << *i << "\n"s ;
		std::cout << "hello\n"s ;
	}
	// Iterate over v using begin and end
	{
		std::vector<int> v = {1,2,3,4,5} ;

		for ( auto iter = std::begin(v), last = std::end(v) ; iter != last ; ++iter )
		{
			std::cout << *iter << "\n"s ;
		}
	}
}

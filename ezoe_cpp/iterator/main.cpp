int	main()
{
	// [i, j)
	// half-closed
	{
		std::vector<int> v = {1,2,3,4,5} ;
		
		auto i = std::begin(v) ;
		auto j = std::end(v) ;
	}
	// "Why numbering should start at zero"(EWD831)
	// by Edsger Wybe Dijkstra
	//
	// a) 2 <= i <  6
	// b) 1 <  i <= 5
	// c) 2 <= i <= 5
	// d) 1 <  i <  6
	//
	// Iterator is based on a).
	// In c++, many is based on a).
	// If b), for loop may looks like this
	{
		std::vector<int> v = {1,2,3,4,5} ;
		auto i = std::begin ( v ) ;
		auto j = std::end ( v ) ;

		++i ;
		for ( ; i != j ; ++i )
			std::cout << *i ;
		std::cout << *i ;
	}
	// If a), for loop may looks like this
	{
		std::vector<int> v = {1,2,3,4,5} ;
		auto i = std::begin ( v ) ;
		auto j = std::end ( v ) ;

		for ( ; i != j ; ++i )
			std::cout << *i ;
	}
}

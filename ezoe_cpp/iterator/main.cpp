auto output_all = []( auto first, auto last )
{
	for ( auto iter = first ; iter != last ; ++iter )
	{
		std::cout << *iter << "\n"s ;
	}
} ;

auto output_all2 = []( auto first, auto last, auto output_iter )
{
	for ( auto iter = first ; iter != last ; ++iter )
	{
		*output_iter = *iter ;
	}
} ;

int	main()
{
	// Vector
	{
		std::vector<int> v = {1,2,3,4,5} ;

		output_all( std::begin(v), std::end(v) ) ;
	}
	// Standard Input Stream
	{
		// last is not initialized, ok?
		std::istream_iterator<int> first( std::cin ), last ;
		output_all( first, last ) ;
	}
	// Directory Iterator
	/* Unexpectedly got Runtime Error
	{
	    std::filesystem::directory_iterator first("./"), last ;

   		 output_all( first, last ) ;
	}
	*/
	// Output to std::cout
	{
		std::vector<int> v = {1,2,3,4,5} ;

		output_all2( std::begin(v), std::end(v),
					std::ostream_iterator<int>(std::cout) ) ;
	}
	// Ouput to Vector ( copy vector )
	{
		std::vector<int> source = {1,2,3,4,5} ;
		std::vector<int> destination(5) ;
		
		output_all2( std::begin(source), std::end(source),
					std::begin(destination) ) ;
	}
	// directory iterator ( sample code )
	{
		std::filesystem::directory_iterator first("./"), last ;

		for ( auto x = first; x != last; ++x )
			std::cout << x->path() << std::endl ;
	}
}

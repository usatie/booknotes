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
	// generate
	{
		std::vector<int> v = {1,2,3,4,5} ;
		auto gen_zero = [](){ return 0 ; } ;
		std::generate( std::begin(v), std::end(v), gen_zero ) ;
		print_vec(v) ;
	}
	// generate_n
	{
		std::vector<int> v = {1,2,3,4,5} ;
		auto gen_zero = [](){ return 0 ; } ;
		std::generate_n( std::begin(v), 3, gen_zero ) ;
		print_vec(v) ;
	}
	// Implement generate
	{
		auto generate = []( auto first, auto last, auto gen )
		{
			for ( auto iter = first ; iter != last ; ++iter )
			{
				*iter = gen() ;
			}
		} ;
		auto generate_n = []( auto first, auto n, auto gen )
		{
			for ( auto i = 0 ; i != n ; ++i, ++first )
			{
				*first = gen() ;
			}
		} ;
		// generate
		{
			std::vector<int> v = {1,2,3,4,5} ;
			auto gen_zero = [](){ return 0 ; } ;
			generate( std::begin(v), std::end(v), gen_zero ) ;
			print_vec(v) ;
		}
		// generate_n
		{
			std::vector<int> v = {1,2,3,4,5} ;
			auto gen_zero = [](){ return 0 ; } ;
			generate_n( std::begin(v), 3, gen_zero ) ;
			print_vec(v) ;
		}
	}
}

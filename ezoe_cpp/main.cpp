int	main()
{
	// Short-circuit evaluation
	// Minimal evaluation
	{
		auto a = []()
		{
			std::cout << "a\n"s ;
			return false ;
		} ;
		auto b = []()
		{
			std::cout << "b\n"s ;
			return true ;
		} ;
		
		bool c = a() && b() ;
		std::cout << std::boolalpha << c << "\n"s ;
	}
	// Boolean Conversions
	{
		std::cout << std::boolalpha ;

		bool b = true < false ;
		std::cout << b << "\n"s ;

		auto print = [](auto x)
		{ std::cout << x << "\n"s ; } ;

		print( true  + true  ) ;
		print( true  + false ) ;
		print( false + true  ) ;
		print( false + false ) ;
	}
	{
		auto print = [](auto x)
		{ std::cout << x << "\n"s ; } ;

		bool Zero = 0 ;
		bool One = 1 ;
		bool minus_one = -1 ;
		bool OneTwoThree = 123 ;

		print( Zero ) ;
		print( One ) ;
		print( minus_one ) ;
		print( OneTwoThree ) ;
	}
}

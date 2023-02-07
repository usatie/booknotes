int	main()
{
	// unused variable 
	{
		auto x = 1 ;
		auto y = 2 ;
		
		std::cout << x + x << "\n"s ;
	}
	// assignment used as truth value
	{
		auto x = 0 ;

		if ( x = 123 )
			std::cout << "x is 123.\n"s ;
		else
			std::cout << "x is NOT 123.\n"s ;
	}
	{
		auto x = 0 ;

		bool b1 = x = 1 ;
		if ( x = 1 ) std::cout << "true assignment\n"s ;

		bool b0 = x = 0 ;
		if ( x = 0 ) std::cout << "false assignment\n"s ;
	}
	// no warning
	{
		auto x = 0 ;

		if ( ( x = 0 ) )
			std::cout << "TRUE!.\n"s ;
		else
			std::cout << "FALSE!.\n"s ;
	}
}

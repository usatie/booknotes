bool is_rocket_ready_to_launch()
{
	return false;
}

int	main()
{
	// expression statement
	{
		1 + 1 ;
		1 == 1 ;
		1 < 2 ;
	}

	// expression
	{
		auto a = 123 ;
		auto b = a + 4 ;
		auto c = 1.0 ;
		auto d = "hello"s ;
	}

	// conditoin expression
	{
		if ( 1 == 1 )
		{ std::cout << "1 == 1 is true.\n"s ; }
		else
		{ std::cout << "1 == 1 is false.\n"s ; }

		auto x = 1 == 1 ;
		if ( x )
		{ std::cout << "1 == 1 is true.\n"s ; }
		else
		{ std::cout << "1 == 1 is false.\n"s ; }

		auto a = 1 == 1 ;
		auto b = 1 != 1 ;
		std::cout << a << "\n"s << b ;
	}
	// expression
	{
		if ( 1 ) std::cout << "1\n"s ;
		if ( 0 ) std::cout << "0\n"s ;
		if ( 123 ) std::cout << "123\n"s ;
		if ( -1 ) std::cout << "-1\n"s ;
	}
	// bool
	{
		auto a = 1 == 1 ;
		bool A = 1 == 1 ;
		bool correct = true ;
		bool wrong = false ;

		// after this, boolean value is printed as true/false
		std::cout << std::boolalpha ;
	   	std::cout << true << "\n"s << false << "\n"s ;
		// after this, boolean value is printed as 1/0
		std::cout << std::noboolalpha ;
	   	std::cout << true << "\n"s << false << "\n"s ;
	}
	{
		bool a = 1 == 1 ;
		bool b = 1 != 1 ;
		bool c = 1 < 2 ;
		bool d = 1 > 2 ;

		if ( true )
			std::cout << "true\n"s ;
		if ( false )
			std::cout << "false\n"s ;
	}
	{
		std::cout << "operator!\n"s ;
		std::cout << std::boolalpha ;
		std::cout << !true << "\n"s ;
		std::cout << !false << "\n"s ;
		
		if ( !is_rocket_ready_to_launch() )
		{
			std::cout << "Standby...\n" ;
		}
	}
	{
		std::cout << std::boolalpha ;
		auto print = [](auto b)
		{ std::cout << b << "\n"s ; } ;
		
		print( true  == true  ) ;
		print( true  == false ) ;
		print( false == true  ) ;
		print( false == false ) ;
		
		print( true  != true  ) ;
		print( true  != false ) ;
		print( false != true  ) ;
		print( false != false ) ;
		
		bool b = ( 1 < 2 ) == true ;

		print( true  && true  ) ;
		print( true  && false ) ;
		print( false && true  ) ;
		print( false && false ) ;

		print( true  || true  ) ;
		print( true  || false ) ;
		print( false || true  ) ;
		print( false || false ) ;
	}
	{
		double temperature = 36.6 ;

		if ( ( temperature >= 36.1 ) && ( temperature <= 37.2 ) )
		{ std::cout << "Good.\n"s ; }
		else
		{ std::cout << "Bad.\n"s ; }
	}
	{
		double height = 1.3 ;

		if ( ( height < 1.1 ) && ( height > 1.9 ) )
		{ std::cout << "No.\n"s ; }
		else
		{ std::cout << "Yes.\n"s ; }
	}
}

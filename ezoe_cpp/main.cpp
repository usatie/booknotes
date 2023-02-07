int	main()
{
	auto a = 12345 + 6789 ;
	auto b = 8073 * 132 / 5 ;
	auto sum = a + b ;

	std::cout
		<< "a=12345 + 6789="s << a << "\n"s
		<< "b=8073 * 132 / 5="s << b << "\n"s
		<< "a+b="s << sum << "\n"s ;
	if ( a < b )
	{
		std::cout << b << "\n"s ;
	}
	else
	{
		std::cout << a << "\n"s ;
	}

	if ( 2 < 1 )
		std::cout << "sentence 1.\n"s ;
	std::cout << "sentence 2.\n"s ;

	if ( 1 < 2 )
	{
		std::cout << "yes!\n"s ;
		std::cout << "yes!\n"s ;
	}

	{
		auto a = "dog"s ;
		auto b = "dog"s ;
		auto c = "cat"s ;
		
		if ( a == b )
		{
			std::cout << "a == b\n"s ;
		}
		else
		{
			std::cout << "a != b\n" ;
		}

		if ( a == c )
		{
			std::cout << "a == c\n"s ;
		}
		else
		{
			std::cout << "a != c\n" ;
		}
	}

	{
		auto dog = "dog"s ;
		auto cat = "cat"s ;
		
		if ( cat < dog )
		{
			std::cout << "cat is smaller.\n"s ;
		}
		else
		{
			std::cout << "dog is smaller.\n" ;
		}

		auto longcat = "longcat"s ;
		if ( longcat > cat )
		{
			std::cout << "Longcat is Looong.\n"s ;
		}
		else
		{
			std::cout << "Longcat isn't that long. Sigh.\n" ;
		}
	}
	{
		auto x = ""s ;
		
		if ( "a"s < "b"s )
		{ x = "a"s ; }
		else
		{ x = "b"s ; }

		std::cout << x << "\n" ;
	}
	{
		auto x = ""s ;
		
		if ( "aa"s < "ab"s )
		{ x = "aa"s ; }
		else
		{ x = "ab"s ; }

		std::cout << x << "\n" ;
	}
}

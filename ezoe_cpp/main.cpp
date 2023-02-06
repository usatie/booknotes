int	main()
{
	/*
	// statements
	auto x = 1 + 1 ;
	std::cout << x ;
	;
	*/

	// compound statements
	{
		std::cout << "hello\n"s ;
		std::cout << "hello\n"s ;
	}
	{ std::cout << "world\n"s ; }
	{ }
	{{{}}}

	// variable scope
	auto a = 0 ;
	{
		auto b = 0 ;
		{
			auto c = 0 ;
		}
	}

	// shadow
	auto x = 0 ;
	{
		auto x = 1 ;
		{
			auto x = 2 ;
			std::cout << x << "\n"s ;
		}
		std::cout << x << "\n"s ;
		x = 42 ;
		std::cout << x << "\n"s ;
	}
	std::cout << x << "\n"s ;
}

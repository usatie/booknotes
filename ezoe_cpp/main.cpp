int	main()
{
	// compile error
	// auto x = 1 + 1 

	auto x = 1 + 1 ;
	// unused warning
	auto y = x + 1 ;

	std::cout
		<< "EXIT_SUCCESS: "s << EXIT_SUCCESS << "\n"s
		<< "EXIT_FAILURE: "s << EXIT_FAILURE << "\n"s ;

	// compile error
	// "hello"s << 1 ;
}

int	main()
{
	// lambda statement
	auto print = [](auto x)
	{
		std::cout << x << "\n"s ;
	} ;
	print(123) ;
	print(3.14) ;
	print("hello") ;

	auto print_two = []( auto x, auto y )
	{
		std::cout << x << " "s << y << "\n"s ;
	} ;

	print_two( 1, 2 ) ;
	print_two( "Pi is", 3.14 ) ;

	auto no_args = []()
	{
		std::cout << "Nothing\n" ;
	} ;
	no_args() ;

	// () is operator
	// operator ()
	auto donothing = [](){} ;
	donothing() ;
	donothing     (     ) ;

	// operato() on lambda itself
	[](){}() ;
	
	// Return value
	auto plus = []( auto x, auto y )
	{
		return x + y ;
	} ;
	std::cout
		<< plus( 1, 2 ) << "\n"s
		<< plus( 1.5, 0.5 ) << "\n"s
		<< plus( "123"s, "456"s ) << "\n"s ;

	// Exit on return
	auto f = []()
	{
		std::cout << "f is called.\n"s ;
		return 0 ;
		std::cout << "f returned zero.\n" ;
	} ;

	auto result = f() ;
}

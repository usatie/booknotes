// This is lambda expression, not function
// auto function = []( auto value ) { return value ; } ;

int	main()
{
	// Basic Syntax
	{
		// []       : lambda introduce operator
		// ()       : argument list
		// {}       : compound statement
		// ;        : statement terminator
		[](){} ;

		// void f( int x, double d ) {}
		[]( int x, double d ){} ;
		// argument list can use auto
		[]( auto x ) { } ;
		{
			auto f = []( auto x )
			{ std::cout << x ; } ;
			f(0) ; // int
			f(1.0) ; // double
			f("hello"s) ; // std::string
		}
		// compound statement
		[]()
		{
			std::cout << "hello"s ;
			int x = 1 + 1 ;
		} ;
		1 + 1 ; // expression statement
		[](){} ; // expression statement

		// lambda expression can be called as is
		[]( auto x ){ std::cout << x ; }("hello"s) ;

		// argument list can be ommited when no arguments needed
		[]{} ;
		// return type is inffered by return statement
		[]{ return 0 ; } ; // int
		[]{ return 0.0 ; } ; // double
		[]{ return "hello"s ; } ; // std::string
		// compile error : return type can't be inffered
		// return type 'double' must match previous return type 'int' when lambda expression has unspecified explicit return type
		/*
		[]( bool b )
		{
			if ( b )
				return 0 ;
			else
				return 0.0 ;
		} ;
		*/

		// Return type can be explicitly decared
		[]( bool b ) -> int
		{
			if ( b )
				return 0 ;
			else
				return 0.0 ;
		} ;

		// copy capture
		{
			auto message = "hello"s ;
			[=]() { std::cout << message ; } ;

			int x = 0 ;
			[=](){ return x ; } ;
			// cannot assign to a variable captured by copy in a non-mutable lambda
			// [=](){ x = 1 ; } ; // compile error
		}
		// reference capture
		{
			int x = 0 ;
			[&](){ return x ; } ;
			[&](){ ++x ; } ; // compile ok
		}
	}
}

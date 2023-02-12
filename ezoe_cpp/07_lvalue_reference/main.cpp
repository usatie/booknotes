void f ( int & x )
{
	x = 3 ;
}

int	main()
{
	// lvalue reference
	{
		int a = 1 ;
		int & ref = a ;

		ref = 3 ; std::cout << a << "\n"s ;
	}
	// Initialization is must-do
	{
		// int & ref ; // This is compile error
	}
	// Can be used in function
	{
		int a = 1 ;
		f ( a ) ;
		std::cout << a << "\n"s ;
	}
	{
		// This is not correct
		/*
		auto swap = []( auto a, auto b )
		{
			auto temp = a ;
			a = b ;
			b = temp ;
		} ;
		*/
		// This is correct
		auto swap = []( auto & a, auto & b )
		{
			auto temp = a ;
			a = b ;
			b = temp ;
		} ;
	}
	// std::swap
	{
		int a = 1 ;
		int b = 2 ;
		std::swap( a, b ) ;
		std::cout
			<< "a: "s << a << "\n"s
			<< "b: "s << b << "\n"s ;
	}
	// const
	{
		// Both OK
		const int x = 0 ;
		int const y = 0 ;

		// Compile Error
		// x = 1 ;
		// y = 1 ;
	}
	// const lvalue reference
	{
		int x = 0 ;
		int & ref = x ;
		++ref ;
		const int & const_ref = x ;
		// Compile Error
		//++const_ref ;
	}
	{
		int x = 0 ;
		// const int &
		// int const &
		// have the same meaning
		const int & y = x ;
		int const & z = x ;
		// This is compile error
		// int & const yy = x ;
	}
	// Constant Reference to Reference
	{
		int x = 0 ;
		int & ref = x ;
		const int & cref = x ;
	}
	// Reference to constant object
	{
		const int x = 0 ;
		// This is compile error
		// int & ref = x ;

		// This is valid
		const int & cref = x ;
	}
	{
		// vector is copied
		auto f = []( std::vector<int> v )
		{ std::cout << v.at(1234) ; } ;

		// vector is not copied
		auto g = []( std::vector<int> & v )
		{ std::cout << v.at(1234) ; } ;

		// vector is not copied
		// and guarantee not to be changed
		auto h = []( std::vector<int> const & v )
		{ std::cout << v.at(1234) ; } ;
	}
}

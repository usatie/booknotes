int	main()
{
	// Size of floating-point numbers
	{
		float f = 1.0 ;
		double d = 1.0 ;
		long double ld = 1.0 ;

		auto print = [](std::size_t s )
		{ std::cout << s << "\n"s ; } ;
		
		print( sizeof(float) ) ;
		print( sizeof(double) ) ;
		print( sizeof(long double) ) ;
	}
	// Precision is limited
	{
		float a = 10000.0 ;
		float b = 0.0001 ;

		float c = a + b ;
		std::cout << a << "\n"s << b << "\n"s << c << "\n"s ;
	}
	// Float Literals
	{
		auto a = 123.456f ; // float
		auto b = 123.456F ; // float
		auto c = 123.456 ; // double
		auto d = 123.456l ; // long double
		auto e = 123.456L ; // long double
	}
	// Float Literals in the form of a and b
	// a * 10 ^ b
	// a : fractional part, coefficient, significand, mantissa
	// b : exponent part
	// [mantissa]e[exponent]
	// [mantissa]E[exponent]
	{
		auto a = 1.23456e2 ;
		auto b = 123456e-3 ;
		auto c = 123.456e0 ;
		auto d = 123.456E0 ;
	}
	{
		auto a = 1.0e0f ; // float
		auto b = 1.0e0 ; // double
		auto c = 1.0e0l ; // long double 
	}
	// Hexadecimal Literals
	// 0x[mantissa]p[exponent]
	// 0x[mantissa]P[exponent]
	{
		double a = 0xabc.0p1 ; // 5496
		double b = 0xde.fp5 ; // 7134
		std::cout << a << "\n"s << b << "\n"s ;
	}
	// +0 and -0
	{
		// a, b is different bit pattern
		double a = +0.0 ;
		double b = -0.0 ;
		bool c = a == b ; // true
		std::cout << a << "\n"s << b << "\n"s << c << "\n"s ;
	}
	// +infinity and -infinity
	{
		double a = std::numeric_limits<double>::infinity() ;
		double b = -std::numeric_limits<double>::infinity() ;
		bool c = a == b ; // true
		std::cout << a << "\n"s << b << "\n"s << c << "\n"s ;
	}
	// NaN ( Not a Number )
	{
		double NaN = std::numeric_limits<double>::quiet_NaN() ;
		std::cout << NaN << "\n"s ;
		std::cout << ( NaN != 0.0 ) << "\n"s ;
		std::cout << ( NaN == 0.0 ) << "\n"s ;
		std::cout << ( NaN == NaN ) << "\n"s ;
		std::cout << ( NaN != NaN ) << "\n"s ;
		std::cout << ( NaN < 0.0  )<< "\n"s ;
	}
	{
		double NaN = std::numeric_limits<double>::quiet_NaN() ;

		// true
		bool b = NaN != 0.0 ;

		// false
		bool a = NaN == 0.0 ;
		bool c = NaN == NaN ;
		bool d = NaN != NaN ;
		bool e = NaN < 0.0 ;
		std::cout << "a: "s << a << "\n"s ;
		std::cout << "b: "s << b << "\n"s ;
		std::cout << "c: "s << c << "\n"s ;
		std::cout << "d: "s << d << "\n"s ;
		std::cout << "e: "s << e << "\n"s ;
	}
	// Significant Digits
	{
		std::cout
			<< "float: "s << std::numeric_limits<float>::digits10 << "\n"s
			<< "double: "s << std::numeric_limits<double>::digits10 << "\n"s
			<< "long double: "s << std::numeric_limits<long double>::digits10 << "\n"s ;
	}
	// Epsilon
	{
		std::cout
			<< "float: "s << std::numeric_limits<float>::epsilon() << "\n"s
			<< "double: "s << std::numeric_limits<double>::epsilon() << "\n"s
			<< "long double: "s << std::numeric_limits<long double>::epsilon() << "\n"s ;
	}
	// Conversion
	{
		double a = 1.23456789 ;
		float b = a ;
		long double c = a ;

		std::cout << std::setprecision( 10 ) << "a: "s << a << "\n"s ;
		std::cout << std::setprecision( 10 ) << "b: "s << b << "\n"s ;
		std::cout << std::setprecision( 10 ) << "c: "s << c << "\n"s ;
	}
	// <float 1> + <float 2> = max(<float 1>, <float 2>)
	// float < double < long double
	{
		auto a = 1.0f + 1.0f ; // float
		auto b = 1.0f + 1.0 ; // double
		auto c = 1.0f + 1.0l ; // long double
	}
	// float to int
	{
		double a = 1.9999 ;
		int x = a ;
		std::cout << "x: "s << x << "\n"s ;
	}
	{
		int a = 1 ;
		double b = a ;

		std::cout << std::setprecision( 30 ) << "a: "s << a << "\n"s ;
		std::cout << std::setprecision( 30 ) << "b: "s << b << "\n"s ;
	}
	// <float> + integer = <float>
	{
		auto a = 1.0 + 1 ; // double 
		auto b = 1 + 1.0 ; // double
		auto c = 1.0f + 1 ; // float 
	}
}

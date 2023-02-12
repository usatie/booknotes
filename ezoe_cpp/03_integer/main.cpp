int	main()
{
	{
		int a = 123 ;
		int b = 0 ;
		int c = -123 ; // unary operator `-` and integer literal `123`
	}
	{
		int decimal = 123 ;
		int octal = 0123 ;
		int binary = 0b1010 ;
		int another_binary = 0B1010 ;
		int hexadecimal = 0x123 ;
		int another_hexadecimal = 0X123 ;
		int hex_10 = 0xa ;
		int hex_15 = 0xf ;
	}
	{
		int a =   1000'0000 ;
		int b = 1'0000'0000 ;
		int c = 1'22'333'4444'5555 ;
		auto d = 0b10101010'11110000'00001111 ;
		auto e = 07'7'5 ;
		auto f = 0xde'ad'be'ef ;
	}
	{
		auto zero = 0b00000000 ;
		auto max  = 0b11111111 ;
		std::cout << zero << "\n"s ;
		std::cout << max << "\n"s ;
	}
	{
		signed char		sc ;
		short int		si ;
		int				i ;
		long int		li ;
		long long int	lli ;

		unsigned char			uc ;
		unsigned short int		usi ;
		unsigned int			ui ;
		unsigned long int		uli ;
		unsigned long long int	ulli ;
	}
	{
		auto x = 123 ; // int
		auto y = 123u ; // unsigned int
		signed a = 1 ; // int
		unsigned b = 1 ; // unsigned int

		// int <= long < unsigned long
		auto c = 100'0000'0000 ;
		auto d = 123 ; // int
		auto e = 123l ; // long
		auto f = 123L ; // long
		auto g = 123ul ; // unsigned long
		auto h = 123lu ; // unsigned long
		// unsigned long vs long long ?
		auto i = 123ll ; // long long int
		auto j = 123LL ; // long long int
		auto k = 123ull ; // unsigned long long int

		// short/unsigned short cannot be expressed in literal
		char ch ;
		signed char sch ; // different from char!
		unsigned char uch ;
	}
	{
		std::cout << "sizeof(int): " << sizeof(int) << "\n"s ;
		int x{} ;
		std::cout << "sizeof(x): " << sizeof(x) << "\n"s ;
	}
	{
		auto print = []( std::size_t s )
		{ std::cout << s << "\n"s ; } ;

		print( sizeof(char) ) ;
		print( sizeof(short) ) ;
		print( sizeof(int) ) ;
		print( sizeof(long) ) ;
		print( sizeof(long long) ) ;
	}
	{
		std::cout
			<< std::numeric_limits<int>::min() << "\n"s
			<< std::numeric_limits<int>::max() << "\n"s ;
		std::cout
			<< std::numeric_limits<unsigned int>::min() << "\n"s
			<< std::numeric_limits<unsigned int>::max() << "\n"s ;
		std::cout
			<< std::numeric_limits<long>::min() << "\n"s
			<< std::numeric_limits<long>::max() << "\n"s ;
		std::cout
			<< std::numeric_limits<unsigned long>::min() << "\n"s
			<< std::numeric_limits<unsigned long>::max() << "\n"s ;
		std::cout
			<< std::numeric_limits<long long>::min() << "\n"s
			<< std::numeric_limits<long long>::max() << "\n"s ;
		std::cout
			<< std::numeric_limits<unsigned long long>::min() << "\n"s
			<< std::numeric_limits<unsigned long long>::max() << "\n"s ;
	}
	{
		// Conversions
		short a = 123 ; // int to short
		int b = 123l ; // long to int
		unsigned int c = 123 ; // int to unsigned int
		int d = 123u ; // unsigned int to int

		std::cout
			<< "short: "s << std::numeric_limits<short>::max() << "\n"s
			<< "int: "s <<  std::numeric_limits<int>::max() << "\n"s ;
		
		short x = 40000 ;
		std::cout << "overflow x: "s << x << "\n"s ;

		// Explicit Conversion
		// static_cast<T>(e) converts e to type T
		int e = 123 ;
		short f = static_cast<short>( e ) ;
	}
}

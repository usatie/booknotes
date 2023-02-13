struct fractional
{
	int num ;
	int denom ;
} ;

fractional add( fractional & l, fractional & r )
{
	if ( l.denom == r.denom )
		return fractional{ l.num + r.num, l.denom } ;
	return fractional{ l.num * r.denom + r.num * l.denom, l.denom * r.denom } ;
}

int	main()
{
	{
		fractional a{1, 1} ;
		fractional b = add(a, a) ;
		fractional c = add(a, b) ;
	}
	// constructor
	/*
	struct class_name
	{
		int data_member ;
		int x ;

		class_name() { }
		class_name( int value ): data_member(value) { }

		// In this case, x is initialize with x.
		class_name( int x ): x(x) { }

		// In this case, x is initialized before constructor, and then x is assigned.
		class_name( int x ) {
			class_name::x = x ;
		}
	} ;
	*/
	{
		struct fractional
		{
			int num ;
			int denom ;

			// special member function
			fractional( int num )
				: num(num), denom(1)
			{ }
		} ;
		fractional a = 1 ;
		fractional b = 2 ;
	}
	{
		struct S
		{
			int x ;
			S( int x ): x(x)
			{
				std::cout << x ;
			}
		} ;

		S a(1) ;
		S b{2} ;
		S c = 3 ;
		std::cout << "\n"s ;
	}
	// destructor
	/*
	struct S
	{
		~S()
		{
		}
	}
	*/
	{
		struct S
		{
			int n ;
			S( int n ): n(n)
			{
				std::cout << "constructed: "s << n << "\n"s ;
			}
			~S()
			{
				std::cout << "destructed: "s << n << "\n"s ;
			}
		} ;
		S a(1) ;
		{ S b{2} ; }
		S c = 3 ;
	}
	// multi-arity constructor 
	{
		struct fractional
		{
			int num ;
			int denom ;
			fractional( int num )
				: num(num), denom(1)
			{ }

			fractional( int num, int denom )
				: num(num), denom(denom)
			{ }
		} ;

		fractional a = 1 ; // fractional(int) is called
		fractional b(1, 2) ; // fractional(int, int) is called
		fractional c = {1, 3} ; // fractional(int, int) is called
	}
	// default args
	{
		auto f = []( int x = 0 ){} ;
		auto g = []( int x, int y = 0, int z = 0 ){} ;
		// compile error because z needs default arg
		// auto h = []( int x, int y = 0, int z ){} ;
		auto h = []( int x = 0, int y = 0, int z = 0 ){} ;
		f() ;
		f(1) ;
		// compile error because missing arg
		// h( 1, , 2 ) ;
	}
	// fractional with default args
	{
		struct fractional
		{
			int num ;
			int denom ;
			
			fractional( int num, int denom = 1 )
				: num(num), denom(denom)
			{ }
		} ;
		fractional a = 1 ;
		fractional b(1, 2) ;
		fractional c{1, 2} ;
	}
	// delegate constructor
	{
		struct fractional
		{
			int num ;
			int denom ;
			
			fractional( int num, int denom )
				: num(num), denom(denom)
			{ }

			fractional ( int num )
				: fractional( num, 1 )
			{ }
		} ;
		fractional a = 1 ;
		fractional b(1, 2) ;
		fractional c{1, 2} ;
	}
	// delegate constructor
	{
		struct S
		{
			S()
				: S(1)
			{
				// This will be printed second
				std::cout << "delegating constructor\n"s ;
			}

			S( int n )
			{
				// This will be printed first
				std::cout << "constructor\n" ;
			}
		} ;

		S s ;
	}

}

// global scope
int x = 0 ;

int	main()
{
	// expressive
	{
		struct point
		{
			int x = 0 ;
			int y = 0 ;
		} ;

		point p ;

		std::cout << p.x << p.y << "\n"s ;
	}

	// read as many points as you want
	{
		struct point
		{
			int x = 0 ;
			int y = 0 ;
		} ;

		std::vector<point> ps ;

		int x { } ;
		int y { } ;
		
		/*
		while ( std::cin >> x >> y )
		{
			ps.push_back( point{ x, y } ) ;
		}
		*/
	}

	// Declare class
	// struct class_name {} ;
	{
		struct S
		{
			int a = 0 ;
			double b = 0.0 ;
			std::string c = "hello"s ;
		} ;
	}

	// Person
	{
		struct Person
		{
			std::string name ;
			int age ;
		} ;

		Person john ;

		john.name = "john"s ;
		john.age = 20 ;
	}

	// initialize class
	{
		struct S {
			int x ;
			int y ;
			int z ;
		} ;
		S s { 1, 2, 3 } ;
	}

	// member function
	{
		struct fractional
		{
			int num ;
			int denom ;

			double value()
			{
				return static_cast<double>(num) / static_cast<double>(denom) ;
			}
		} ;

		fractional x{1, 2} ;
		std::cout << static_cast<double>(x.num) / static_cast<double>(x.denom) << "\n"s ;
		std::cout << x.value() << "\n"s ;
	}
	// mutating member function
	{
		struct X
		{
			int data ;
			void f()
			{
				data = 3 ;
			}
		} ;

		X x {0} ;

		std::cout << x.data << "\n"s ;
		x.f() ;
		std::cout << x.data << "\n"s ;

		struct fractional
		{
			int num ;
			int denom ;

			void set( int num_ )
			{
				num = num_ ;
				denom = 1 ;
			}
			void set( int num_, int denom_ )
			{
				num = num_ ;
				denom = denom_ ;
			}
			double value()
			{
				return static_cast<double>(num) / static_cast<double>(denom) ;
			}
		} ;
		fractional y ;
		std::cout << y.value() << "\n"s ;
		y.set(5) ;
		std::cout << y.value() << "\n"s ;
		y.set(2, 3) ;
		std::cout << y.value() << "\n"s ;
	}
	// collision of variable name and data member
	{
		struct S
		{
			// class scope
			int x ;
			void f ( int x )
			{
				// function block scope
				x = x ;
			}
			void g( int x )
			{
				S::x = x ;
			} 
			void h( int x )
			{
				::x = x ;
			} 
		} ;

		S s{0} ;

		s.f(1) ; // this won't change s.x
		std::cout << s.x << "\n"s ; // 0
		s.g(2) ; // this will change s.x
		std::cout << s.x << "\n"s ; // 2
		s.h(3) ; // this won't change s.x
		std::cout << s.x << "\n"s ; // 2
		std::cout << x << "\n"s ; // 3
	}
	// class scope
	{
		struct fractional
		{
			int num ;
			int denom ;
			
			void set( int num, int denom )
			{
				fractional::num = num ;
				fractional::denom = num ;
			}
		} ;
	}
}

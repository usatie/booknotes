// template < typename T >
//     Declaration

// n is Template Parameter
template < typename T >
T twice( T n )
{
	return n * 2 ;
}

template < typename T >
void f( T const & x )
{
	std::cout << x << "\n"s  ;
}

// Template Parameter can be integer value
template < int N >
void f2()
{
	std::cout << N << "\n"s ;
}

template < std::size_t N >
void f3()
{
	int buffer[N] ;
}

// Template Parameter must be valid
template < typename vec >
void f4( vec & v )
{
	v.push_back(0) ;
}

// Class template
/*
template < typename T, std::size_t N >
struct array
{
	T storage[N] ;

	T & operator [] ( std::size_t i )
	{
		return storage[i] ;
	}
} ;
*/
template < typename T, std::size_t N >
struct array
{
	using value_type = T ;
	using reference = T &;
	using const_reference = T const & ;

	using size_type = std::size_t ;

	value_type storage[N] ;
	// []
	reference operator [] ( size_type i ) { return storage[i] ; }
	const_reference operator [] ( size_type i ) const { return storage[i] ; }
	// front/back
	reference front ( ) { return storage[0] ; }
	const_reference front ( ) const { return storage[0] ; }
	reference back ( ) { return storage[N-1] ; }
	const_reference back ( ) const { return storage[N-1] ; }
	void fill( const_reference u )
	{
		for ( size_type i = 0 ; i != N ; ++i )
			storage[i] = u ;
		// This doesn't work yet
		// std::fill( begin(), end() , u ) ;
	}

	// Declare and Definition
	size_type size() const ;
} ;

template < typename T, std::size_t N >
std::size_t array<T, N>::size() const { return N ; }

template < typename Array >
void	print( Array const & a )
{
	std::cout << "["s ;
	for ( int i = 0 ; i < a.size() ; ++i )
	{
		if ( i > 0 )
			std::cout << ", "s ;
		std::cout << a[i] ;
	}
	std::cout << "]\n"s ;
}

int	main()
{
	{
		std::cout << twice( 123 ) << "\n"s ;
		std::cout << twice( 1.23 ) << "\n"s ;
	}
	// Type is determined when the template is used.
	// Type can be inferred
	// Infer T by parameter
	{
		f( 0 ) ; // T is int
		f( 0.0 ) ; // T is double
		f( "hello"s ) ; // T is std::string
	}
	// Explicitly write T
	{
		f<int>( 0 ) ;
		f<double>( 0 ) ; // conversion from int 0 to double 0.0
	}
	// Template parameter can be int value
	{
		f2<42>() ;
		f2<123>() ;
	}
	// Template parameter must be deterministic at compile time
	{
		f2<1+1234>() ;

		/* Compile error
		int x{} ;
		std::cin >> x ;
		g<x>() ;
		*/
	}
	// Array size can be set by template parameter
	{
		f3<10>() ;
		f3<12>() ;
	}
	// Template code must be valid
	{
		// OK
		std::vector<int> a ;
		f4 ( a ) ;
		// OK
		std::vector<double> b ;
		f4 ( b ) ; // Conversion from int to double inside

		/*
		std::vector<std::string> c ;
		f4 ( c ) ; // cannot convert int to std::string
		
		f4 ( 0 ) ; // int doesn't have push_back()
		*/
	}
	// array
	{
		array<int, 10> a = {1,2,3} ;

		a[5] = 5 ;
		for ( int i = 0 ; i < 10 ; ++i )
			std::cout << a[i] << ", " ;
		std::cout << "\n" ;
	}
	// array with type alias
	{
		using array_type = std::array<int, 5> ;
		array_type a = {1,2,3,4,5} ;
		// auto keyword didn't exist long ago
		array_type::value_type x = 0 ; // auto x = 0 ;
		array_type::reference ref = a[0] ; // auto ref = a[0] ;
	}
	// size()
	// const modifier
	{
		struct S
		{
			void f() {}
		} ;
		S s ;
		s.f() ;

		S const cs ;
		// Compile Error!
		// cs.f() ;
	}
	{
		struct S
		{
			void f() {}
			void f() const {}
		} ;
		S s ;
		s.f() ;

		S const cs ;
		cs.f() ;
	}
	// const member function can't return reference to data member
	{
		struct S
		{
			int data {} ;
			int & get() { return data ; }
			// Compile error
			// int & get() const { return data ; }
			int const & get() const { return data ; }
		} ;
		S s ;
		s.get() ;
	}
	// const array 
	{
		using array_type = std::array<int, 5> ;
		array_type a = {1,2,3,4,5} ;
		print( a ) ;
	}
	// front/back
	{
		array<int, 5> a = {1,2,3,4,5} ;

		int & f = a.front() ; // 1
		int & b = a.back() ; // 5

		std::cout << "front: " << f << "\n"s ;
		std::cout << "back: " << b << "\n"s ;
		f = 100 ;
		b = 42 ;
		print ( a ) ;
	}
	// fill
	{
		array<int, 5> a = {1,2,3,4,5} ;
		a.fill(0) ;
		print( a ) ;
	}
}

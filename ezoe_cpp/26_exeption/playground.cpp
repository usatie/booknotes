// Implement array::at
template < typename T, std::size_t N >
struct array
{
	using reference = T & ;
	using size_type = std::size_t ;

	T storage[N] ;

	size_type size() const { return N ; }
	reference at( size_type n )
	{
		if ( n >= size() )
			throw std::out_of_range("Error: Out of Range") ;
		return storage[n] ;
	}
} ;

int	main()
{
	// Throw an error
	{
		std::cout << "Don't type 0. >"s ;

		int input {} ;
		std::cin >> input ;
		
		if ( input == 0 )
			throw 0 ;

		std::cout << "Success!\n"s ;
	}
	// std::out_of_range
	{
		std::out_of_range err("I am an error.") ;

		std::cout << err.what() ;
	}
	// Throw an error
	{
		std::cout << "Enter Index between 0 to 4. >"s ;

		int i {} ;
		std::cin >> i ;
		
		array<int, 5> a = {1,2,3,4,5} ;
		a.at(i) ;
	}
	// Catch an error
	{
		/*
		try {
			// throwable code
		} catch ( type name ) {
			// error handling
		}
		*/
		try {
			throw 123 ;
		} catch ( int e ) {
			std::cout << e ;
		}
		std::cout << "resumed.\n" ;
	}
	// Can't catch when type doesn't match
	/*
	{
		try {
			throw 3.14 ; // double
		} catch ( int e ) {
			std::cout << e ;
		}
		std::cout << "You won't read this.\n" ;
	}
	*/
	// Multiple catch
	{
		try {
			throw "error"s ; // std::string
		} catch ( int e ) {
			std::cout << e ;
		} catch ( double e ) {
			std::cout << e ;
		} catch ( std::string e ) {
			std::cout << e ;
		}
		std::cout << "resumed.\n" ;
	}
	// Nested error can be caught
	{
		auto f = []() { throw 123 ; } ;
		auto g = [&]() { f() ; } ;
		auto h = [&]() { g() ; } ;
		try {
			h() ;
		} catch ( int e ) {
			std::cout << e ;
		}
		std::cout << "resumed.\n" ;
	}
	// catch an error from std::array
	{
		std::array<int, 1> a = {0} ;
		
		try {
			a.at(1000) ;
			// typo : a[1000] ;
		}
		catch( std::out_of_range & e )
		{
			std::cout << e.what() << "\n"s ;
		}
		std::cout << "resumed.\n" ;
	}
	// Stack Unwinding
	{
		auto f = []() {
			try { throw 0 ; }
			catch ( double e ) { std::cout << "not here.\n" ; }
			std::cout << "This is not printed\n"s ;
		} ;
		try {
			try {
				f() ;
			} catch ( std::string & e ) { std::cout << "not here.\n" ; }
			std::cout << "This is not printed\n"s ;
		} catch ( int e ) { std::cout << "caught here.\n" ; }
	}
	// Destructor can be called during stack unwinding
	{
		struct Object {
			std::string name ;
			Object( std::string const & name ) : name(name)
			{ std::cout << name << " is constructed.\n"s ; }
			~Object()
			{ std::cout << name << " is destructed.\n"s ; }
		} ;
		Object obj("obj"s) ;

		auto f = []() { 
			Object obj("f"s) ;
			throw 123 ;
		} ;
		auto g = [&]() {
			Object obj("g"s) ;
			f() ;
		} ;
		auto h = [&]() {
			Object obj("h"s) ;
			g() ;
		} ;
		try {
			h() ;
		} catch ( int e ) {
			std::cout << "caught.\n"s ;
		}
	}
	// std::scope_exit from C++20
	/*
	{
		auto f = []() { 
			// maybe typo after new?
			auto ptr = new ;
			// maybe typo missing ()?
			std::scope_exit e( [&]{ delete ptr ; } ) ;

		} ;
	}
	*/
}

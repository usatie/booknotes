// return_type func_name (args) {body}

int plus ( int x, int y )
{
	return x + y ;
}

double plus ( double x, double y )
{
	return x + y ;
}

std::string plus ( std::string x, std::string y )
{
	return x + y ;
}


/* Compile error
int f()	{}
*/

// ok
void f(){}

auto a() {}
auto b() { return 0 ; }
auto c() { return 0.0 ; }
auto d() { return ""s ; }

/* compile error type 
auto e()
{
	return 0 ;
	return 0.0 ;
}
*/

int	main()
{
	auto x = plus( 1, 2 ) ;
	std::cout << x << "\n" ;

	auto d = plus( 1.1, 2.04 ) ;
	std::cout << d << "\n" ;

	auto s = plus( "hello"s, "world"s ) ;
	std::cout << s << "\n" ;
}

#include "all.h"

int	main()
{
	auto answer = 42 ;
	std::cout << answer << "\n"s ;

	auto pi = 3.14 ;
	std::cout << pi << "\n"s ;

	auto question = "Life, The Universe, and Everything."s ;
	std::cout << question ;

	auto a = 1 ;
	auto b(2) ;
	auto c{3} ;

	/* compile error
	std::cout << x ;
	auto x = 123 ;
	*/

	auto x
	= 123 ;

	std::cout << x;

	x = 456 ;

	std::cout << x;

	x = 789 ;

	std::cout << x;
	std::cout << "\n"s ;

	// self assignment
	x = 10 ;
	x = x + 5 ;

	std::cout << x;
	std::cout << "\n"s ;
	
	// Add 
	x = 1 ;
	x += 5 ;

	std::cout << x;
	std::cout << "\n"s ;

	// Statically typed
	/* compile error
	auto x = 1 ;
	x = "hello"s ;
	x = 2 ;
	*/

	auto i = 123 ; // int
	auto d = 1.23 ; // double
	auto s = "123"s ; // std::string
	

	/* ok
	int a = 3.14 ;
	std::cout << a << "\n"s ;

	double d = 123 ;
	std::cout << d;
	
	int i = 0.9999 ;
	std::cout << i ; // 0

	double d = 1234567890 ;
	std::cout << d ;
	*/
	
	d = 1234567890 ;
	std::cout << d ;
}

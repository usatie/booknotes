#include "all.h"

int	main()
{
	std::cout
		<< "Integer: "s << 42 << "\n"s
		<< "Floating Point: "s << 3.14 ;
	
	std::cout << "\n"s ;

	std::cout
		<< 3 + 5 << " "s << 3 - 5 << " "s
		<< 3 * 5 << " "s << 3 / 5 << " "s
		<< 3 % 5 ;
	
	std::cout << "\n"s ;

	std::cout << (1 + 2) * 3;

	std::cout << "\n"s ;

	// mod is invalid in floats
	std::cout
		<< 3.5 + 7.11 << " "s << 3.5 - 7.11 << " "s
		<< 3.5 * 7.11 << " "s << 3.5 / 7.11 ;

	std::cout << "\n"s ;

	std::cout << 1 + 0.1 ;
	
	std::cout << "\n"s ;

	// Compile error
	// std::cout << 1 + "234"s ;

	// Maybe in this case, "234" is a pointer
	std::cout << 1 + "234" ;
}

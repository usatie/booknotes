#include "all.h"

int	main()
{
	// What's the difference of "" and ""s ?
	std::cout << "hello"s ;
	std::cout << "hello" ;
	std::cout << "aaa\nbbb\nccc"s ;
	std::cout << "\\n is a new-line.\n"s ;
	std::cout << "hello"s + "world"s ;
}

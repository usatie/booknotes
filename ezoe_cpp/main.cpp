#include "all.h"

// g++ -std=c++17 -Wall --pedantic-errors -o hello hello.cpp
// man gcc
// g++ -include all.h -o program main.cpp
// time g++ -std=c++17 -Wall --pedantic-errors -include all.h -o program main.cpp
// g++ -std=c++17 -Wall --pedantic-errors -x c++-header -o all.h.gch all.h
// time g++ -std=c++17 -Wall --pedantic-errors -include all.h -o program hello.cpp
int	main()
{
	std::cout << "hello" ;
}

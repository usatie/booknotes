#include "array.hpp"

int main()
{
	using Array = const array<int, 5> ;
	{
		Array a = {1,2,3,4,5} ;

		auto iter = a.begin() ;
		std::cout << "postfix\n" ;
		std::cout << *iter++ << "\n"s ;
		std::cout << *iter++ << "\n"s ;
		std::cout << *iter-- << "\n"s ;
		std::cout << *iter-- << "\n"s ;
	}
	{
		Array a = {1,2,3,4,5} ;

		auto iter = a.begin() ;
		std::cout << "prefix\n" ;
		std::cout << *++iter << "\n"s ;
		std::cout << *++iter << "\n"s ;
		std::cout << *--iter << "\n"s ;
		std::cout << *--iter << "\n"s ;
	}
	// Now it's available in algorithms!
	{
		Array a = {1,2,3,4,5} ;

		std::for_each( std::begin(a), std::end(a),
			[](auto x) { std::cout << x ; } ) ;
		std::cout << "\n" ;
	}
	// +=, +
	// -=, -
	{
		Array a = {1,2,3,4,5} ;

		auto iter = a.begin() ;
		std::cout << "+=, +\n" ;
		std::cout << *(iter+=2) << "\n"s ;
		std::cout << *iter << "\n"s ;
		std::cout << *(iter+2) << "\n"s ;
		std::cout << *iter << "\n"s ;
		std::cout << "-=, -\n" ;
		std::cout << *(iter-=2) << "\n"s ;
		std::cout << *iter << "\n"s ;
		std::cout << *(iter-2) << "\n"s ;
		std::cout << *iter << "\n"s ;
	}
	// []
	{
		Array a = {1,2,3,4,5} ;

		auto iter = a.begin() ;
		std::cout << "[]\n" ;
		std::cout << iter[0] << "\n"s ;
		std::cout << iter[1] << "\n"s ;
		std::cout << iter[2] << "\n"s ;
		std::cout << iter[3] << "\n"s ;
		std::cout << iter[4] << "\n"s ;
	}
	// <, <=, >, >=
	{
		Array a = {1,2,3,4,5} ;

		auto i = a.begin() ;
		auto j = i + 1 ;
		std::cout << "<, <=, >, >=\n" << std::boolalpha ;
		std::cout << (i <  j) << "\n"s ;
		std::cout << (i <= j) << "\n"s ;
		std::cout << (i >  j) << "\n"s ;
		std::cout << (i >= j) << "\n"s ;
	}
}

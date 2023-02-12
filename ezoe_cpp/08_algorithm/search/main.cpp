int	main()
{
	{
		// Without type definition ok?
		// std::vector<int>
		std::vector v1 = {1,2,3,4,5,6,7,8,9} ;
		std::vector v2 = {4,5,6} ;

		// Search subset
		auto a = std::search( std::begin(v1), std::end(v1), std::begin(v2), std::end(v2) ) ;
		bool A = ( a == std::next( std::begin(v1), 3 ) ) ;
		std::cout << "A : "s << A << "\n"s ;

		// Search Empty
		auto b = std::search( std::begin(v1), std::end(v1), std::end(v2), std::end(v2) ) ;
		bool B = ( b == std::begin(v1) ) ;
		std::cout << "B : "s << B << "\n"s ;

		// Search non subset
		std::vector v3 = {3,2,1} ;
		auto c = std::search( std::begin(v1), std::end(v1), std::begin(v3), std::end(v3) ) ;
		bool C = ( c == std::end(v1) ) ;
		std::cout << "C : "s << C << "\n"s ;
	}
}

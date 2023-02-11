int	main()
{
	{
		std::vector<int> a = {1,2,3,4,5} ;
		std::vector<int> b = {1,2,3,4,5} ;
		std::vector<int> c = {1,2,3,4,5,6} ;
		std::vector<int> d = {1,2,3,4,5} ;
		
		bool ab = std::equal(
			std::begin(a), std::end(a),
			std::begin(b), std::end(b) ) ;
		bool ac = std::equal(
			std::begin(a), std::end(a),
			std::begin(c), std::end(c) ) ;
		bool ad = std::equal(
			std::begin(a), std::end(a),
			std::begin(d), std::end(d) ) ;
		std::cout << std::boolalpha ;
		std::cout << "ab: "s << ab << "\n"s ;
		std::cout << "ac: "s << ac << "\n"s ;
		std::cout << "ad: "s << ad << "\n"s ;
	}
	// size
	{
		std::vector<int> v = {1,2,3,4,5} ;
		auto first = std::begin(v) ;
		auto last = std::end(v) ;
		auto size = last - first ;
		auto next = first + 1 ;
		auto size_from_next = last - next ;
	}
	// distance
	{
		std::vector<int> v = {1,2,3,4,5} ;
		auto first = std::begin(v) ;
		auto last = std::end(v) ;
		auto distance = []( auto first, auto last){
			return last - first ;
		} ;

		auto size = std::distance(first, last) ;
		auto size_from_next = std::distance(first + 1, last) ;
	}
	// equal
	{
		auto equal = []( auto first1, auto last1, auto first2, auto last2 )
		{
			auto size1 = std::distance( first1, last1 ) ;
			auto size2 = std::distance( first2, last2 ) ;
			if ( size1 != size2 )
				return false ;
			for ( auto i = first1, j = first2 ;
					i != last1 ; ++i, ++j )
			{
				if ( *i != *j )
					return false ;
			}
			return true ;
		} ;
	}
	// equal pred
	{
		auto equal = []( auto first1, auto last1, auto first2, auto last2, auto pred )
		{
			auto size1 = std::distance( first1, last1 ) ;
			auto size2 = std::distance( first2, last2 ) ;
			if ( size1 != size2 )
				return false ;
			for ( auto i = first1, j = first2 ;
					i != last1 ; ++i, ++j )
			{
				if ( pred(*i ,*j ) )
					return false ;
			}
			return true ;
		} ;
		auto equal2 = []( auto first1, auto last1, auto first2, auto last2 )
		{
			return std::equal( first1, last1, first2, last2,
					[]( auto v1, auto v2){ return (v1 == v2) ; } ) ;
		} ;
	}
}

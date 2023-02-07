int	main()
{
	/*
	std::vector<int> vi ;
	std::vector<double> vd ;
	std::vector<std::string> vs ;
	std::vector<std::vector<int>> vvi ;
	std::vector<std::vector<std::vector<int>>> vvvi ;

	{
		std::vector<int> v ;

		v.push_back(1) ;
		v.push_back(2) ;
		v.push_back(3) ;
	}
	{
		std::vector<int> v ;

		for ( int i = 0 ; i < 1000 ; ++i )
		{
			v.push_back(i) ;
			std::cout << "size: " << v.size() << "\n"s ;
		}
		std::cout << v.at(0) << "\n"s ;
		std::cout << v.at(4) << "\n"s ;
		std::cout << v.at(9) << "\n"s ;
		std::cout << v.at(999) << "\n"s ;
		// runtime error
		// std::cout << v.at(1000) << "\n"s ;
	}
	{
		std::vector<int> v ;
		std::size_t size = v.size() ;
		v.push_back(0) ;
		std::size_t index = 0 ;
		v.at( index ) ;
	}
	{
		std::vector<int> v ;


		for ( int iota = 0 ; iota < 10 ; ++iota )
		{
			v.push_back( iota ) ;
		}

		for ( std::size_t index = 0 ; index < 10 ; ++index )
		{
			std::cout << v.at( index ) << " "s ;
		}
	}
	*/
	{
		std::vector<int> v = { 8, 3, 7, 4, 2, 9, 3 } ;
		std::size_t size = v.size() ;

		for ( std::size_t head = 0 ; head != size ; ++head )
		{
			std::size_t min = head ;
			for ( std::size_t index = head + 1 ; index != size ; ++index )
			{
				if ( v.at( index ) < v.at( min ) )
					min = index ;
			}
			std::cout << v.at( min ) << " "s ;
			auto temp = v.at( head ) ;
			v.at( head ) = v.at( min ) ;
			v.at( min ) = temp ;
		}

		std::cout << "\n"s ;
		for ( std::size_t index = 0; index != size ; ++index )
			std::cout << v.at( index ) << " "s ;
	}
}

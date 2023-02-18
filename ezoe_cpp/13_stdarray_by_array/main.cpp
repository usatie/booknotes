int	main()
{
	// Naive Implementation of std::array
	{
		struct array_int_3
		{
			int m0 ; int m1 ; int m2 ;

			int & operator []( std::size_t i )
			{
				switch(i)
				{
					case 0 :
						return m0 ;
					case 1 :
						return m1 ;
					case 2 :
						return m2 ;
					default:
						std::abort() ;
				}
			}
		} ;

		array_int_3 arr {} ;

		std::cout << arr[0] << ", " << arr[1] << ", " << arr[2] << "\n"s ; 
		arr[0] = 1 ;
		arr[1] = 21 ;
		arr[2] = 42 ;
		std::cout << arr[0] << ", " << arr[1] << ", " << arr[2] << "\n"s ; 
		// This will abort
		// std::cout << arr[3] ;
	}
	// array basics
	{
		// Initialize by compile time constant
		{
			int a[10] ;
			double b[5] ;
			/* Compile Error
			std::size_t size ;
			std::cin >> size ;
			int c[size] ;
			*/
		}
		// Initialize by literal
		{
			int a[5] = {1,2,3,4,5} ;
			double b[3] = {1.0, 2.0, 3.0} ;
		}
		// Access by operator []
		{
			int a[5] = {1,2,3,4,5} ;
			std::cout << a[3] << "\n" ;
			a[2] = 0 ;
		}
		// No member function
		// size
		{
			auto print = [](auto s) { std::cout << s << "\n"s ; } ;
			int a[5] ;
			print( sizeof(a) ) ;
			print( sizeof(int) * 5 ) ;

			double b[5] ;
			print( sizeof(b) ) ;
			print( sizeof(double) * 5 ) ;
		}
		// Array has no member functon, cannot be copied.
		// That's why std::array exists.
		// std::array wraps array.
		{
			// aray cannot be copied, however array as data member of class is copied.
			struct array_int_10
			{
				int storage[10] ;
			} ;
			auto print = [](auto v) { 
				for (auto i = 0 ; i < 10 ; ++i )
					std::cout << v.storage[i] << ", " ;
				std::cout << "\n"s ;
			} ;
			array_int_10 a = { 0, 1, 2 } ;
			array_int_10 b = a ;
			print(a) ;
			print(b) ;
		}
		// operator []
		{
			struct array_int_10
			{
				int storage[10] ;

				int & operator [] ( std::size_t i ) 
				{
					return storage[i] ;
				}
			} ;
			auto print = [](auto v) { 
				for (auto i = 0 ; i < 10 ; ++i )
					std::cout << v.storage[i] << ", " ;
				std::cout << "\n"s ;
			} ;
			array_int_10 a = { 0,1,2,3,4,5,6,7,8,9  } ;
			a[3] =  0 ;
			print(a) ;
		}
	}
}

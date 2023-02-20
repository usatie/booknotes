int	main()
{
	/*---------------------------------------------
	 * Common between pointer and reference
	  --------------------------------------------- */
	// reference
	{
		int object = 0 ;
		object = 123 ;

		std::cout << object << "\n"s ;

		int & ref = object ;
		ref = 456 ;
		std::cout << object << "\n"s ;

		object = 789 ;
		std::cout << ref << "\n"s ;
	}
	// reference must be initialize at declaration
	// target can't be changed
	{
		int x = 0 ;
		int & r = x ;
		int y = 1 ;

		r = y ; // This does not change the reference target
	}
	// reference vs pointer
	{
		using ref_type = int & ;
		using ptr_type = int * ;

		int object { } ;

		// declare/initialize
		ref_type r = object ; // reference can be initialized via value type
		ptr_type p = &object ; // pointer needs operator & 

		// read/write
		r = 42 ;       // reference
		int read = r ; // reference
		*p = 42 ;      // pointer needs operator * to dereference
		read = *p ;    // pointer needs operator * to dereference

		ptr_type p2 = p ; // pointer with no operator is pointer, not dereferenced value
	}
	/*---------------------------------------------
	 * Difference between pointer and reference
	  --------------------------------------------- */
	// assignment
	{
		int x { } ;
		int y { } ;

		int & reference = x ;
		reference = y ; // doesn't change the reference target

		int * pointer = &x ;
		pointer = &y ; // change the reference target to y
	}
	/*
	// NULL pointer
	{
		// Compile error
		//int & reference ; // reference must be initialized

		int * pointer ; // this is ok, but the pointer value is undefined
		std::cout << *pointer ; // this is undefined
		*pointer = 123 ; // this is undefined
	}
	*/
	// nullptr
	{
		int * pointer = nullptr ;
		double * p1 = nullptr ;
		std::string * p2 = nullptr ;

		int * p3 = NULL ; // NULL is treated as null pointer
		int * p4 = 0 ; // 0 is treated as null pointer
		// However, null pointer is not guaranteed to be 0.
	}
	// Invalid reference happens with pointer
	{
		auto f = []() -> int * {
			int variable {} ;
			return &variable ;
		} ;

		int * ptr = f() ;
		int read = *ptr ; // This dereference is invalid
	}
	// Invalid reference can happen with reference
	{
		auto f = []() -> int & {
			int variable {} ;
			return variable ;
		} ;

		int & ref = f() ;
		int read = ref ; // This dereference is invalid
	}
}

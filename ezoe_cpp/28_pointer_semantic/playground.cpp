int	main()
{
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
}

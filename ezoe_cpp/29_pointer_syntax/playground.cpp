// Syntax
//
// T *     : ponter to T
// T &     : reference to T
// const T : constant T
// T const : constant T

int f( int x )
{
	std::cout << x << "\n" ;
	return x ;
}

int	main()
{
	// T *     : ponter to T
	{
		using t1 = int * ;
		using t2 = double * ;
		using t3 = std::string * ;
		using t4 = std::array<int, 5> * ;
		using t5 = std::array<double, 10> * ;
	}
	// T *     : ponter to T
	// T &     : reference to T
	// const T : constant T
	// T const : constant T
	{
		using t1 = int * ;
		using t2 = int & ;
		using t3 = const int ;
		using t4 = int const ;
	}
	// pointer and reference
	{
		using type = int * & ; // reference to pointer
		// using error = int & * ; // pointer to reference
	}
	// Pointer to reference is invalid, meaningless
	{
		int data {} ;
		int & ref = data ;
		int *p1 = &data ;
		int *p2 = &ref ;

		// reference behave the same as referenced object,
		// so p1 and p2 are the same.
	}
	// Reference to pointer
	{

		int * ptr = nullptr ;
		int * & ref = ptr ;

		int data {} ;
		ref = &data ; // ptr = &value
	}
	// pointer and const
	{
		using T = int ;
		using const_T_1 = const T ;
		using const_T_2 = T const ;
		using T_pointer = T * ;

		// pointer to <const T>
		using const_T_pointer_1 = const T * ;
		using const_T_pointer_2 = T const * ;

		// const pointer to <T>
		using T_const_pointer = T * const ;
		// Why this is not so ?
		// using T_const_pointer_2 = const T * ;
		// using T_const_pointer_1 = T_pointer const ;
		// using T_const_pointer_2 = const T_pointer ;

		// const pointer to <const T>
		using const_T_const_pointer_1 = const T * const ;
		using const_T_const_pointer_2 = T const * const ;
	}
	// pointer to <const T>
	{
		const int data = 123 ;
		const int data2 = 456 ;
		int data3 = 789 ;
		const int * ptr = &data ;

		int read = *ptr ; // ok
		//*ptr = 0 ;      // NOT OK
		ptr = &data2 ;    // ok
		ptr = &data3 ;    // ok
		//*ptr = 42       // NOT OK
		data3 = 42 ;      // ok
	}
	// pointer to pointer
	{
		using U = int ;
		using T = U * ; // pointer to T
		using type = T * ; // pointer to pointer
	}
	{
		int x = 123 ;
		int * p = &x ;
		int ** pp = &p ;

		int value1 = **pp ; // get value x from pp
		std::cout << "value1: " << value1 << "\n" ;
		int y = 456 ;
		*pp = &y ; // update value p
		int value2 = **pp ; // get calue y from pp
		std::cout << "value2: " << value2 << "\n" ;
	}
	{
		int object { } ;

		int * a = &object ;
		int ** b = &a ;
		int ** pointer_to_pointer_to_object = b ;

		int *c = *pointer_to_pointer_to_object ;

		std::cout << "object: " << object << "\n" ;
		*c = 1 ; // object = 1
		std::cout << "object: " << object << "\n" ;
		**b = 2 ; // object = 2
		std::cout << "object: " << object << "\n" ;
	}
	{
		int object { } ;

		int * a = &object ;
		int ** b = &a ;

		int & r1 = *a ;
		int & r2 = **b ;

		std::cout << "object: " << object << "\n" ;
		r1 = 1 ;
		std::cout << "object: " << object << "\n" ;
		r2 = 2 ;
		std::cout << "object: " << object << "\n" ;
	}
	{
		using type = int *** ;
		using pointer_to_type = type * ;
	}
	{
		using type = int const * const * const * const ;
	}
	// pointer to function
	{
		int f( int ) ;
		double g( double, double ) ;

		using f_type = int ( int ) ;
		using g_type = double ( double, double ) ;

		using f_pointer = f_type * ;
		using g_pointer = g_type * ;
	}
	// call function via pointer
	{
		using f_type = int ( int ) ;
		using f_pointer = f_type * ;
		/*
		 * Lambda cannot be used as function pointer?
		auto f = []( int x ) -> int {
			std::cout << x << "\n" ;
			return x ;
		}
		*/
		f_pointer ptr = &f ;
		(*ptr)(123) ;
		ptr(456) ; // pointer to function can be automatically dereferenced
	}
	// declare pointer to function without type alias
	{
		int (*ptr)(int) = &f ;
		int * name1 ;
		int (*name2	) ;
		using type1 = int * ;
		using type2 = int (* /* name is omitted */ ) ;
		int * f2( int ); // function returns pointer to int
		using type3 = int (* /* name is omitted */ )(int) ; // function pointer
	}
}

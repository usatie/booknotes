// Syntax
//
// T *     : ponter to T
// T &     : reference to T
// const T : constant T
// T const : constant T

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
	// 
}

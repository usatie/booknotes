int	main()
{
	using Array = std::array<int,5> ;
	// 4 types of iterators
	{
		// iterator
		Array::iterator i = nullptr ;
		// const iterator
		const Array::iterator c_i = nullptr ;
		// const_iterator
		Array::const_iterator ci = nullptr ;
		// const const_iterator
		const Array::const_iterator c_ci = nullptr ;

		// nullptr is needed to compile
	}
	// Get const_iterator
	// const array
	{
		const Array a = {1,2,3,4,5} ;
		auto i = a.begin() ; // const_iterator
	}
	// cbegin/cend
	{
		Array a = {1,2,3,4,5} ;
		auto i = a.cbegin() ; // const_iterator
		auto j = a.cend() ; // const_iterator
	}
	// Conversion from iterator
	{
		Array a = {1,2,3,4,5} ;
		Array::iterator i = a.begin() ; // iterator
		Array::const_iterator j = i ; // const_iterator
	}
	// Difference between const iterator and const_iterator
	// const iterator
	{
		Array a = {1,2,3,4,5} ;
		const Array::iterator iter = a.begin() ;

		// 1. Compile Error
		// ++iter ;

		// 2. Able to change the element referenced by iterator
		*iter = 42 ;
	}
	// const_iterator
	{
		Array a = {1,2,3,4,5} ;
		Array::const_iterator iter = a.cbegin() ;

		// 1. Able to change the iterator of itself
		++iter ;

		// 2. Compile Error
		//*iter = 42 ;
	}
	// const const_iterator
	{
		Array a = {1,2,3,4,5} ;
		const Array::const_iterator iter = a.cbegin() ;

		// 1. Compile Error
		//++iter ;

		// 2. Compile Error
		//*iter = 42 ;
	}
	// auto, auto const
	{
		Array a = {1,2,3,4,5} ;
		auto i = a.begin() ; // iterator
		auto const c_i = a.begin() ; // const iterator
		auto ci = a.cbegin() ; // const_iterator
		auto const c_ci = a.cbegin() ; // const const_iterator
	}
}

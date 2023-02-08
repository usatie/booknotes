int	main()
{
	// Typedef name (Type Alias)
	{
		using Number = int ;
		
		Number x = 0 ;
	}
	// {type_name} {var_name} ;
	// typedef {type_name} {var_name}
	{
		typedef int Number ;
		
		Number x = 0 ;
	}
	{
		int typedef Number ;

		Number x = 0 ;
	}
}

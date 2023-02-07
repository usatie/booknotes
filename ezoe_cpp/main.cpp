// for ( init ; cond ; increment ) statement
void	print_n( int n )
{
	for ( int i = 0 ; i < n ; ++i )
		std::cout << i << " "s ;
	std::cout << "\n"s ;
}

void	print_times_table_for()
{
	for ( int a = 1 ; a <= 9 ; ++a )
	{
		for ( int b = 1 ; b <= 9 ; ++b )
		{
			std::cout << a * b << "\t"s ;
		}
		std::cout << "\n"s ;
	}
}

int	main()
{
	print_n( 100 ) ;
	print_times_table_for() ;
}

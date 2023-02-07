void	until_ten( int x )
{
	if ( x > 10 )
		return ;
	else
	{
		std::cout << x << "\n"s ;
		until_ten( x + 1 ) ;
	}
}

int	convert( int n )
{
	if ( n < 0 )
		return - convert( -n ) ;
	if ( n <= 1 )
		return n ;
	return ( n % 10 ) + ( 2 * convert(n / 10) );
}

int	input()
{
	std::cout << "> "s ;
	int x{} ;
	std::cin >> x ;
	return x ;
}

void	output( int binary )
{
	std::cout << binary << "\n"s ;
}

// tail recursion
int	factorial ( int n )
{
	if ( n < 1 )
		return 0 ;
	else if ( n == 1 )
		return 1 ;
	else
		return n * factorial( n - 1 ) ;
}

int	main()
{
	until_ten(1) ;
	while ( true )
	{
		auto decimal = input() ;
		auto binary = convert(decimal) ;
		output(binary) ;
	}
}

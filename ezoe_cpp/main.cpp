void	hello()
{
	std::cout << "hello\n"s ;
}

int	input()
{
	std::cout << ">"s ;
	int	x {} ;
	std::cin >> x ;
	return x ;
}

void	hello_n( int n )
{
	int	i = 0;
	if ( n < 0 )
		return ;
loop:
	if ( i != n )
	{
		std::cout << "hello\n"s ;
		++i ;
		goto loop ;
	}
}

int	main()
{
	/*
	std::cout << 1 ;
	goto skip ;
	std::cout << 2;
skip:
	std::cout << 3 ;
	*/

	/*
loop:
	hello() ;
	goto loop ;
	*/

	/*
	int sum = 0 ;
loop:
	int x = input() ;
	if ( x != 0 )
	{
		sum += x ;
		std::cout << sum << "\n" ;
		goto loop ;
	}
	*/
	hello_n(10);
}

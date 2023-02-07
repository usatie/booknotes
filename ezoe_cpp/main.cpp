int	input()
{
	std::cout << ">"s ;
	int	x {} ;
	std::cin >> x ;
	return x ;
}

void	sum_input_loop()
{
	int sum = 0 ;
	int x {} ;

	while ( ( x = input() ) != 0 )
	{
		sum += x ;
		std::cout << sum << "\n"s ;
	}
}

void	print_times_table_while()
{
	int a = 1 ;
	while ( a <= 9 )
	{
		int b = 1 ;
		while ( b <= 9 )
		{
			std::cout << a * b << "\t"s ;
			++b ;
		}
		std::cout << "\n"s ;
		++a ;
	}
}

void	print_times_table_goto_ezoe()
{
	int a = 1 ;
loop_outer:
	if ( a <= 9 )
	{
		int b = 1 ;
loop_inner:
		if ( b <= 9 )
		{
			std::cout << a * b << "\t"s ;
			++b ;
			goto loop_inner ;
		}
		std::cout << "\n"s ;
		++a ;
		goto loop_outer ;
	}
}

void	print_times_table_goto()
{
	int a = 1 ;
loop1:
	int b = 1 ;
loop2:
	std::cout << a * b << "\t"s ;
	++b ;
	if ( b <= 9 )
		goto loop2 ;
	std::cout << "\n"s ;
	++a ;
	if ( a <= 9 )
		goto loop1 ;
}

int	main()
{
	print_times_table_goto_ezoe() ;
}

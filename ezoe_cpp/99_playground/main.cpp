int	main()
{
	std::string s = "hello"s ;
	for ( auto i = s.begin() ; i != s.end() ; ++i )
		std::cout << *i << "\n"s ;
}

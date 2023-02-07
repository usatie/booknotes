int	main()
{
	double height{}  ;
	std::cout << "height(m)>"s ;
	std::cin >> height ;

	double mass{} ;
	std::cout << "mass(kg)>"s ;
	std::cin >> mass ;

	double bmi = mass / (height * height) ;

	std::cout << "BMI="s << bmi << "\n"s ;

	auto status = []( double bmi )
	{
		if ( bmi < 18.5 )
			return "Underweight.\n"s ;
		else if ( bmi < 25.0 )
			return "Normal.\n"s ;
		else if ( bmi < 30.0 )
			return "Overweight.\n"s ;
		else
			return "Obese.\n"s ;
		
	} ;
	
	std::cout << status(bmi) ;

	/*
	// std::cin splits input by blank and newline
	// hello world
	// hello
	std::string x{} ;
	std::cin >> x ;
	std::cout << x ;
	*/

	/*
	// hello world
	// helloworld
	std::string x{} ;
	std::string y{} ;
	std::cin >>  x >> y ;
	std::cout << x << y ;
	*/

	/*
	int i{} ;
	std::cin >> i ;
	std::cout << i << "\n"s ;
	double d{} ;
	std::cin >> d ;
	std::cout << d << "\n"s ;
	*/

	/*
	bool b{} ;

	//std::cin >> b ;
	//std::cout << std::boolalpha << b << "\n"s ;

	std::cin >> std::boolalpha >> b ;
	std::cout << std::boolalpha << b << "\n"s ;
	*/
}

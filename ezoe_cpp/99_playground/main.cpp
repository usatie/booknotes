#include <string>

int	main()
{
	std::string s ;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'C') ;
	while (std::getline(std::cin, s) )
	{
		std::cout << "[" << s << "]\n" ;
	}
}

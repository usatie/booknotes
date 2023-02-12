#include "all.h"

void	sort()
{
    std::vector<int> v = { 3,8,2,5,6,9,4,1,7 } ;
    auto size = v.size() ;

    for ( std::size_t head = 0 ; head != size ; ++head )
    {
		std::cout << "debug: head = "s << head << ", v = {"s ;
		for ( std::size_t i = 0 ; i != size ; ++i )
		{
			std::cout << v.at( i ) << " "s ;
		}
		std::cout << "}\n"s ;
        auto min = head ;
        for ( std::size_t index = head+1 ; index != size ; ++index )
        {
            if ( v.at(index) < v.at(min) )
                min = index ;
        }
        
        auto temp = v.at(head) ;
        v.at(head) = v.at(min) ;
        v.at(min) = temp ;
    }

    for ( std::size_t i = 0 ; i != size ; ++i )
    {
        std::cout << v.at(i) << " "s ;
    }
}

int	stderr_debug()
{
	int n{} ;
	std::cin >> n ;
	if ( n < 1 )
		return -1 ;

	int sum = 1 ;
	for ( int i = 2 ; i <= n ; ++i )
	{
		sum *= i ;
		std::cerr << "debug: "s << i << ", " << sum << "\n"s ;
	}
	std::cout << sum ;
	return 0 ;
}

int main()
{
	stderr_debug() ;
}

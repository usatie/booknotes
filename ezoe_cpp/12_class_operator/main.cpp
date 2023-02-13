struct S {} ;

// binary operator
S operator + ( S a, S b ) ;
// unary operator
S operator + ( S a ) ;
// prefix operator
void operator ++ ( S ) ;
// postfix operator
void operator ++ ( S, int ) ;

struct fractional
{
	int num ;
	int denom ;
} ;

// Binary Operators
fractional operator +( fractional & l, fractional & r )
{
	if ( l.denom == r.denom )
		return fractional{ l.num + r.num, l.denom } ;
	else
		return fractional{ l.num * r.denom + r.num * l.denom, l.denom * r.denom } ;
}

fractional operator -( fractional & l, fractional & r )
{
	if ( l.denom == r.denom )
		return fractional{ l.num - r.num, l.denom } ;
	else
		return fractional{ l.num * r.denom - r.num * l.denom, l.denom * r.denom } ;
}

fractional operator *( fractional & l, fractional & r )
{
	return fractional{ l.num * r.num, l.denom * r.denom } ;
}

fractional operator /( fractional & l, fractional & r )
{
	return fractional{ l.num * r.denom, l.denom * r.num } ;
}

std::ostream& operator <<( std::ostream & os, fractional & r )
{
	os << r.num << "/"s << r.denom ;
	return os ;
}

struct IntLike{ int data ; } ;

// const reference is prefered
IntLike operator + ( IntLike const & l, IntLike const & r )
{
	return IntLike{ l.data + r.data } ;
}

// Unary Operators
IntLike operator + ( IntLike const & obj )
{
	return obj ;
}

IntLike operator - ( IntLike const & obj )
{
	return IntLike{ -obj.data } ;
}
// Increment / Decrement
// prefix operators
IntLike & operator ++( IntLike & obj )
{
	++obj.data ;
	return obj ;
}
IntLike & operator --( IntLike & obj )
{
	--obj.data ;
	return obj ;
}
// postfix operators
IntLike operator ++( IntLike & obj, int ) // second arg int is dummy. Used for distinguish postfix
{
	auto temp = obj ;
	++obj.data ;
	return temp ;
}
IntLike operator --( IntLike & obj, int ) // second arg int is dummy. Used for distinguish postfix
{
	auto temp = obj ;
	--obj.data ;
	return temp ;
}

int	main()
{
	fractional a{1, 2} ;
	fractional b{1, 3} ;
	// use as operator
	{
		auto c = a + b ;
		auto d = a - b ;
		auto e = a * b ;
		auto f = a / b ;
		std::cout << "c: " << c << "\n"s ;
		std::cout << "d: " << d << "\n"s ;
		std::cout << "e: " << e << "\n"s ;
		std::cout << "f: " << f << "\n"s ;
	}
	// use like function
	{
		auto c = operator +( a, b ) ;
		auto d = operator -( a, b ) ;
		auto e = operator *( a, b ) ;
		auto f = operator /( a, b ) ;
		std::cout << "c: " << c << "\n"s ;
		std::cout << "d: " << d << "\n"s ;
		std::cout << "e: " << e << "\n"s ;
		std::cout << "f: " << f << "\n"s ;
	}
	// Increment / Decrement
	{
		int i = 0 ;
		std::cout << "i++   : "s << i++ << "\n"s ;
		std::cout << "i     : "s << i << "\n"s ;
	}
	{
		int i = 0 ;
		std::cout << "++i   : "s << ++i << "\n"s ;
		std::cout << "i     : "s << i << "\n"s ;
	}
	// prefix operator return value is reference
	{
		int i = 0 ;
		std::cout << "++++i : "s << ++++i << "\n"s ;
		std::cout << "i     : "s << i << "\n"s ;
	}
	/* compile error
	{
		int i = 0 ;
		std::cout << "i++++ : "s << i++++ << "\n"s ;
		std::cout << "i     : "s << i << "\n"s ;
	}
	*/
	// operator overloading by member function
	{
		struct S
		{
			// left operand is self, right operand is passed as arg
			S operator +( S const & right )
			{
				return S{} ;
			}
		} ;
		struct IntLike
		{
			int data ;
			IntLike operator +( IntLike const & right )
			{
				return IntLike { data + right.data } ;
			}
		} ;

		IntLike a{ 1 } ;
		IntLike b{2} ;

		IntLike c = a + b ;
		IntLike d = a.operator +(b)  ;

		std::cout << "c: "s << c.data << "\n"s ;
		std::cout << "d: "s << d.data << "\n"s ;
	}
}

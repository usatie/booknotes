namespace ns {
	int name{} ;
	int g() { return 0 ; } 
}

namespace a {
	int f() { return 0 ; } 
}

namespace b {
	int f() { return 1 ; } 
}

int f()
{
	return ns::name ;
}

// variable in global namespace
// global namespace doesn't have a name.
int x {} ;

// Nesting namespace
namespace A { namespace B { namespace C {
	int name {} ;
} } }

namespace A::B::C {
	int another_name {} ;
}

// namespace alias
// namespace {alias} = {namespace_name} ;
namespace very_long_name_space {
	int f() { return 0 ; }
}
// namespace vlns = very_long_name_space ;

// alias in namespace
namespace ns {
	namespace A { int x { } ; }
	namespace B = A ;
	int f1() { return B::x ; }
	int f2() { return B::x ; }
}

// omit namesace
// using namespace {namespace_name} ;

int omit()
{
	using namespace std ;
	string s;
	vector<int> v ;
	cout << 123 ;
	
	{
		using namespace a ;
		// compile error 
		// f() ;
		::f() ; // ok
		a::f() ; // ok
	}
}

// inline namespace
// inline namespace name { }
inline namespace A1 {
	int a1 { } ;
}

namespace B1 {
	int b1 { } ;
}

void inline_namespace()
{
	a1 = 10 ; // ok
	A1::a1 = 10 ; // ok

	// b1 = 10 ; // compile error
	B1::b1 = 10 ;
}

int	main()
{
	ns::name = 1 ;
	// compile error
	// name ;
	// g()
	ns::g() ;
	std::cout << "a::f() "s << a::f() << "\n"s ;
	std::cout << "b::f() "s << b::f() << "\n"s ;

	std::cout << "x "s << x << "\n"s ;
	std::cout << "::x "s << ::x << "\n"s ;
	std::cout << "A::B::C::name "s << A::B::C::name << "\n"s ;
	std::cout << "A::B::C::another_name "s << A::B::C::another_name << "\n"s ;
	// Alias has a scope
	{
		// Alias
		namespace vlns = very_long_name_space ;
		vlns::f() ;
		// Alias to nested namespace
		namespace D = A::B::C ;
		D::name ;
	}
	omit() ;
}

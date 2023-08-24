
#pragma once

class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{
	public:
		A();
		virtual ~A();
};

class B : public Base
{
	public:
		B();
		virtual ~B();
};

class C : public Base
{
	public:
		C();
		virtual ~C();
};

//It randomly instanciates A, B or C
Base*	generate( void );

//It prints the actual type pointed to A, B or C
void	identify( Base* p );

//It prints the actual type pointed to A, B or C
//Using a pointer inside this function is forbidden
void	identify( Base& p );
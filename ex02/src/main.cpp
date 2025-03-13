/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:42:09 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 20:56:00 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base/Base.hpp"
#include "A/A.hpp"
#include "B/B.hpp"
#include "C/C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

Base::~Base(){}
A::~A(){}
B::~B(){}
C::~C(){}
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast&) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast&) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast&) {}

	std::cout << "Unknown type" << std::endl;
}

Base* generate()
{
	int randValue = std::rand() % 3;

	if (randValue == 0)
		return new A();
	else if (randValue == 1)
		return new B();
	else
		return new C();
}

int main()
{
	std::srand(std::time(0));
	Base* obj = generate();
	std::cout << "Objeto generado en: " << obj << std::endl;
	std::cout << "Identificación por puntero: ";
	identify(obj);
	std::cout << "Identificación por referencia: ";
	identify(*obj);
	delete obj;
	return 0;
}

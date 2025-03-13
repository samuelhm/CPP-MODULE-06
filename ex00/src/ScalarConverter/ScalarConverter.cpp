/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:22 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 19:43:45 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string &literal)
{
	return (literal.length() == 3 &&
			literal[0] == '\'' &&
			literal[2] == '\'' &&
			std::isprint(literal[1]));
}

bool ScalarConverter::isPseudo(const std::string &literal)
{
	return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
			literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool ScalarConverter::isInt(const std::string &literal)
{
	if (literal.empty())
		return false;

	size_t i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;

	for (; i < literal.length(); i++)
		if (!std::isdigit(literal[i]))
			return false;
	long value = std::strtol(literal.c_str(), NULL, 10);
	return (value >= std::numeric_limits<int>::min() &&
			value <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;

	size_t len = literal.length();
	if (len < 4 || literal[len - 1] != 'f')
		return false;

	char *end;
	std::strtof(literal.c_str(), &end);
	return (*end == 'f' && end == &literal[len - 1]);
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;

	char *end;
	std::strtod(literal.c_str(), &end);
	return (*end == '\0');
}

void ScalarConverter::convert(const std::string &literal)
{
	char c;
	int i;
	float f;
	double d;

	if (isChar(literal))
	{
		c = literal[1];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (isPseudo(literal))
	{
		c = 0;
		i = 0;
		f = std::strtof(literal.c_str(), NULL);
		d = std::strtod(literal.c_str(), NULL);
	}
	else if (isInt(literal))
	{
		i = std::strtol(literal.c_str(), NULL, 10);
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	else if (isFloat(literal))
	{
		f = std::strtof(literal.c_str(), NULL);
		i = static_cast<int>(f);
		c = static_cast<char>(i);
		d = static_cast<double>(f);
	}
	else if (isDouble(literal))
	{
		d = std::strtod(literal.c_str(), NULL);
		i = static_cast<int>(d);
		c = static_cast<char>(i);
		f = static_cast<float>(d);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	
	if (isPseudo(literal) || i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (isPseudo(literal) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

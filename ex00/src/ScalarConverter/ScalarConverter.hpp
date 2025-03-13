/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:28 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 20:35:25 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <iostream>

class ScalarConverter
{
	private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter& operator=(const ScalarConverter &other);
	static bool	isChar(const std::string &literal);
	static bool	isInt(const std::string &literal);
	static bool	isDouble(const std::string &literal);
	static bool	isFloat(const std::string &literal);
	static bool	isPseudo(const std::string &literal);

	public:
	static void convert(const std::string &literal);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:19:15 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 20:31:15 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer/Serializer.hpp"

int main()
{
	Data myData = {42, "Barcelona"};

	uintptr_t raw = Serializer::serialize(&myData);
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Original address: " << &myData << std::endl;
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << "Deserialized address: " << ptr << std::endl;
	std::cout << "ID: " << ptr->id << ", Name: " << ptr->name << std::endl;

	return 0;
}

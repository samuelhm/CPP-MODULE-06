/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:18:17 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 20:34:52 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer &other);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif

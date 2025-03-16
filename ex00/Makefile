# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 11:52:37 by shurtado          #+#    #+#              #
#    Updated: 2025/03/13 20:09:14 by shurtado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Convert
CC			=	c++
CPPFLAGS	=	-std=c++98 -g -Wall -Werror -Wextra -MMD -MP -fsanitize=address -pedantic

CLASSES		=	ScalarConverter
SRC			=	$(addprefix src/, $(foreach class, $(CLASSES), $(class)/$(class).cpp) main.cpp)

OBJS		=	$(SRC:%.cpp=obj/%.o)
DEPS		=	$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCLUDES) $(CPPFLAGS) -o $@ $(OBJS) $(LDFLAGS)

obj/%.o: %.cpp Makefile
	@mkdir -p $(dir $@)
	$(CC) $(INCLUDES) $(CPPFLAGS) -c $< -o $@


clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 13:22:25 by iel-amra          #+#    #+#              #
#    Updated: 2022/01/31 13:59:16 by iel-amra         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRC=$(wildcard : *.c)
OBJ=$(SRC:.c=.o)
HEADER=libft.h

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

%o : %c $(HEADER)
	gcc -c -Werror -Wall -Wextra $<
	
clean :
	rm -f $(OBJ) $(OBJBONUS)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.SUFFIXES:

.PHONY : clean fclean all re

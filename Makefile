NAME = so_long
SRC_FILE = src
OBJ_FILE = obj
HEADER_FILE = header
SRC = $(wildcard ${SRC_FILE}/*.c)
OBJ = $(SRC:${SRC_FILE}/%.c=${OBJ_FILE}/%.o)
HEADER = $(wildcard ${HEADER_FILE}/*.h)
LIBFT = libft/libft.a 

all : checkLibft ${NAME}

${NAME} : ${OBJ} ${LIBFT}
	gcc -Wall -Werror -Wextra -fsanitize=address ${OBJ}  ${LIBFT} -LMiniLibX -lmlx -framework OpenGL -framework AppKit -o ${NAME}

checkLibft :
	make -C libft

${OBJ_FILE}/%.o : ${SRC_FILE}/%.c ${HEADER}
	gcc -Wall -Werror -Wextra -fsanitize=address -I/usr/include -IMiniLibX -O2 -include "header/principal.h" -c $< -o $@

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean ${NAME}

.PHONY : clean fclean re checkLibft

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
	gcc ${OBJ} -LMiniLibX -lmlx -L/usr/lib -IMiniLibX -lXext -lX11 -lm -lz -o ${NAME} ${LIBFT}

checkLibft :
	make -C libft

${OBJ_FILE}/%.o : ${SRC_FILE}/%.c ${HEADER}
	gcc -Wall -Werror -Wextra -I/usr/include -IMiniLibX -O3 -include "header/principal.h" -c $< -o $@

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean ${NAME}

.PHONY : clean fclean re checkLibft

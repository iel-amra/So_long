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
	gcc $(OBJ) ${LIBFT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)	

checkLibft :
	make -C libft

${OBJ_FILE}/%.o : ${SRC_FILE}/%.c ${HEADER}
	gcc -include "header/principal.h" -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O2 -c $< -o $@

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean ${NAME}

.PHONY : clean fclean re checkLibft

NAME = so_long
SRC_FILE = project/src
OBJ_FILE = project/obj
HEADER_FILE = project/header
SRC = $(wildcard ${SRC_FILE}/*.c)
OBJ = $(SRC:${SRC_FILE}/%.c=${OBJ_FILE}/%.o)
HEADER = $(wildcard ${HEADER_FILE}/*.h)
LIBFT = project/libft/libft.a 

all : ${NAME}

${NAME} : ${OBJ} FORCE
	gcc $(OBJ) ${LIBFT} -Lproject/mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)	

FORCE :
	make -C project/libft

${OBJ_FILE}/%.o : ${SRC_FILE}/%.c ${HEADER} | ${OBJ_FILE}
	gcc -include "project/header/principal.h" -Wall -Wextra -Werror -I/usr/include -Iproject/mlx_linux -O2 -c $< -o $@

${OBJ_FILE} :
	mkdir ${OBJ_FILE}

clean :
	make -C project/libft clean 
	rm -rf ${OBJ_FILE}

fclean : clean
	make -C project/libft fclean 
	rm -f ${NAME}

re : fclean ${NAME}

.PHONY : all clean fclean re FORCE

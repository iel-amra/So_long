NAME = so_long
SRC_FILE = src
OBJ_FILE = obj
HEADER_FILE = header
SRC = src/assets.c src/background.c src/cadre_frame.c src/character.c src/clean_world.c src/collectibles.c src/end.c src/enemies.c src/events.c src/free.c src/free2.c src/hit_map.c src/image_functions.c src/load_frames.c src/main.c src/map.c src/move_objects.c src/objects.c src/parsing.c src/parsing2.c src/place_enemies.c src/portal.c src/reader.c src/reset_map.c src/tileset.c src/update_char.c src/update_coll.c src/update_enemies.c src/update_objects.c src/utils.c src/wall.c src/time.c
OBJ = $(SRC:${SRC_FILE}/%.c=${OBJ_FILE}/%.o)
HEADER = ${HEADER_FILE}/principal.h
LIBFT = libft/libft.a 
MINILIBX = mlx_linux/libmlx.a

FLAG = -Wall -Werror -Wextra

all : checkLibs ${NAME}

${NAME} : ${OBJ} ${LIBFT} $(MINILIBX) Makefile
	gcc $(FLAG) ${OBJ}  ${LIBFT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

checkLibs :
	make -C libft
	make -C mlx_linux

${OBJ_FILE}/%.o : ${SRC_FILE}/%.c ${HEADER}  ${LIBFT} $(MINILIBX) | ${OBJ_FILE}
	gcc $(FLAG) -I/usr/include -Imlx_linux -O2 -include "header/principal.h" -c $< -o $@

${OBJ_FILE} :
	mkdir $@

clean :
	rm -rf ${OBJ_FILE}
	make -C libft clean
	make -C mlx_linux clean

fclean :
	rm -rf ${OBJ_FILE}
	rm -f ${NAME}
	make -C libft fclean
	make -C mlx_linux clean

re : fclean all

.PHONY : clean fclean re checkLibs all

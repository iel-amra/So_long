#ifndef PRINCIPAL_H
# define PRINCIPAL_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <time.h>

#define NB_KEYS 6
#define EP_X 30
#define EP_Y 47
#define	NB_OBJECTS 1
#define	NB_CHAR_ANIME 3
#define MAX_SPEED 3
#define GRAVITY 0.07
#define JUMP_POWER 5
#define AIR_SPEED 0.05
#define FLY_SPEED 0.02
#define	DEFAULT_WAIT 16

typedef struct timespec t_time;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int	x;
	int	y;
}	t_data;

typedef struct	s_move{
	float	x;
	float	y;
	int	old_x;
	int	old_y;
	float	speed_x;
	float	speed_y;
}	t_move;

typedef struct	s_anime{
	t_data	*frames;
	int	current_frame;
	int	total_frame;
	int	loop;
	int	wait;
	int	i;
}	t_anime;


typedef struct	s_object{
	int	x;
	int	y;
	int	current_anime;
	t_anime	*animes;
	t_move	*move;
	t_data	*img;
	t_data	hit;
	int	mirror;
}	t_object;

typedef struct	s_assets {
	char	*path;
	t_data	tileset[7][7];
	t_data	map;
	t_data	hit_map;
	char	**tab;
	unsigned char	**coder;
}	t_assets;

typedef struct		s_vars {
	void		*mlx;
	void		*win;
	int		keys[NB_KEYS];
	t_data		world[2];
	int		dis_hit[2];
	int		nloaded;
	int		closing;
	int		rendering;
	t_assets	assets;
	t_object	objects[NB_OBJECTS];
}	t_vars;

typedef struct	s_cutter {
	int	x;
	int	len_x;
	int	y;
	int	len_y;
}	t_cutter;


int	init_assets(t_assets *assets, void *mlx);
int	init_tileset(t_data tileset[7][7], void *mlx);
t_data	get_tile(void *mlx, t_data *img, t_cutter my_cutter);
void	put_tile(t_data *tile, t_data *img, int x, int y);
void	put_inverted_tile(t_data *tile, t_data *img, int x, int y);
void	cadre_frame(int *x, int *y, t_object *chara, t_data *world);
int	create_character(t_assets *assets, t_object *chara, void *mlx);
void	get_first_pos(t_object *chara, char **tab);
t_anime	*init_chara_animes(void *mlx);
int	init_char_one_anime(int i, t_anime *anime, void *mlx);
void	clean_world(t_data *world, t_object *objects, t_data *map, int color);
void	clean_background(t_data *world, t_cutter cutter, int color);
void	restore_map(t_data *world, t_object *objects, t_data *map);
void	local_restore(t_data *world, t_cutter cutter, t_data *map);
int	close_prog(t_vars *vars);
int	key_down(int keycode, t_vars *vars);
int	key_up(int keycode, t_vars *vars);
void	free_objects(t_object *objects, void *mlx);
void	free_animes(t_anime *animes, int nb, void *mlx);
void	free_frames(t_data *frames, int nb, void *mlx);
void	free_assets(void *mlx, t_assets *assets);
void	free_tileset(t_data tileset[7][7], void *mlx);
void	double_free(void *pointer);
void	build_hit(t_data *hit, int i, int j);
int	check_code(unsigned char code, int x, int y);
void	add_hit_map(t_assets *assets, int x, int y, void *mlx);
void	init_hit_map(t_assets *assets, void *mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_data *data, int x, int y);
t_data	new_image(void *mlx, int x, int y);
t_data	image_xpm(void *mlx, char *path);
void	paint_background(t_data *img, int color);
void	edit_next_frame(t_vars *vars, t_data *new);
int	render_next_frame(t_vars *vars);
int	init_vars(t_vars *vars);
void	init_world(t_vars *vars);
int	len_tab(char **tab);
void	add_map(t_assets *assets, int x, int y);
void	init_map(t_assets *assets, void *mlx);
int	get_code(char	**tab, int x, int y);
unsigned char	code_pos(char	**tab, int x, int y);
void	put_coder();
int	init_objects(t_assets *assets, t_object *objects, void *mlx);
t_data	*load_frames(char *path,  int nb_frames, void *mlx);
int	load_one_frame(t_data *frame, char *path, int i, void *mlx);
void	invert_frame(t_data *frame);
void	display_objects(t_object *objects, t_data *world, int *keys);
int	count_reader(char *path);
char	*full_reader(char *path);
char	**reader(char *path);
void	printer(unsigned char **tab);
t_time	current_time();
int	time_inf(t_time time1, t_time time2);
t_time	time_diff(t_time time1, t_time time2);
t_time	time_add(t_time time1, t_time time2);
void	time_disp(t_time time);
void	update_objects(t_object *objects, t_data *hit_map, int *keys);
void	load_anime(t_object *object, int nb, int first_frame);
void	update_character(t_object *object, t_data *hit_map, int *keys);
void	update_normal_char(t_object *object, t_data *hit_map, int *keys);
void update_ground_char(t_object *object, t_move *move, int *keys);
void	update_fly_char(t_object *object, int *keys);
void	move_objects(t_object *object, t_data *hit_map);
void	move_objects_to_dest(t_object *object, t_data *hit_map, int x_dest, int y_dest);
void	simple_move(t_object *object, int x_dest, int y_dest);
void	dicoto_move(t_object *object, t_data *hit_map, int x_dest, int y_dest);
int	wall_nearby(t_object *object, t_data *hit_map);
int	wall_one_pix(t_object *object, t_data *hit_map, int i, int j);
int	wall_collision(t_data *hit, t_data *hit_map, int x, int y);
void	anime_objects(t_object *object);
t_cutter	new_cutter(int x, int y, int len_x, int len_y);
void	draw_rectangle(t_data *img, t_cutter cutter, int color);
void draw_empty_rectangle(t_data *img, t_cutter cutter, int color);

#endif

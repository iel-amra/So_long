/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:30:39 by iel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 17:08:25 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINCIPAL_H
# define PRINCIPAL_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <time.h>
# include <sys/time.h>

# define NB_KEYS 6
# define EP_X 30
# define EP_Y 47
# define NB_CHAR_ANIME 3
# define MAX_SPEED 10
# define GRAVITY 0.8
# define JUMP_POWER 17
# define AIR_SPEED 0.8
# define FLY_SPEED 0.2
# define DEFAULT_WAIT 5

# define MULTI_COLL 3
# define SECURITY_LEN 3   
# define PRIVACY_LEN 5
# define FPS 60

typedef struct timeval	t_time;

typedef struct s_cutter {
	int	x;
	int	len_x;
	int	y;
	int	len_y;
}	t_cutter;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_data;

typedef struct s_move{
	float	x;
	float	y;
	int		begin_x;
	int		begin_y;
	float	begin_speed_x;
	float	begin_speed_y;
	int		old_x;
	int		old_y;
	float	speed_x;
	float	speed_y;
	float	accel_x;
	float	accel_y;
	int		center_x;
	int		center_y;
}	t_move;

typedef struct s_anime{
	t_data	*frames;
	int		current_frame;
	int		total_frame;
	int		loop;
	int		wait;
	int		i;
}	t_anime;

typedef struct s_object{
	int			x;
	int			y;
	int			current_anime;
	t_anime		*animes;
	t_move		*move;
	t_data		*img;
	t_data		hit;
	t_cutter	cutter;
	int			mirror;
	int			alive;
	int			finished;
	int			nb_animes;
}	t_object;

typedef struct s_assets {
	char			*path;
	t_data			tileset[7][7];
	t_data			map;
	t_data			hit_map;
	t_data			background;
	char			**tab;
	unsigned char	**coder;
	int				nb_coll;
	int				collected;
	int				nb_enemies;
	int				nb_objects;
	int				nb_portals;
	int				nb_move;
}	t_assets;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			keys[NB_KEYS];
	t_data		world[2];
	int			dis_hit[2];
	int			nloaded;
	int			closing;
	int			rendering;
	t_assets	assets;
	t_object	*objects;
}	t_vars;

int				init_assets(t_assets *assets, void *mlx);
void			init_assets_var(t_assets *assets, void *mlx);
int				get_background(t_data *background, void *mlx);
t_data			get_background_tile(void *mlx);
void			cadre_frame(int *x, int *y, t_object *chara, t_data *world);
int				create_character(t_assets *assets, t_object *chara, void *mlx);
void			create_char_move(t_object *chara, char **tab);
void			get_first_pos(int *x, int *y, char **tab, char c);
t_anime			*init_chara_animes(void *mlx);
int				init_char_one_anime(int i, t_anime *anime, void *mlx);
void			clean_world(t_data *world, t_object *objects, t_assets *assets);
void			clean_background(t_data *world, t_cutter cutter, int color);
void			restore_map(t_data *world, t_object *objects,
					t_data *map, int nb_obj);
void			local_restore(t_data *world, t_cutter cutter, t_data *map);
int				init_collectibles(char **tab, t_object *objects, void *mlx);
t_anime			*init_coll_anime(void *mlx);
int				init_multi_coll(t_object *coll, int y, int x, void *mlx);
int				init_one_coll(t_object *coll, int y, int x, void *mlx);
void			init_move_coll(t_move	*move, int x, int y);
void			check_end(t_vars *vars);
int				center_coll(t_object *object, t_object *portals, int i);
int				center_coll_hori(t_object *object, t_object *portal);
int				center_coll_verti(t_object *object, t_object *portal);
int				in_portal(t_object *chara, t_object *portal);
int				init_enemies(char **tab, t_object *objects, void *mlx);
int				init_one_enemy(t_object *enem, int y, int x, void *mlx);
void			init_move_enem(t_move *move, int x, int y);
t_anime			*init_enem_anime(void *mlx);
int				close_prog(t_vars *vars);
int				key_down(int keycode, t_vars *vars);
void			special_key_down(int keycode, t_vars *vars);
int				key_up(int keycode, t_vars *vars);
void			free_assets(void *mlx, t_assets *assets);
void			free_tileset(t_data tileset[7][7], void *mlx);
void			double_free(void *pointer);
void			free_objects(t_object *objects, void *mlx);
void			free_object(t_object *object, void *mlx);
void			free_animes(t_anime *animes, int nb, void *mlx);
void			free_frames(t_data *frames, int nb, void *mlx);
void			build_hit(t_data *hit, int i, int j);
int				check_code(unsigned char code, int x, int y);
void			add_hit_map(t_assets *assets, int x, int y, void *mlx);
void			init_hit_map(t_assets *assets, void *mlx);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_data *data, int x, int y);
t_data			new_image(void *mlx, int x, int y);
t_data			image_xpm(void *mlx, char *path);
void			paint_background(t_data *img, int color);
t_data			*load_frames(char *path, int nb_frames, void *mlx);
int				load_one_frame(t_data *frame, char *path, int i, void *mlx);
void			edit_next_frame(t_vars *vars, t_data *new);
int				render_next_frame(t_vars *vars);
int				init_vars(t_vars *vars);
void			init_world(t_vars *vars);
int				len_tab(char **tab);
void			add_map(t_assets *assets, int x, int y);
void			init_map(t_assets *assets, void *mlx);
int				get_code(char	**tab, int x, int y);
unsigned char	code_pos(char	**tab, int x, int y);
void			move_objects(t_object *object, t_data *hit_map);
void			move_objects_to_dest(t_object *object, t_data *hit_map,
					int x_dest, int y_dest);
void			update_on_coll(t_object *object, int *x_dest,
					int *y_dest, t_data *hit_map);
void			simple_move(t_object *object, int x_dest, int y_dest);
void			dicoto_move(t_object *object, t_data *hit_map,
					int x_dest, int y_dest);
int				init_objects(t_assets *assets, t_object **objects, void *mlx);
int				init_coll_and_enemy(t_assets *assets,
					t_object *objects, void *mlx);
void			display_objects(t_object *objects, t_data *world,
					int *keys, t_assets *assets);
void			display_one_object(t_object *object, t_data *world, int *keys);
int				parse_error(char *str);
int				parsing(char **tab, char *path);
int				map_rectangle(char **tab);
int				wall_surrounded(char **tab);
int				is_ber(char *path);
int				no_other(char **tab);
int				place_enemies(char **tab);
int				this_is_enemy(char **tab, int x, int y);
void			drop_char(char **tab, int *x, int *y);
int				init_portals(t_object *objects, char **tab, void *mlx);
int				init_one_portal(t_object *portal, int x, int y, void *mlx);
t_anime			*portal_anime(void *mlx);
int				count_reader(char *path);
char			*full_reader(char *path);
char			**reader(char *path);
void			reset_objects(t_object *objects);
void			reset_one_object(t_object *object);
int				init_tileset(t_data tileset[7][7], void *mlx);
t_data			get_tile(void *mlx, t_data *img, t_cutter my_cutter);
void			put_tile(t_data *tile, t_data *img, int x, int y);
void			put_inverted_tile(t_data *tile, t_data *img, int x, int y);
void			update_character(t_object *chara, t_assets *assets,
					int *keys, t_object *enem);
void			update_normal_char(t_object *object,
					t_data *hit_map, int *keys);
void			update_ground_char(t_object *object, t_move *move, int *keys);
void			update_fly_char(t_object *object, int *keys);
void			update_finished_char(t_object *chara, t_assets *assets);
void			update_colls(t_object *colls, int i,
					t_object *chara, t_assets *assets);
void			update_one_coll(t_object *coll,
					t_object *chara, t_assets *assets);
int				pixel_coll(t_object *small, t_object *big);
void			update_enemies(t_object *enemies, int i, t_data *hit_map);
void			update_one_enemy(t_object *enemy, t_data *hit_map);
int				air_below(t_object *object, t_data *hit_map);
void			update_objects(t_object *obj, t_data *hmap,
					int *keys, t_assets *assets);
void			load_anime(t_object *object, int nb, int first_frame);
void			anime_objects(t_object *object);
t_cutter		new_cutter(int x, int y, int len_x, int len_y);
void			draw_rectangle(t_data *img, t_cutter cutter, int color);
void			draw_empty_rectangle(t_data *img, t_cutter cutter, int color);
int				nb_char_in_tab(char **tab, char c);
unsigned char	**get_coder(void);
int				wall_nearby(t_object *object, t_data *hit_map);
int				wall_one_pix(t_object *object, t_data *hit_map, int i, int j);
int				wall_collision(t_data *hit, t_data *hit_map, int x, int y);
int				time_is_inf(struct timeval t1, struct timeval t2);
struct timeval	time_add(struct timeval t1, struct timeval t2);
struct timeval	time_minus(struct timeval t1, struct timeval t2);
struct timeval	ms_to_timeval(unsigned long ms);

#endif

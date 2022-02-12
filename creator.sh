(echo "#ifndef PRINCIPAL_H
# define PRINCIPAL_H

# include \"../libft/libft.h\"
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <time.h>
# include <sys/time.h>

#define NB_KEYS 6
#define EP_X 30
#define EP_Y 47
#define	NB_OBJECTS 1
#define	NB_CHAR_ANIME 3
#define MAX_SPEED 10
#define GRAVITY 0.8
#define JUMP_POWER 17
#define AIR_SPEED 0.5
#define FLY_SPEED 0.2
#define	DEFAULT_WAIT 5

#define MULTI_COLL 3
#define SECURITY_LEN 3
#define PRIVACY_LEN 5

typedef struct timeval t_time;

typedef struct	s_cutter {
	int	x;
	int	len_x;
	int	y;
	int	len_y;
}	t_cutter;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_data;

typedef struct	s_move{
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

typedef struct	s_anime{
	t_data	*frames;
	int		current_frame;
	int		total_frame;
	int		loop;
	int		wait;
	int		i;
}	t_anime;


typedef struct	s_object{
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
}	t_object;

typedef struct	s_assets {
	char			*path;
	t_data			tileset[7][7];
	t_data			map;
	t_data			hit_map;
	char			**tab;
	unsigned char	**coder;
	int				nb_coll;
	int				nb_enemies;
	int				nb_objects;
}	t_assets;

typedef struct		s_vars {
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

"
cat src/*.c | grep "^[^# 	{}].*)$" | grep -v "^int[ 	]*main(" | sed "s/$/;/" | sed -e "s/^int	/int		/" \
	-e "s/	/		/" -Ee "s/(t_cutter)	+/\1	/" -e "s/	/		/" -Ee "s/(unsigned [a-zA-Z0-9_]+)	+/\1	/"
echo "
#endif") > header/principal.h

(echo "#ifndef PRINCIPAL_H
# define PRINCIPAL_H

# include \"../libft/libft.h\"
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

"
cat src/*.c | grep "^[^# 	{}].*)$" | grep -v "^int[ 	]*main(" | sed "s/$/;/"
echo "
#endif") > header/principal.h

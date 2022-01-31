/*
typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int	x;
	int	y;
}	t_data;

typedef struct		s_vars {
	void		*mlx;
	void		*win;
	int		keys[NB_KEYS];
	t_data		img[2];
	int		nloaded;
	int		closing;
	t_assets	assets;
}	t_vars;

typedef struct	s_cutter {
	int	x;
	int	len_x;
	int	y;
	int	len_y;
}	t_cutter;

typedef struct	s_assets {
	t_data	tileset[49];
}	t_assets;

*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return(*(unsigned int*)dst);
}


int	close_prog(t_vars *vars)
{
	vars->closing = 1;
	usleep(10000);
	mlx_destroy_image(vars->mlx, vars->img[0].img);
	mlx_destroy_image(vars->mlx, vars->img[1].img);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_down(int keycode, t_vars *vars)
{
	if (keycode == 119)
		vars->keys[0] = 1;
	if (keycode == 97)
		vars->keys[1] = 1;
	if (keycode == 115)
		vars->keys[2] = 1;
	if (keycode == 100)
		vars->keys[3] = 1;
	if (keycode == 65307)
		close_prog(vars);
	return (0);
}

int	key_up(int keycode, t_vars *vars)
{
	if (keycode == 119)
		vars->keys[0] = 0;
	if (keycode == 97)
		vars->keys[1] = 0;
	if (keycode == 115)
		vars->keys[2] = 0;
	if (keycode == 100)
		vars->keys[3] = 0;
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	if (vars->closing)
		return (0);
	//paint_background((vars->img) + (vars->nloaded), 0xFFA5EEF6 );
	//void	*img = mlx_xpm_file_to_image(vars->mlx, "./img/Mossy Tileset/Mossy - TileSet.xpm", &w, &h);
	//printf("W : %i, A : %i, S : %i, D : %i\n", vars->keys[0], vars->keys[1],vars->keys[2],vars->keys[3]);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[vars->nloaded].img, 0, 0);
	vars->nloaded = 1 - vars->nloaded;
	return (0);	
}

void	init_assets(t_assets *assets, void *mlx)
{
	t_data		tileset;
	t_cutter	my_cutter;

	tileset = image_xpm(mlx, "./img/Mossy Tileset/Mossy - TileSet.xpm");
	my_cutter.x = 0;
	my_cutter.y = 0;
	my_cutter.len_x = 512;
	my_cutter.len_y = 512;
	//assets->tileset[0] = get_tile(mlx, tileset, my_cutter);
}

void	init_vars(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < NB_KEYS)
	{
		vars->keys[i] = 0;
		i++;
	}
	vars->mlx = mlx_init(); 
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Hello world!");
	vars->img[0] = new_image(vars->mlx, 1920, 1080);
	vars->img[1] = new_image(vars->mlx, 1920, 1080);
	//init_assets(&vars->assets, vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[0].img, 0, 0);
	vars->nloaded = 1;
	vars->closing = 0;
	printf("bonjour\n");
}

void	paint_background(t_data *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1920)
	{
		j = 0;
		while (j < 1080)
		{
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}

t_data	new_image(void *mlx, int x, int y)
{
	t_data	img;

	img.img = mlx_new_image(mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
			&img.line_length, &img.endian);
	img.x = x;
	img.y = y;
	return (img);
}

t_data	image_xpm(void *mlx, char *path)
{
	t_data	img;
	img.img = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
			&img.line_length, &img.endian);
	return (img);
}

t_data	get_tile(void *mlx, t_data img, t_cutter my_cutter)
{
	int	i;
	int	j;
	t_data	tile;

	tile = new_image(mlx, my_cutter.len_x, my_cutter.len_y);
	i = 0;
	while (i < my_cutter.len_x)
	{
		j = 0;
		while (j < my_cutter.len_y)
		{
			my_mlx_pixel_put(&tile, i, j, 
				my_mlx_pixel_get(&img, my_cutter.x + i, my_cutter.y + j));
			j++;
		}
		i++;
	}
	return (tile);
}

int	main()
{
	t_vars	vars;

	init_vars(&vars);
	mlx_hook(vars.win, 2, 1L<<0, key_down, &vars);
	mlx_hook(vars.win, 3, 1L<<1, key_up, &vars);
	mlx_hook(vars.win, 25, 1L<<18, close, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	//mlx_expose_hook(vars.mlx, close_prog, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

int	get_background(t_data *background, void *mlx)
{
	t_data	tile;
	int		i;
	int		j;

	tile = get_background_tile(mlx);
	if (tile.img == (void *) 0)
		return (1);
	i = 0;
	while (i < background->x)
	{
		j = 0;
		while (j < background->y)
		{
			put_tile(&tile, background, i, j);
			j += tile.y;
		}
		i += tile.x;
	}
	return (0);
}

t_data	get_background_tile(void *mlx)
{
	t_data	fond;
	t_data	ajout;

	fond = image_xpm(mlx, "img/background/Nebula Blue.xpm");
	if (fond.img == (void *) 0)
		return (fond);
	ajout = image_xpm(mlx, "img/background/Stars Small_1.xpm");
	if (ajout.img == (void *) 0)
	{
		mlx_destroy_image(mlx, fond.img);
		return (ajout);
	}
	put_tile(&ajout, &fond, 0, 0);
	mlx_destroy_image(mlx, ajout.img);
	ajout = image_xpm(mlx, "img/background/Stars-Big_1_2_PC.xpm");
	if (ajout.img == (void *) 0)
	{
		mlx_destroy_image(mlx, fond.img);
		return (ajout);
	}
	put_tile(&ajout, &fond, 0, 0);
	mlx_destroy_image(mlx, ajout.img);
	return (fond);
}

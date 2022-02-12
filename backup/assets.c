int	init_assets(t_assets *assets, void *mlx)
{
	assets->tab = reader(assets->path);
	if (!assets->tab)
		return (1);
	assets->coder = (unsigned char **) reader("coder/tileset_code.txt");
	if (!assets->coder)
	{
		double_free(assets->tab);
		return (1);
	}
	if (init_tileset(assets->tileset, mlx))
	{
		double_free(assets->tab);
		double_free(assets->coder);
		return (1);
	}
	init_map(assets, mlx);
	init_hit_map(assets, mlx);
	assets->nb_coll = nb_collectibles(assets->tab);
	return (0);
}

int	init_tileset(t_data tileset[7][7], void *mlx)
{
	int		i;
	int		j;
	t_data		tileset_img;
	t_cutter	my_cutter;

	tileset_img = image_xpm(mlx, "./img/Mossy Tileset/Mossy - TileSet.xpm");
	if (!tileset_img.img)
		return (1);
	my_cutter = new_cutter(0, 0, 128, 128);
	i = 0;
	while (i < 7)
	{
		my_cutter.x = i * 128;
		j = 0;
		while (j < 7)
		{
			my_cutter.y = j * 128;
		tileset[i][j] = get_tile(mlx, &tileset_img, my_cutter);
			j++;
		}
		i++;
	}
	mlx_destroy_image(mlx, tileset_img.img);
	return (0);
}

t_data	get_tile(void *mlx, t_data *img, t_cutter my_cutter)
{
	int	i;
	int	j;
	t_data	tile;

	tile = new_image(mlx, my_cutter.len_x, my_cutter.len_y);
	i = 0;
	while (i < my_cutter.len_x && my_cutter.x + i < img->x)
	{
		j = 0;
		while (j < my_cutter.len_y && my_cutter.y + j < img->y)
		{
			my_mlx_pixel_put(&tile, i, j, 
				my_mlx_pixel_get(img, my_cutter.x + i, my_cutter.y + j));
			j++;
		}
		i++;
	}
	return (tile);
}

void	put_tile(t_data *tile, t_data *img, int x, int y)
{
	int		i;
	int		j;
	unsigned int	color;

	i = 0;
	while (i < tile->x && i + x < img->x)
	{
		j = 0;
		while (j < tile->y && j + y < img->y)
		{
			color = my_mlx_pixel_get(tile, i,  j);
			if (color != 0xFF000000)
			my_mlx_pixel_put(img, i + x, j + y, color);
			j++;
		}
		i++;
	}
}

void	put_inverted_tile(t_data *tile, t_data *img, int x, int y)
{
	int		i;
	int		j;
	unsigned int	color;

	i = 0;
	while (i < tile->x && i + x < img->x)
	{
		j = 0;
		while (j < tile->y && j + y < img->y)
		{
			color = my_mlx_pixel_get(tile, tile->x - i, j);
			if (color != 0xFF000000)
			my_mlx_pixel_put(img, i + x, j + y, color);
			j++;
		}
		i++;
	}
}

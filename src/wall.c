int	wall_nearby(t_object *object, t_data *hit_map)
{
	int	i;
	int	j;
	int	res;
	t_data	*hit;

	hit = &object->hit;
	i = 0;
	j = 0;
	res = 0;
	while (i < hit->x)
	{
		j = 0;
		while (j < hit->y)
		{
			if (my_mlx_pixel_get(hit, i, j) == 0x000000FF)
				res = res | wall_one_pix(object, hit_map, i, j);
			j++;
		}
		i++;
	}
	return (res);
}

int	wall_one_pix(t_object *object, t_data *hit_map, int i, int j)
{
	int	res;
	int	x;
	int	y;

	x = object->x;
	y = object->y;
	res = 0;
	if (i + x >= 0 && j + y - 1 >= 0 && i + x < hit_map->x && j + y - 1 < hit_map->y
		&& my_mlx_pixel_get(hit_map, i + x, j + y - 1) == 0x00FF0000)
		res = 8;
	if (i + x + 1 >= 0 && j + y >= 0 && i + x + 1 < hit_map->x && j + y < hit_map->y
		&& my_mlx_pixel_get(hit_map, i + x + 1, j + y) == 0x00FF0000)
		res += 4;
	if (i + x >= 0 && j + y + 1 >= 0 && i + x < hit_map->x && j + y + 1 < hit_map->y
		&& my_mlx_pixel_get(hit_map, i + x, j + y + 1) == 0x00FF0000)
		res += 2;
	if (i + x - 1 >= 0 && j + y >= 0 && i + x - 1 < hit_map->x && j + y < hit_map->y
		&& my_mlx_pixel_get(hit_map, i + x - 1, j + y) == 0x00FF0000)
		res += 1;
	return (res);
}


int	wall_collision(t_data *hit, t_data *hit_map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < hit->x && i + x < hit_map->x)
	{
		j = 0;
		while (j < hit->y && j + y < hit_map->y)
		{
			if (i + x >= 0 && j + y >= 0
				&& my_mlx_pixel_get(hit, i, j) == 0x000000FF
				&& my_mlx_pixel_get(hit_map, i + x, j + y) == 0x00FF0000)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}



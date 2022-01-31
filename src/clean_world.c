void	clean_world(t_data *world, t_object *objects, t_data *map, int color)
{
	int		i;
	t_cutter	cutter;

	i = 0;
	while (i < NB_OBJECTS)
	{
		cutter = new_cutter(objects[i].move->old_x, objects[i].move->old_y, 
				objects[i].img->x, objects[i].img->y);
		clean_background(world, cutter, color);
		local_restore(world, cutter, map);
		i++;
	}
}

void	clean_background(t_data *world, t_cutter cutter, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < cutter.len_x && cutter.x + i < world->x)
	{
		j = 0;
		while (j < cutter.len_y && cutter.y + j < world->y)
		{
			if (cutter.x + i >= 0 && cutter.y + j >= 0)
				my_mlx_pixel_put(world, cutter.x + i, cutter.y + j, color);
			j++;
		}
		i++;
	}
}

void	restore_map(t_data *world, t_object *objects, t_data *map)
{
	int		i;
	t_cutter	cutter;

	i = 0;
	while (i < NB_OBJECTS)
	{
		cutter = new_cutter(objects[i].x, objects[i].move->old_y, 
				objects[i].img->x, objects[i].img->y);
		local_restore(world, cutter, map);
		i++;
	}
}

void	local_restore(t_data *world, t_cutter cutter, t_data *map)
{
	int		i;
	int		j;
	unsigned int	color;
/*
	int	count = 0;
	t_time	somme;
	somme.tv_nsec = 0;
	somme.tv_sec = 0;
*/
	i = 0;
	while (i < cutter.len_x && cutter.x + i < world->x)
	{
		j = 0;
		while (j < cutter.len_y && cutter.y + j < world->y)
		{	
			if (cutter.x + i >= 0 && cutter.y + j >= 0)
			{
				color = my_mlx_pixel_get(map, cutter.x + i, cutter.y + j);
				if (color != 0xFF000000)
				{
					//count++;
					//t_time past = current_time();
			
					my_mlx_pixel_put(world, cutter.x + i, cutter.y + j, color);
					//somme = time_add(somme, time_diff(current_time(), past));
				}
			}
			j++;
		}
		i++;
	}
	//time_disp(somme);
	//printf("count : %i\n", count);
}

int	init_objects(t_assets *assets, t_object **objects, void *mlx)
{
	*objects = malloc((1 + assets->nb_objects) * sizeof(**objects));
	if (!*objects)
		return (1);
	(*objects)[assets->nb_objects].animes = (void *) 0;
	if (create_character(assets, *objects, mlx)) // Envoie le pointeur du premier object
	{
		free(*objects);
		return (1);
	}
	if (init_portal(*objects + 1, assets->tab, mlx))
	{
		free_object(*objects, NB_CHAR_ANIME, mlx);
		free(*objects);
		return (1);
	}
	if (init_collectibles(assets->tab, *objects + 2, mlx))
	{
		free_object(*objects, NB_CHAR_ANIME, mlx);
		free_object(*objects + 1, 1, mlx);
		free(*objects);
		return (1);
	}
	if (init_enemies(assets->tab, *objects + assets->nb_coll + 2, mlx))
	{
		(*objects)[1 + assets->nb_coll].animes = (void *) 0;
		free_objects(*objects, mlx);
		free(*objects);
		return (1);
	}
	reset_objects(*objects);
	return (0);
}

t_data	*load_frames(char *path,  int nb_frames, void *mlx)
{
	int	i;
	t_data *frames;

	frames = malloc(sizeof(*frames) * nb_frames);
	if (!frames)
		return ((void *) 0);
	i = 0;
	while (i < nb_frames)
	{
		if (load_one_frame(frames + i, path, i, mlx))
		{
			free_frames(frames, i, mlx);
			return ((void *) 0);
		}
		i++;
	}
	return (frames);

}

int	load_one_frame(t_data *frame, char *path, int i, void *mlx)
{
	char	*temp;
	char 	*temp2;

	if (i <= 9)
		path = ft_strjoin(path, "0000");
	else
		path = ft_strjoin(path, "000");
	temp = ft_itoa(i);
	temp2 = ft_strjoin(path, temp);
	free(temp);
	free(path);
	path = ft_strjoin(temp2, ".xpm");
	free(temp2);
	*frame = image_xpm(mlx, path);
	free(path);
	if (!frame->img)
		return (1);
	return (0);
}
/*
void	invert_frame(t_data *frame)
{
	int		i;
	int		j;
	unsigned int	color[2];

	i = 0;
	while (i < frame->x / 2)
	{
		j = 0;
		while (j < frame->y / 2)
		{
			color[0] = my_mlx_pixel_get(frame, i, j);
			color[1] = my_mlx_pixel_get(frame, frame->x - i, frame->y - j);
			my_mlx_pixel_put(frame, i, j, color[1]);
			my_mlx_pixel_put(frame, i, j, color[0]);
			j++;
		}
		i++;
	}
}*/
/*
void	display_objects(t_object *objects, t_data *world, int *keys, int i)
{
	i--;
	while (i >= 0)
	{
		if (!objects[i].mirror)
		{
			put_tile(objects[i].img, world, objects[i].x, objects[i].y);
			if (keys[4])
				put_tile(&objects[i].hit, world, objects[i].x, objects[i].y);
		}
		else
		{
			put_inverted_tile(objects[i].img, world, objects[i].x, objects[i].y);
			if (keys[4])
				put_inverted_tile(&objects[i].hit, world, objects[i].x, objects[i].y);
		}
		i--;
	}
}
*/

void	display_objects(t_object *objects, t_data *world, int *keys, int i)
{
	i--;
	while (i >= 2)
	{
		display_one_object(objects + i, world, keys);
		i--;
	}
	display_one_object(objects, world, keys);
	display_one_object(objects + 1, world, keys);
}

void	display_one_object(t_object *object, t_data *world, int *keys)
{
		if (!object->mirror)
		{
			put_tile(object->img, world, object->x, object->y);
			if (keys[4])
				put_tile(&object->hit, world, object->x, object->y);
		}
		else
		{
			put_inverted_tile(object->img, world, object->x, object->y);
			if (keys[4])
				put_inverted_tile(&object->hit, world, object->x, object->y);
		}

}

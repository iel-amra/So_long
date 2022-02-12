int	nb_collectibles(char **tab)
{
	int	count;
	int	i;

	count = 0;
	while (*tab)
	{
		i = 0;
		while ((*tab)[i])
		{
			if ((*tab)[i] == 'C')
				count++;
			i++;
		}
		tab++;
	}
	return (count * MULTI_COLL);
}

int	init_collectibles(char **tab, t_object *objects, void *mlx)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C' && init_multi_coll(objects + count++ * MULTI_COLL, i, j, mlx))
			{
				objects[count].animes = (void *) 0;
				free_objects(objects, mlx);
				return (1);
			}	
			j++;
		}
		i++;
	}
	return (0);
}

t_anime	*init_coll_anime(void *mlx)
{
	t_anime	*anime;

	anime = malloc(sizeof(*anime));
	if (!anime)
		return ((void *) 0);
	anime->frames = load_frames("img/Potion/Health Potion ", 6, mlx);
	if (!anime->frames)
	{
		free(anime);
		return ((void *) 0);
	}
	anime->wait = DEFAULT_WAIT;
	anime->total_frame = 6;
	anime->loop = 1;
	anime->current_frame = 0;
	anime->i = 0;
	return (anime);
}

int	init_multi_coll(t_object *coll, int y, int x, void *mlx)
{
	int	i;
	
	i = 0;
	while (i < MULTI_COLL)
	{
		if (init_one_coll(coll + i, y, x, mlx))
		{
				coll[i].animes = (void *) 0;
				free_objects(coll, mlx);
				return (1);
		}
		i++;
	}
	return (0);
}

int	init_one_coll(t_object *coll, int y, int x, void *mlx)
{
	coll->move = malloc(sizeof(t_move));
	if (!coll->move)
		return (1);
	coll->animes = init_coll_anime(mlx);
	if (!coll->animes)
	{
		free(coll->move);
		return (1);
	}
	coll->current_anime = 0;
	coll->img = coll->animes[coll->current_anime].frames;
	coll->img += coll->animes[coll->current_anime].current_frame;
	coll->hit = new_image(mlx, coll->img->x, coll->img->y);
	paint_background(&coll->hit, 0xFF000000);
	coll->mirror = 0;
	init_move_coll(coll->move, x, y);
	coll->alive = 1;
	return (0);
}

void	init_move_coll(t_move	*move, int x, int y)
{
	move->begin_x = x * 128 + 20;
	move->begin_y = y * 128 + 20;
	move->center_x = x * 128 + 64 - 20;
	move->center_y = y * 128 + 64 - 20;
	move->begin_speed_x = 0;
	move->begin_speed_y = 0;
	move->accel_x = (float) rand() / (float) RAND_MAX * 0.1;
	move->accel_y = (float) rand() / (float) RAND_MAX * 0.1;
}

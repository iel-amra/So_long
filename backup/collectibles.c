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
	return (count);
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
			if (tab[i][j] == 'C' && init_one_coll(objects + count++, i, j, mlx))
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

void	free_coll(t_object *object, int len)
{
	(void) object;
	(void) len;
}

int	init_coll_anime(t_anime *anime, void *mlx)
{
	anime->frames = load_frames("img/Potion/Health Potion ", 6, mlx);
	if (!anime->frames)
		return (1);
	anime->wait = DEFAULT_WAIT;
	anime->total_frame = 6;
	anime->loop = 1;
	anime->current_frame = 0;
	anime->i = 0;
	return (0);
}

int	init_one_coll(t_object *coll, int y, int x, void *mlx)
{
	coll->animes = malloc(sizeof(*coll->animes));
	if (!coll->animes)
		return (1);
	if (init_coll_anime(coll->animes, mlx))
	{
		free(coll->animes);
		return (1);
	}
	coll->move = (void *) 0;
	coll->current_anime = 0;
	coll->img = coll->animes[coll->current_anime].frames;
	coll->img += coll->animes[coll->current_anime].current_frame;
	coll->hit = new_image(mlx, coll->img->x, coll->img->y);
	paint_background(&coll->hit, 0xFF000000);
	coll->hit.img = (void *) 0;
	coll->x = x * 128 + 22;
	coll->y = y * 128 + 10;
	coll->mirror = 0;
	return (0);
}

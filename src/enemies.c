int init_enemies(char **tab, t_object *objects, void *mlx)
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
			if (tab[i][j] == 'S' && init_one_enemy(objects + count++, i, j, mlx))
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

int	init_one_enemy(t_object *enem, int y, int x, void *mlx)
{
	enem->move = malloc(sizeof(t_move));
	if (!enem->move)
		return (1);
	enem->animes = init_enem_anime(mlx);
	if (!enem->animes)
	{
		free(enem->move);
		return (1);
	}
	enem->current_anime = 0;
	enem->img = enem->animes[enem->current_anime].frames;
	enem->img += enem->animes[enem->current_anime].current_frame;
	enem->hit = new_image(mlx, enem->img->x, enem->img->y);
	enem->cutter = new_cutter(20, 10, 70, 60);
	paint_background(&enem->hit, 0xFF000000);
	draw_empty_rectangle(&enem->hit, enem->cutter, 0x000000FF);
	enem->mirror = 0;
	init_move_enem(enem->move, x, y);
	enem->x = enem->move->x;
	enem->y = enem->move->y;
	enem->alive = 1;
	return (0);
}

void	init_move_enem(t_move *move, int x, int y)
{
	move->accel_x  = rand() % 7 + 5;
	move->begin_speed_x = move->accel_x * (rand() % 2 * 2 - 1);
	move->begin_speed_y = 0;
	move->begin_x = x * 128 + 32;
	move->begin_y = y * 128 + 70;
	move->old_x = move->x;
	move->old_y = move->y;
}

t_anime	*init_enem_anime(void *mlx)
{
	t_anime	*anime;

	anime = malloc(sizeof(*anime));
	if (!anime)
		return ((void *) 0);
	anime->frames = load_frames("img/SlimeGreen/SlimeBasic_", 30, mlx);
	if (!anime->frames)
	{
		free(anime);
		return ((void *) 0);
	}
	anime->wait = DEFAULT_WAIT;
	anime->total_frame = 30;
	anime->loop = 1;
	anime->current_frame = rand() % 30;
	anime->i = 0;
	return (anime);
}

int	create_character(t_assets *assets, t_object *chara, void *mlx)
{
	t_cutter	cutter;

	chara->move = malloc(sizeof(t_move));
	if (!chara->move)
		return (1);
	chara->animes = init_chara_animes(mlx);
	if (!chara->animes)
	{
		free (chara->move);
		return (1);
	}
	chara->current_anime = 0;
	chara->img = chara->animes[chara->current_anime].frames;
	chara->img += chara->animes[chara->current_anime].current_frame;
	chara->hit = new_image(mlx, chara->img->x, chara->img->y);
	cutter = new_cutter(80, 80, 70, 100);
	paint_background(&chara->hit, 0xFF000000);
	draw_empty_rectangle(&chara->hit, cutter, 0x000000FF);
	create_char_move(chara, assets->tab);
	chara->mirror = 0;
	chara->finished = 0;
	return (0);
}

void	create_char_move(t_object *chara, char **tab)
{
	get_first_pos(&chara->move->begin_x, &chara->move->begin_y, tab, 'P');
	chara->move->begin_x = chara->move->begin_x * 128 - 50;
	chara->move->begin_y = chara->move->begin_y * 128 - 50;
	chara->move->old_x = chara->move->begin_x;
	chara->move->old_y = chara->move->begin_y;
	chara->move->begin_speed_x = 0;
	chara->move->begin_speed_y = 0;
	chara->move->center_x = chara->move->begin_x * 128 - 50 + 64;
	chara->move->center_y = chara->move->begin_y * 128 - 50 + 64;
}

void	get_first_pos(int *x, int *y, char **tab, char c)
{
	*y = 0;
	*x = 0;

	while (tab[*y] && tab[*y][*x] != c)
	{
		*x = 0;
		while (tab[*y][*x] && tab[*y][*x] != c)
			(*x)++;
		if (tab[*y][*x] != c)
		(*y)++;
	}
}

t_anime	*init_chara_animes(void *mlx)
{
	int	i;
	t_anime	*animes;

	animes = malloc(sizeof(*animes) * NB_CHAR_ANIME);
	if (!animes)
		return ((void *) 0);
	i = 0;
	while (i < NB_CHAR_ANIME)
	{
		if (init_char_one_anime(i, animes + i, mlx))
		{
			free_animes(animes, i, mlx);
			return ((void *) 0);
		}
		i++;
	}
	return (animes);
}

int	init_char_one_anime(int i, t_anime *anime, void *mlx)
{
	anime->wait = DEFAULT_WAIT;
	anime->total_frame = 20;
	if (i == 0)
		anime->frames = load_frames("project/img/BlueWizard/2BlueWizardIdle/Chara - BlueIdle", 
				20, mlx);
	if (i == 1)
	{
		anime->frames = load_frames("project/img/BlueWizard/2BlueWizardJump/CharaWizardJump_", 
				8, mlx);
		anime->total_frame = 8;
	}
	if (i == 2)
	{
		anime->frames = load_frames("project/img/BlueWizard/2BlueWizardWalk/Chara_BlueWalk", 
				20, mlx);
		anime->wait = 1;
	}
	if (!anime->frames)
		return (1);
	anime->loop = i != 1;
	anime->current_frame = 0;
	anime->i = 0;
	return (0);
}

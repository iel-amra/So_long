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
	cutter = new_cutter(80, 80, 70, 100); // A preciser
	paint_background(&chara->hit, 0xFF000000);
	draw_empty_rectangle(&chara->hit, cutter, 0x000000FF);
	get_first_pos(chara, assets->tab);
	chara->move->speed_x = 0;
	chara->move->speed_y = 0;
	chara->move->old_x = chara->x;
	chara->move->old_y = chara->y;
	chara->move->x = chara->x;
	chara->move->y = chara->y;
	chara->mirror = 0;
	return (0);
}

void	get_first_pos(t_object *chara, char **tab)
{
	chara->y = 0;
	chara->x = 0;

	while (tab[chara->y] && tab[chara->y][chara->x] != 'P')
	{
		chara->x = 0;
		while (tab[chara->y][chara->x] && tab[chara->y][chara->x] != 'P')
			chara->x++;
		if (tab[chara->y][chara->x] != 'P')
		chara->y++;
	}
	chara->y = chara->y * 128 - 50;
	chara->x = chara->x * 128 - 50;
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
		anime->frames = load_frames("img/BlueWizard/2BlueWizardIdle/Chara - BlueIdle", 
				20, mlx);
	if (i == 1)
	{
		anime->frames = load_frames("img/BlueWizard/2BlueWizardJump/CharaWizardJump_", 
				8, mlx);
		anime->total_frame = 8;
	}
	if (i == 2)
	{
		anime->frames = load_frames("img/BlueWizard/2BlueWizardWalk/Chara_BlueWalk", 
				20, mlx);
		anime->wait = 4;
	}
	if (!anime->frames)
		return (1);
	anime->loop = i != 1;
	anime->current_frame = 0;
	anime->i = 0;
	return (0);
}

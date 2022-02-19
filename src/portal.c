int	init_portal(t_object *portal, char **tab, void *mlx)
{
	t_cutter cutter;
	
	portal->move = (void *) 0;
	get_first_pos(&portal->x, &portal->y, tab, 'E');
	portal->x = portal->x * 128 - 50;
	portal->y = portal->y * 128 - 164;
	portal->mirror = 0;
	portal->current_anime = 0;
	portal->animes = portal_anime(mlx);
	if (!portal->animes)
		return (1);
	portal->img = portal->animes[portal->current_anime].frames;
	portal->img += portal->animes[portal->current_anime].current_frame;
	portal->hit = new_image(mlx, portal->img->x, portal->img->y + 100);
	paint_background(&portal->hit, 0xFF000000);
	cutter = new_cutter(125 - MAX_SPEED - 1, 180, MAX_SPEED + 1, 128);
	//cutter = new_cutter(0, 180, 230, 128);
	draw_empty_rectangle(&portal->hit, cutter, 0x00FF00FF);
	return (0);
}

t_anime	*portal_anime(void *mlx)
{
	t_anime		*anime;
	t_cutter	cutter;

	anime = malloc(sizeof(*anime));
	if (!anime)
		return ((void *) 0);
	cutter = new_cutter(480, 480, 5, 3); 
	//anime->frames = cut_tiles_frame(cutter, mlx, "img/Pipoya VFX WarpPortal/480x480/pipo-gate01ba.xpm");
	anime->frames = load_frames("img/Plant Animations/Plant 8 Poison/PlantPosion_", 30, mlx);
	if (!anime->frames)
	{
		free(anime);
		return ((void *) 0);
	}
	anime->current_frame = 0;
	anime->total_frame = 30;
	anime->loop = 1;
	anime->wait = 3;
	anime->i = 0;
	return (anime);
}
/*
t_data	*cut_tiles_frame(t_cutter cutter, void *mlx, char *path)
{
	t_data	all_frames;
	t_data	*frames;

	frames = malloc(cutter.len_x * cutter.len_y * sizeof(*frames));
	if (!frames)
		return ((void *) 0);
	all_frames = image_xpm(mlx, path);
	if (!all_frames.img)
	{
		free(frames);
		return ((void *) 0);
	}
	cutted_tiles(cutter, &all_frames, frames, mlx);
	mlx_destroy_image(mlx, all_frames.img);
	return (frames);
}

void	cutted_tiles(t_cutter cutter, t_data *all_frames, t_data *frames, void *mlx)
{
	int			i;
	int			j;
	t_cutter	cutty;

	j = 0;
	while (j < cutter.len_y)
	{
		i = 0;
		while (i < cutter.len_x)
		{
			cutty = new_cutter(i * cutter.x, j * cutter.y, cutter.x, cutter.y); // penser a securiser
			frames[j * cutter.len_x + i] = get_tile(mlx, all_frames, cutty);
			i++;
		}
		j++;
	}
}*/

void	free_objects(t_object *objects, void *mlx)
{
	(void) mlx;
	free_animes(objects[0].animes, NB_CHAR_ANIME, mlx);
	free(objects[0].move);
	mlx_destroy_image(mlx, objects[0].hit.img);
}


void	free_animes(t_anime *animes, int nb, void *mlx)
{
	int i;

	i = 0;
	while (i < nb)
	{
		free_frames(animes[i].frames, animes[i].total_frame, mlx);
		i++;
	}
	free(animes);
}

void	free_frames(t_data *frames, int nb, void *mlx)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		mlx_destroy_image(mlx, frames[i].img);
		i++;
	}
	free(frames);
}

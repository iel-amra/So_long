void	free_objects(t_object *objects, void *mlx)
{
	int	i;

	i = 1;
	free_object(objects, NB_CHAR_ANIME, mlx);
	while (objects[i].animes)
	{
		free_object(objects + i, 1, mlx);
		i++;
	}
	free(objects);
	// penser a free les collectibles
}

void	free_object(t_object *object, int nb_anime, void *mlx)
{
	(void) nb_anime;
	free_animes(object->animes, nb_anime, mlx);
	if (object->move)
		free(object->move);
	if (object->hit.img)
		mlx_destroy_image(mlx, object->hit.img);
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

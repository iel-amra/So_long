void	update_objects(t_object *objects, t_data *hit_map, int *keys, t_assets *assets)
{
	int	i;

	update_character(objects, assets, keys, objects + assets->nb_coll + 2);
	update_colls(objects + 2, assets->nb_coll, objects, assets);
	update_enemies(objects + assets->nb_coll + 2, assets->nb_enemies, hit_map);
	i = assets->nb_objects - 1;
	while (i >= 0)
	{
		if (objects->alive)
			move_objects(objects + i, hit_map);
		else
			reset_one_object(objects + i);
		anime_objects(objects + i);
		i--;
	}
}

void	load_anime(t_object *object, int nb, int first_frame)
{
	t_anime	*anime;

	if (object->current_anime == nb)
		return ;
	object->current_anime = nb;
	anime = object->animes + nb;
	anime->current_frame = first_frame;
}

void	anime_objects(t_object *object)
{
	t_anime *anime;

	anime = object->animes + object->current_anime;
	if (anime->i < anime->wait)
	{
		anime->i++;
		return;
	}
	if (!anime->loop && anime->current_frame == anime->total_frame - 1)
		return ;
	anime->i = 0;
	anime->current_frame++;
	if (anime->current_frame == anime->total_frame)
		anime->current_frame = 0;
	object->img = &anime->frames[anime->current_frame];
}

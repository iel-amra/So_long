void	update_enemies(t_object *enemies, int i, t_data *hit_map)
{
	i--;
	while (i >= 0)
	{
		update_one_enemy(enemies + i, hit_map);
		i--;
	}
}

void	update_one_enemy(t_object *enemy, t_data *hit_map)
{
	int	radar;

	enemy->move->speed_y += GRAVITY;
	radar = wall_nearby(enemy, hit_map);
	//printf("%i\n", air_below(enemy, hit_map));
	if (!air_below(enemy, hit_map) && radar & 2)
		enemy->move->speed_x *= -1;
	if (radar & 1)
		enemy->move->speed_x = enemy->move->accel_x;
	if (radar & 4)
		enemy->move->speed_x = -enemy->move->accel_x;
}

int	air_below(t_object *object, t_data *hit_map)
{
	int	i;
	int	res;
	t_data	*hit;

	hit = &object->hit;
	i = 0;
	res = 0xFFFFFFFF;
	while (i < hit->x)
	{
		//printf("%i ", my_mlx_pixel_get(hit, i, object->cutter.y + object->cutter.len_y - 1) == 0x000000FF);
		if (my_mlx_pixel_get(hit, i, object->cutter.y + object->cutter.len_y - 1) == 0x000000FF)
			res = res & wall_one_pix(object, hit_map, i, object->cutter.y + object->cutter.len_y);
		i++;
	}
	return (res);
}

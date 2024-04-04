void	update_colls(t_object *colls, int i, t_object *chara, t_assets *assets)
{
	i--;
	while (i >= 0)
	{
		update_one_coll(colls + i, chara, assets);
		i--;
	}
}

void	update_one_coll(t_object *coll, t_object *chara, t_assets *assets)
{
	t_move	*move;

	if (pixel_coll(coll, chara))
	{
		if (coll->alive)
			assets->collected++;
		coll->alive = 0;
	}
	move = coll->move;
	if (coll->alive)
	{
		if (move->x < move->center_x)
			move->speed_x += move->accel_x;
		else
			move->speed_x -= move->accel_x;
		if (move->y < move->center_y)
			move->speed_y += move->accel_y;
		else
			move->speed_y -= move->accel_y;
	}
	else
		move->speed_y -= 0.3;
}

int	pixel_coll(t_object *small, t_object *big)
{
	int	nb;
	int	i;
	int	j;

	nb = 0;
	i = 0;
	while (i < small->img->x && i + small->x - big->x < big->img->x) 
	{
		j = 0;
		while (j < small->img->y && j + small->y - big->y < big->img->x)
		{
			if (i + small->x - big->x > 0 && j + small->y - big->y > 0
				&& my_mlx_pixel_get(small->img, i, j) != 0xFF000000
				&& my_mlx_pixel_get(big->img, i + small->x - big->x , j + small->y - big->y) != 0xFF000000)
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

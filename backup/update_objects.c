void	update_objects(t_object *objects, t_data *hit_map, int *keys, int nb_obj)
{
	int	i;

	update_character(objects, hit_map, keys);
	i = 0;
	while (i < nb_obj)
	{
		move_objects(objects + i, hit_map);
		anime_objects(objects + i);
		i++;
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

void	update_character(t_object *object, t_data *hit_map, int *keys)
{
	if (keys[1])
		object->mirror = 1;
	if (keys[3])
		object->mirror = 0;
	if (keys[5])
		update_fly_char(object, keys);
	else 
		update_normal_char(object, hit_map, keys);
}

void	update_normal_char(t_object *object, t_data *hit_map, int *keys)
{
	t_move	*move;

	move = object->move;
	move->speed_y += GRAVITY;
	if (wall_nearby(object, hit_map) & 2)
		update_ground_char(object, move, keys);
	else
	{
		load_anime(object, 1, 0);
		if (keys[1])
			move->speed_x -= AIR_SPEED;
		if (keys[3])
			move->speed_x += AIR_SPEED;
	}
	if (move->speed_x > MAX_SPEED)
		move->speed_x = MAX_SPEED;
	if (move->speed_x < -MAX_SPEED)
		move->speed_x = -MAX_SPEED;
}

void	update_ground_char(t_object *object, t_move *move, int *keys)
{
		if (keys[1])
		{
			load_anime(object, 2, 0);
			move->speed_x = -MAX_SPEED;
		}
		else if (keys[3])
		{
			load_anime(object, 2, 0);
			move->speed_x = MAX_SPEED;
		}
		else
		{
			load_anime(object, 0, 0);
			move->speed_x = 0;
		}
		if (keys[0])
			move->speed_y = -JUMP_POWER;
}

void	update_fly_char(t_object *object, int *keys)
{
	t_move	*move;
	
	move = object->move;
	load_anime(object, 1, 0);
	if (keys[1])
		move->speed_x -= FLY_SPEED;
	if (keys[3])
		move->speed_x += FLY_SPEED;
	if (keys[0])
		move->speed_y -= FLY_SPEED;
	if (keys[2])
		move->speed_y += FLY_SPEED;
}

void	move_objects(t_object *object, t_data *hit_map)
{
	int	x_dest;
	int	y_dest;

	if (!object->move)
		return ;
	object->move->old_x = object->x;
	object->move->old_y = object->y;
	x_dest = object->move->x + object->move->speed_x;
	y_dest = object->move->y + object->move->speed_y;
	move_objects_to_dest(object, hit_map, x_dest, y_dest);
}

void	move_objects_to_dest(t_object *object, t_data *hit_map, int x_dest, int y_dest)
{
	int	delta;

	if (!wall_collision(&object->hit, hit_map, x_dest, y_dest))
	{
		simple_move(object, x_dest, y_dest);
		return ;
	}
	dicoto_move(object, hit_map, x_dest, y_dest);
	delta = (object->move->speed_x > 0) * 2 - 1;
	if (wall_collision(&object->hit, hit_map, object->x + delta, object->y))
	{
		object->move->speed_x = 0;
		object->move->x = object->x;
		x_dest = object->x;
	}
	delta = (object->move->speed_y > 0) * 2 - 1;
	if (wall_collision(&object->hit, hit_map, object->x, object->y + delta))
	{
		object->move->speed_y = 0;
		object->move->y = object->y;
		y_dest = object->y;
	}
	if (y_dest == object->y || x_dest == object->x)
		move_objects_to_dest(object, hit_map, x_dest, y_dest);
}

void	simple_move(t_object *object, int x_dest, int y_dest)
{
		object->move->x += object->move->speed_x;
 		object->move->y += object->move->speed_y;
		object->x = x_dest;
		object->y = y_dest;
}

void	dicoto_move(t_object *object, t_data *hit_map, int x_dest, int y_dest)
{
	while (x_dest - object->x > 1 || y_dest - object->y > 1
			|| object->x - x_dest > 1 || object->y - y_dest > 1)
	{
		if (wall_collision(&object->hit, hit_map, (x_dest + object->x) / 2, 
					(y_dest + object->y) / 2))
		{
			x_dest = (x_dest + object->x) / 2;
			y_dest = (y_dest + object->y) / 2;
		}
		else
		{
			object->x = (x_dest + object->x) / 2;
			object->y = (y_dest + object->y) / 2;
		}
	}
}

int	wall_nearby(t_object *object, t_data *hit_map)
{
	int	i;
	int	j;
	int	res;
	t_data	*hit;

	hit = &object->hit;
	i = 0;
	j = 0;
	res = 0;
	while (i < hit->x)
	{
		j = 0;
		while (j < hit->y)
		{
			if (my_mlx_pixel_get(hit, i, j) == 0x000000FF)
				res = res | wall_one_pix(object, hit_map, i, j);
			j++;
		}
		i++;
	}
	return (res);
}

int	wall_one_pix(t_object *object, t_data *hit_map, int i, int j)
{
	int	res;
	int	x;
	int	y;

	x = object->x;
	y = object->y;
	res = 0;
	if (i + x >= 0 && j + y - 1 >= 0 && i + x < hit_map->x && j + y - 1 < hit_map->y
		&& my_mlx_pixel_get(hit_map, i + x, j + y - 1) == 0x00FF0000)
		res = 8;
	if (i + x + 1 >= 0 && j + y >= 0 && i + x + 1 < hit_map->x && j + y < hit_map->y
		&& my_mlx_pixel_get(hit_map, i + x + 1, j + y) == 0x00FF0000)
		res += 4;
	if (i + x >= 0 && j + y + 1 >= 0 && i + x < hit_map->x && j + y + 1 < hit_map->y
		&& my_mlx_pixel_get(hit_map, i + x, j + y + 1) == 0x00FF0000)
		res += 2;
	if (i + x - 1 >= 0 && j + y >= 0 && i + x - 1 < hit_map->x && j + y < hit_map->y
		&& my_mlx_pixel_get(hit_map, i + x - 1, j + y) == 0x00FF0000)
		res += 1;
	return (res);
}


int	wall_collision(t_data *hit, t_data *hit_map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < hit->x && i + x < hit_map->x)
	{
		j = 0;
		while (j < hit->y && j + y < hit_map->y)
		{
			if (i + x >= 0 && j + y >= 0
				&& my_mlx_pixel_get(hit, i, j) == 0x000000FF
				&& my_mlx_pixel_get(hit_map, i + x, j + y) == 0x00FF0000)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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

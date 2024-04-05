/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:49:29 by iel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 14:02:14 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

void	move_objects_to_dest(t_object *object, t_data *hit_map,
			int x_dest, int y_dest)
{
	if (!wall_collision(&object->hit, hit_map, x_dest, y_dest))
	{
		simple_move(object, x_dest, y_dest);
		return ;
	}
	dicoto_move(object, hit_map, x_dest, y_dest);
	update_on_coll(object, &x_dest, &y_dest, hit_map);
	if (y_dest == object->y || x_dest == object->x)
		move_objects_to_dest(object, hit_map, x_dest, y_dest);
	else
	{
		if (object->move->speed_x > 0)
			object->x++;
		else
			object->x--;
	}
}

void	update_on_coll(t_object *object, int *x_dest,
			int *y_dest, t_data *hit_map)
{
	int	delta;

	delta = (object->move->speed_x > 0) * 2 - 1;
	if (wall_collision(&object->hit, hit_map, object->x + delta, object->y))
	{
		object->move->speed_x = 0;
		object->move->x = object->x;
		*x_dest = object->x;
	}
	delta = (object->move->speed_y > 0) * 2 - 1;
	if (wall_collision(&object->hit, hit_map, object->x, object->y + delta))
	{
		object->move->speed_y = 0;
		object->move->y = object->y;
		*y_dest = object->y;
	}
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

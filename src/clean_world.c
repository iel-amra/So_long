/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:54:08 by iel-amra          #+#    #+#             */
/*   Updated: 2022/02/23 11:06:29 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	clean_world(t_data *world, t_object *objects, t_assets *assets)
{
	int			i;
	t_cutter	cutter;

	i = 0;
	while (i < assets->nb_objects)
	{
		if (objects[i].move)
			cutter = new_cutter(objects[i].move->old_x, objects[i].move->old_y,
					objects[i].img->x, objects[i].img->y);
		else
			cutter = new_cutter(objects[i].x, objects[i].y,
					objects[i].img->x, objects[i].img->y);
		local_restore(world, cutter, &assets->background);
		local_restore(world, cutter, &assets->map);
		i++;
	}
}

void	clean_background(t_data *world, t_cutter cutter, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < cutter.len_x && cutter.x + i < world->x)
	{
		j = 0;
		while (j < cutter.len_y && cutter.y + j < world->y)
		{
			if (cutter.x + i >= 0 && cutter.y + j >= 0)
				my_mlx_pixel_put(world, cutter.x + i, cutter.y + j, color);
			j++;
		}
		i++;
	}
}

void	restore_map(t_data *world, t_object *objects, t_data *map, int nb_obj)
{
	int			i;
	t_cutter	cutter;

	i = 0;
	while (i < nb_obj)
	{
		cutter = new_cutter(objects[i].x, objects[i].y,
				objects[i].img->x, objects[i].img->y);
		local_restore(world, cutter, map);
		i++;
	}
}

void	local_restore(t_data *world, t_cutter cutter, t_data *map)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < cutter.len_x && cutter.x + i < world->x)
	{
		j = 0;
		while (j < cutter.len_y && cutter.y + j < world->y)
		{	
			if (cutter.x + i >= 0 && cutter.y + j >= 0)
			{
				color = my_mlx_pixel_get(map, cutter.x + i, cutter.y + j);
				if (color != 0xFF000000)
					my_mlx_pixel_put(world, cutter.x + i, cutter.y + j, color);
			}
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:43:05 by iel-amra          #+#    #+#             */
/*   Updated: 2022/02/25 11:45:05 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	check_end(t_vars *vars)
{
	if (vars->objects->finished && in_portal(vars->objects, vars->objects + 1))
	{
		vars->rendering = 0;
		close_prog(vars);
	}
}

int	center_coll(t_object *object, t_object *portals, int i)
{
	while (i >= 0)
	{
		if (center_coll_hori(object, portals + i)
			&& center_coll_verti(object, portals + i))
			return (i + 1);
		i--;
	}
	return (0);
}

int	center_coll_hori(t_object *object, t_object *portal)
{
	int	i;

	i = 0;
	if (object->y + object->img->y / 2 < portal->y
		|| object->y + object->img->y / 2 >= portal->y + portal->hit.y)
		return (0);
	while (i < portal->hit.x)
	{
		if (my_mlx_pixel_get(&portal->hit, i,
				object->y + object->img->y / 2 - portal->y) != 0xFF000000)
			return (1);
		i++;
	}
	return (0);
}

int	center_coll_verti(t_object *object, t_object *portal)
{
	int	i;

	i = 0;
	if (object->x + object->img->x / 2 < portal->x
		|| object->x + object->img->x / 2 >= portal->x + portal->hit.x)
		return (0);
	while (i < portal->hit.y)
	{
		if (my_mlx_pixel_get(&portal->hit,
				object->x + object->img->x / 2 - portal->x, i) != 0xFF000000)
			return (1);
		i++;
	}
	return (0);
}

int	in_portal(t_object *chara, t_object *portal)
{
	if (chara->y < portal[chara->finished - 1].y)
		return (1);
	return (0);
}

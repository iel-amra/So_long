/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:34:44 by iel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 16:19:36 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	init_objects(t_assets *assets, t_object **objects, void *mlx)
{
	*objects = malloc((1 + assets->nb_objects) * sizeof(**objects));
	if (!*objects)
		return (1);
	(*objects)[assets->nb_objects].animes = (void *) 0;
	if (create_character(assets, *objects, mlx))
	{
		free(*objects);
		return (1);
	}
	if (init_portals(*objects + 1, assets->tab, mlx))
	{
		free_object(*objects, mlx);
		free(*objects);
		return (1);
	}
	if (init_coll_and_enemy(assets, *objects, mlx))
		return (1);
	reset_objects(*objects);
	return (0);
}

int	init_coll_and_enemy(t_assets *assets, t_object *objects, void *mlx)
{
	if (init_collectibles(assets->tab, objects + assets->nb_portals + 1, mlx))
	{
		objects[1 + assets->nb_portals].animes = (void *) 0;
		free_objects(objects, mlx);
		free(objects);
		return (1);
	}
	if (init_enemies(assets->tab,
			objects + assets->nb_coll + assets->nb_portals + 1, mlx))
	{
		objects[1 + assets->nb_coll + assets->nb_portals].animes
			= (void *) 0;
		free_objects(objects, mlx);
		free(objects);
		return (1);
	}
	return (0);
}

void	display_objects(t_object *objects, t_data *world,
			int *keys, t_assets *assets)
{
	int	i;

	i = assets->nb_objects - 1;
	while (i > assets->nb_portals)
	{
		display_one_object(objects + i, world, keys);
		i--;
	}
	display_one_object(objects, world, keys);
	while (i > 0)
	{
		display_one_object(objects + i, world, keys);
		i--;
	}
}

void	display_one_object(t_object *object, t_data *world, int *keys)
{
	if (!object->mirror)
	{
		put_tile(object->img, world, object->x, object->y);
		if (keys[4])
			put_tile(&object->hit, world, object->x, object->y);
	}
	else
	{
		put_inverted_tile(object->img, world, object->x, object->y);
		if (keys[4])
			put_inverted_tile(&object->hit, world, object->x, object->y);
	}
}

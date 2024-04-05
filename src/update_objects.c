/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:33:41 by iel-amra          #+#    #+#             */
/*   Updated: 2022/02/23 11:50:23 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	update_objects(t_object *obj, t_data *hmap, int *keys, t_assets *assets)
{
	int	i;

	update_character(obj, assets, keys,
		obj + assets->nb_coll + assets->nb_portals + 1);
	update_colls(obj + 1 + assets->nb_portals,
		assets->nb_coll, obj, assets);
	update_enemies(obj + assets->nb_coll + 1 + assets->nb_portals,
		assets->nb_enemies, hmap);
	i = assets->nb_objects - 1;
	while (i >= 0)
	{
		if (obj->alive)
			move_objects(obj + i, hmap);
		else
		{
			assets->nb_move = 0;
			reset_one_object(obj + i);
		}
		anime_objects(obj + i);
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
	t_anime	*anime;

	anime = object->animes + object->current_anime;
	if (anime->i < anime->wait)
	{
		anime->i++;
		return ;
	}
	if (!anime->loop && anime->current_frame == anime->total_frame - 1)
		return ;
	anime->i = 0;
	anime->current_frame++;
	if (anime->current_frame == anime->total_frame)
		anime->current_frame = 0;
	object->img = &anime->frames[anime->current_frame];
}

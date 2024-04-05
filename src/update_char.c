/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:04:03 by iel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 16:15:20 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	update_character(t_object *chara, t_assets *assets,
			int *keys, t_object *enem)
{
	int	i;

	if (chara->finished || (assets->collected == assets->nb_coll
			&& center_coll(chara, chara + 1, assets->nb_portals)))
		return (update_finished_char(chara, assets));
	if (keys[1])
		chara->mirror = 1;
	if (keys[3])
		chara->mirror = 0;
	if (keys[5])
		update_fly_char(chara, keys);
	else
		update_normal_char(chara, &assets->hit_map, keys);
	i = 0;
	while (i < assets->nb_enemies)
	{
		if (pixel_coll(enem + i, chara))
		{
			chara->alive = 0;
			assets->collected = 0;
		}
		i++;
	}
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
		if (keys[1] && move->speed_x > -MAX_SPEED)
			move->speed_x += -AIR_SPEED;
		if (keys[3] && move->speed_x < MAX_SPEED)
			move->speed_x += AIR_SPEED;
	}
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

void	update_finished_char(t_object *chara, t_assets *assets)
{
	if (!chara->finished)
	{
		chara->finished = center_coll(chara, chara + 1, assets->nb_portals);
		paint_background(&chara->hit, 0xFF000000);
		chara->move->speed_y = 0;
	}
	load_anime(chara, 1, 0);
	chara->move->speed_x = 0;
	chara->move->speed_y -= 0.2;
}

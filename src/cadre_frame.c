/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cadre_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:41:24 by iel-amra          #+#    #+#             */
/*   Updated: 2022/02/23 10:41:26 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	cadre_frame(int *x, int *y, t_object *chara, t_data *world)
{
	(void) world;
	if (world->x < 1920)
		*x = (1920 - world->x) / 2;
	else
	{
		*x = -chara->x + 1920 / 2 - 20;
		if (*x > 0)
			*x = 0;
		else if (*x < -world->x + 1920)
			*x = -world ->x + 1920;
	}
	if (world->y < 1080)
		*y = (1080 - world->y) / 2;
	else
	{
		*y = -chara->y + 1080 / 2;
		if (*y > 0)
			*y = 0;
		else if (*y < -world->y + 1080)
			*y = -world->y + 1080;
	}
}

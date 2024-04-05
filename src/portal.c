/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:22:51 by iel-amra          #+#    #+#             */
/*   Updated: 2022/02/25 11:53:01 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	init_portals(t_object *objects, char **tab, void *mlx)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'E'
				&& init_one_portal(objects + count++, j, i, mlx))
			{
				objects[--count].animes = (void *) 0;
				free_objects(objects, mlx);
				return (1);
			}	
			j++;
		}
		i++;
	}
	return (0);
}

int	init_one_portal(t_object *portal, int x, int y, void *mlx)
{
	t_cutter	cutter;

	portal->move = (void *) 0;
	portal->x = x * 128 - 50;
	portal->y = y * 128 - 164;
	portal->mirror = 0;
	portal->current_anime = 0;
	portal->nb_animes = 1;
	portal->animes = portal_anime(mlx);
	if (!portal->animes)
		return (1);
	portal->img = portal->animes[portal->current_anime].frames;
	portal->img += portal->animes[portal->current_anime].current_frame;
	portal->hit = new_image(mlx, portal->img->x, portal->img->y + 100);
	paint_background(&portal->hit, 0xFF000000);
	cutter = new_cutter(125 - MAX_SPEED - 1, 180, MAX_SPEED + 1, 128);
	draw_empty_rectangle(&portal->hit, cutter, 0x00FF00FF);
	return (0);
}

t_anime	*portal_anime(void *mlx)
{
	t_anime		*anime;

	anime = malloc(sizeof(*anime));
	if (!anime)
		return ((void *) 0);
	anime->frames
		= load_frames("img/Plant Animations/Plant 8 Poison/PlantPosion_",
			30, mlx);
	if (!anime->frames)
	{
		free(anime);
		return ((void *) 0);
	}
	anime->current_frame = 0;
	anime->total_frame = 30;
	anime->loop = 1;
	anime->wait = 3;
	anime->i = 0;
	return (anime);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:16:05 by iel-amra          #+#    #+#             */
/*   Updated: 2022/02/25 11:20:01 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	build_hit(t_data *hit, int i, int j)
{
	t_cutter	cutter;

	cutter = new_cutter(
			(-32 + 3 * EP_X / 2.0) * i * i
			+ (32 + 1 / 2.0 * EP_X) * i + 64 - EP_X,
			(-32 + 3 * EP_Y / 2.0) * j * j
			+ (32 + 1 / 2.0 * EP_Y) * j + 64 - EP_Y,
			(64 - 3 * EP_X) * i * i + 2 * EP_X,
			(64 - 3 * EP_Y) * j * j + 2 * EP_Y);
	draw_empty_rectangle(hit, cutter, 0x00FF0000);
}

int	check_code(unsigned char code, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (x == 0 && y == 0)
		return (0);
	if (code == 2)
		code = 0;
	code = (code << 1) + (code >> 7);
	while ((i != -1 || j != 0) && (x != i || y != j))
	{
		code = (code << 1) + (code >> 7);
		if ((j == -1 && i != 1) - (j == 1 && i != -1))
			i += (j == -1 && i != 1) - (j == 1 && i != -1);
		else
			j += (i == 1 && j != 1) - (i == -1 && j != -1);
	}
	return (code & 1);
}

void	add_hit_map(t_assets *assets, int x, int y, void *mlx)
{
	int		i;
	int		j;
	t_data	hit;

	if (assets->tab[y][x] != '1')
		return ;
	hit = new_image(mlx, 128, 128);
	paint_background(&hit, 0xFF000000);
	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (check_code(get_code(assets->tab, x, y), i, j))
				build_hit(&hit, i, j);
			j++;
		}
		i++;
	}
	if (get_code(assets->tab, x, y) != 16 && get_code(assets->tab, x, y) != 1)
		build_hit(&hit, 0, 0);
	put_tile(&hit, &assets->hit_map, x * 128, y * 128);
	mlx_destroy_image(mlx, hit.img);
}

void	init_hit_map(t_assets *assets, void *mlx)
{
	int	i;
	int	j;

	assets->hit_map = new_image(mlx, ft_strlen(assets->tab[0]) * 128,
			len_tab(assets->tab) * 128);
	paint_background(&assets->hit_map, 0xFF000000);
	j = 0;
	while (assets->tab[j])
	{
		i = 0;
		while (assets->tab[j][i])
		{
			add_hit_map(assets, i, j, mlx);
			i++;
		}
		j++;
	}
}

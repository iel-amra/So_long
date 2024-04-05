/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:23:26 by iel-amra          #+#    #+#             */
/*   Updated: 2022/02/25 11:23:27 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	free_assets(void *mlx, t_assets *assets)
{
	double_free(assets->tab);
	double_free(assets->coder);
	free_tileset(assets->tileset, mlx);
	mlx_destroy_image(mlx, assets->map.img);
	mlx_destroy_image(mlx, assets->hit_map.img);
}

void	free_tileset(t_data tileset[7][7], void *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			mlx_destroy_image(mlx, tileset[j][i].img);
			j++;
		}
		i++;
	}
}

void	double_free(void *pointer)
{
	void	**tab;

	tab = pointer;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(pointer);
}

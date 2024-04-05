/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:10:08 by iel-amra          #+#    #+#             */
/*   Updated: 2022/02/25 11:26:15 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

t_data	new_image(void *mlx, int x, int y)
{
	t_data	img;

	img.img = mlx_new_image(mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.x = x;
	img.y = y;
	return (img);
}

t_data	image_xpm(void *mlx, char *path)
{
	t_data	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	if (!img.img)
	{
		ft_putstr_fd("Can't find : ", 2);
		ft_putendl_fd(path, 2);
		return (img);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

void	paint_background(t_data *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->x)
	{
		j = 0;
		while (j < img->y)
		{
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}

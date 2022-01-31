t_cutter	new_cutter(int x, int y, int len_x, int len_y)
{
	t_cutter	cutter;

	cutter.x = x;
	cutter.y = y;
	cutter.len_x = len_x;
	cutter.len_y = len_y;
	return (cutter);
}

void	draw_rectangle(t_data *img, t_cutter cutter, int color)
{
	int	i;
	int	j;

	if (cutter.x < 0 || cutter.y < 0)
	{
		ft_putendl_fd("Draw rectangle with negative input", 2);
		return ;
	}
	i = 0;
	while (i + cutter.x < img->x && i < cutter.len_x)
	{
		j = 0;
		while (j + cutter.y < img->y && j < cutter.len_y)
		{
			my_mlx_pixel_put(img, i + cutter.x, j + cutter.y, color);
			j++;
		}
		i++;
	}
}

void draw_empty_rectangle(t_data *img, t_cutter cutter, int color)
{
	draw_rectangle(img, cutter, color);
	cutter.x += 1;
	cutter.y += 1;
	cutter.len_x -= 2;
	cutter.len_y -= 2;
	draw_rectangle(img, cutter, 0xFF000000);
}

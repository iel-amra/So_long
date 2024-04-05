/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:42:21 by iel-amra          #+#    #+#             */
/*   Updated: 2022/02/25 13:18:18 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

void	draw_empty_rectangle(t_data *img, t_cutter cutter, int color)
{
	draw_rectangle(img, cutter, color);
	cutter.x += 1;
	cutter.y += 1;
	cutter.len_x -= 2;
	cutter.len_y -= 2;
	draw_rectangle(img, cutter, 0xFF000000);
}

int	nb_char_in_tab(char **tab, char c)
{
	int	count;
	int	i;

	count = 0;
	while (*tab)
	{
		i = 0;
		while ((*tab)[i])
		{
			if ((*tab)[i] == c)
				count++;
			i++;
		}
		tab++;
	}
	return (count);
}

unsigned char	**get_coder(void)
{
	char	*s;
	char	*tmp;
	char	**tab;

	s = ft_strjoin("\34\37\7\4\367\375\137\n\174\377\307\104\337\177\175\n",
			"\160\361\301\100\127\165\327\n\20\21\1\2\325\135\365\n");
	if (!s)
		return ((void *) 0);
	tmp = ft_strjoin(s, "\164\305\27\35\24\25\5\n\134\107\321\161\124\125\105\n");
	free(s);
	if (!tmp)
		return ((void *) 0);
	s = ft_strjoin(tmp, "\10\3\335\167\120\121\101");
	free(tmp);
	if (!s)
		return ((void *) 0);
	tab = ft_split(s, "\n");
	free(s);
	return ((unsigned char **)tab);
}

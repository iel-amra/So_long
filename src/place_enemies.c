int place_enemies(char **tab)
{
	int	i;
	int	j;
	int	nb;

	j = 0;
	nb = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (this_is_enemy(tab, i, j))
			{
				tab[j][i] = 'S';
				nb++;
			}
			i++;
		}
		j++;
	}
	//printf("%i\n", nb);
	//printer(tab);
	return (nb);
}

int	this_is_enemy(char **tab, int x, int y)
{
	int	i;
	int	x_drop;
	int	y_drop;

	if (tab[y][x] != '0' || tab[y + 1][x] != '1')
		return (0);
	drop_char(tab, &x_drop, &y_drop);
	i = 0;
	while (i < SECURITY_LEN)
	{
		if (tab[y][x + i] == '1' || (y == y_drop && x + i == x_drop) || tab[y + 1][x + i] != '1')
				return (0);
		if (tab[y][x - i] == '1' || (y == y_drop && x - i == x_drop) || tab[y + 1][x - i] != '1')
				return (0);
		i++;
	}
	i = 0;
	while (i < PRIVACY_LEN)
	{
		if ((x - i >= 0 && tab[y][x - i] == 'S') || (x + i < len_tab(tab) && tab[y][x + i] == 'S'))
				return (0);
		i++;
	}
	return (1);
}

void	drop_char(char **tab, int *x, int *y)
{
	get_first_pos(x, y, tab, 'P');
	while (tab[(*y) + 1][*x] != '1')
		(*y)++;
}

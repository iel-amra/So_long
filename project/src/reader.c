int	count_reader(char *path)
{
	int	i;
	int	fd;
	char	c;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	while (read(fd, &c, 1))
		i++;
	close(fd);
	return (i);
}

char	*full_reader(char *path)
{
	int	fd;
	int	i;
	char	*str;
	int	len;

	len = count_reader(path) + 1;
	if (!len)
		return ((void *) 0);
	str = malloc(sizeof(char) * len);
	if (!str)
		return ((void *) 0);
	fd = open(path, O_RDONLY);
	i = 0;
	if (fd == -1)
	{
		free(str);
		return ((void *) 0);
	}
	while (read(fd, str + i, 1))
		i++;
	str[i] = '\0';
	return (str);
}

char	**reader(char *path)
{
	char	*str;
	char	**tab;

	str = full_reader(path);
	if (!str)
		return ((void *) 0);
	tab = ft_split(str, "\n");
	free(str);
	return (tab);
}

void	printer(char **tab)
{
	//int	i;

	while (*tab)
	{
		/*
		i = 0;
		while ((*tab)[i])
		{
			ft_putnbr((*tab)[i]);
			ft_putstr(" ");	
			i++;
		}
		write(1, "\n", 1);
		*/
		ft_putendl(*tab);
		tab++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:26:41 by iel-amra          #+#    #+#             */
/*   Updated: 2022/04/13 11:41:52 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	count_reader(char *path)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_putstr_fd("Can't open the file\n", 2);
		return (-1);
	}
	while (read(fd, &c, 1))
		i++;
	close(fd);
	return (i);
}

char	*full_reader(char *path)
{
	int		fd;
	int		i;
	char	*str;
	int		len;

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
	close(fd);
	return (str);
}

char	**reader(char *path)
{
	char	*str;
	char	**tab;

	str = full_reader(path);
	if (!str)
		return ((void *) 0);
	if (ft_strstr(str, "\n\n") || str[0] == '\n' || str[ft_strlen(str)] == '\n')
	{
		free(str);
		parse_error("Empty lines in file :(");
		return ((void *) 0);
	}
	tab = ft_split(str, "\n");
	free(str);
	return (tab);
}

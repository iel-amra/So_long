/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:09:27 by iel-amra          #+#    #+#             */
/*   Updated: 2021/12/01 13:46:04 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#define BUFFER_SIZE 16

int	read_in_t_list_gnl(t_list_gnl *my_strings, int fd)
{
	int		read_return;
	t_list_gnl	*travel;

	read_return = 1;
	travel = my_strings;
	while (!ft_strchr(travel->content, '\n') && read_return > 0)
	{
		travel->next = ft_lstnew_gnl((BUFFER_SIZE + 1) * sizeof(char));
		if (!travel->next)
		{
			ft_lstclear_gnl(&my_strings, free, 0);
			return (1);
		}
		travel = travel->next;
		read_return = read(fd, travel->content, BUFFER_SIZE);
		if (read_return == -1)
		{
			ft_lstclear_gnl(&my_strings, free, 0);
			return (1);
		}
		travel->content[read_return] = '\0';
	}
	return (0);
}

char	*ft_custom_strcpy(char *dst, char *src, int mode)
{
	int	i;

	i = 0;
	while (src[i] && (src[i] != '\n' || mode == 0))
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}
	dst[i] = '\0';
	return (dst + i);
}

char	*malloc_final(t_list_gnl *my_strings)
{
	int		len;
	char	*sp_pos;

	len = 1;
	while (my_strings)
	{
		sp_pos = ft_strchr(my_strings->content, '\n');
		if (!sp_pos)
			len += ft_strlen(my_strings->content);
		else
			len += sp_pos - my_strings->content + 1;
		my_strings = my_strings->next;
	}
	if (len == 1)
		return ((void *) 0);
	return (malloc(len));
}

char	*get_final(t_list_gnl *my_strings)
{
	char	*final;
	char	*travel;

	final = malloc_final(my_strings);
	if (!final)
	{
		ft_lstclear_gnl(&my_strings, free, 0);
		return ((void *) 0);
	}
	travel = final;
	while (my_strings)
	{
		travel = ft_custom_strcpy(travel, my_strings->content, 1);
		my_strings = my_strings->next;
	}
	return (final);
}

char	*get_next_line(int fd)
{
	static char	ending[BUFFER_SIZE];
	t_list_gnl		*my_strings;
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *) 0);
	my_strings = ft_lstnew_gnl((ft_strlen(ending) + 1) * sizeof(char));
	if (!my_strings)
		return ((void *) 0);
	ft_custom_strcpy(my_strings->content, ending, 0);
	if (read_in_t_list_gnl(my_strings, fd))
		return ((void *) 0);
	final = get_final(my_strings);
	if (!final)
		return ((void *) 0);
	ft_lstclear_gnl(&my_strings, free, 1);
	if (ft_strchr(my_strings->content, '\n'))
		ft_custom_strcpy(ending,
			ft_strchr(my_strings->content, '\n') + 1, 0);
	else
		ft_custom_strcpy(ending, "\0", 0);
	ft_lstclear_gnl(&my_strings, free, 0);
	return (final);
}

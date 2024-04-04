/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:11:53 by iel-amra          #+#    #+#             */
/*   Updated: 2021/12/01 13:42:34 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list_gnl	*ft_lstnew_gnl(int len)
{
	t_list_gnl	*elem;

	elem = malloc(sizeof(t_list_gnl));
	if (!elem)
		return ((void *) 0);
	elem->content = malloc(len);
	if (!elem->content)
	{
		free(elem);
		return ((void *) 0);
	}
	elem->next = ((void *) 0);
	return (elem);
}

void	ft_lstclear_gnl(t_list_gnl **lst, void (*del)(void*), int mode)
{
	t_list_gnl	*next;
	t_list_gnl	*current;

	current = *lst;
	while ((current || mode) && (current->next || !mode))
	{
		next = current->next;
		(*del)(current->content);
		free(current);
		current = next;
	}
	*lst = current;
}

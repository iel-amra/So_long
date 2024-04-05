/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:23:11 by iel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 16:21:44 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_list_gnl
{
	char				*content;
	struct s_list_gnl	*next;
}	t_list_gnl;

int			read_in_t_list_gnl(t_list_gnl *my_strings, int fd);
char		*ft_custom_strcpy(char *dst, char *src, int mode);
char		*malloc_final(t_list_gnl *my_strings);
char		*get_final(t_list_gnl *my_strings);
char		*get_next_line(int fd);
void		ft_lstclear_gnl(t_list_gnl **lst, void (*del)(void*), int mode);
t_list_gnl	*ft_lstnew_gnl(int len);
#endif

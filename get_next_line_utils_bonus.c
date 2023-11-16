/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 06:29:53 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/16 11:21:02 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	lstclear(t_list **list, int fd)
{
	t_list	*temp;
	t_list	*p_list;

	p_list = *list;
	while (p_list)
	{
		while (p_list && p_list->n_fd == fd)
		{
			free(p_list->content);
			temp = p_list->next;
			free(p_list);
			p_list = temp;
		}
		if (p_list)
			p_list = p_list->next;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	new_line(t_list *list, int fd)
{
	t_list	*p_list;
	int		i;

	i = 0;
	if (list == 0)
		return (0);
	p_list = ft_lstlast_fd(list, fd);
	while (p_list->content[i] && p_list->n_fd == fd)
	{
		if (p_list->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstlast_fd(t_list *list, int fd)
{
	if (list == 0)
		return (0);
	while (list->next)
	{
		if (list->next->content == 0)
			return (list);
		if (list->n_fd == fd)
		{
			while (list->next && list->next->n_fd == fd)
				list = list->next;
			return (list);
		}
		list = list->next;
	}
	return (list);
}

int	line_len(t_list *list, int fd)
{
	int	count;
	int	i;

	count = 0;
	while (list)
	{
		i = 0;
		while (list->content[i] && list->n_fd == fd)
		{
			if (list->content[i] == '\n')
			{
				count++;
				break ;
			}
			count++;
			i++;
		}
		list = list->next;
	}
	return (count);
}

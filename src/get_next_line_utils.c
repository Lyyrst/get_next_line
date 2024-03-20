/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:47:03 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/16 06:06:26 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	lstclear(t_list **list)
{
	t_list	*temp;
	t_list	*p_list;

	p_list = *list;
	while (p_list)
	{
		free(p_list->content);
		temp = p_list->next;
		free(p_list);
		p_list = temp;
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

int	new_line(t_list *list)
{
	t_list	*p_list;
	int		i;

	i = 0;
	if (list == 0)
		return (0);
	p_list = ft_lstlast(list);
	while (p_list->content[i])
	{
		if (p_list->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *list)
{
	if (list == 0)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}

int	line_len(t_list *list)
{
	int	count;
	int	i;

	count = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
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

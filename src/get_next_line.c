/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:43:43 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/16 09:13:38 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	empty_list(t_list **list)
{
	t_list	*p_list;
	t_list	*n;
	int		i;
	int		j;

	i = 0;
	j = 0;
	n = malloc(sizeof(t_list));
	if (!n)
		return ;
	n->next = 0;
	p_list = ft_lstlast(*list);
	while (p_list->content[i] && p_list->content[i] != '\n')
		i++;
	if (p_list->content && p_list->content[i] == '\n')
		i++;
	n->content = malloc(sizeof(char) * ((ft_strlen(p_list->content) - i) + 1));
	if (!n->content)
		return ;
	while (p_list->content[i])
		n->content[j++] = p_list->content[i++];
	n->content[j] = 0;
	lstclear(list);
	*list = n;
}

void	write_line(t_list *list, char **str)
{
	int		i;
	int		j;

	j = 0;
	str[0] = malloc(sizeof(char) * (line_len(list) + 1));
	if (!str[0])
		return ;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				str[0][j++] = list->content[i];
				break ;
			}
			str[0][j++] = list->content[i++];
		}
		list = list->next;
	}
	str[0][j] = 0;
}

void	new_node(char *str, t_list **list, int n)
{
	t_list	*node;
	int		i;
	t_list	*p_list;

	i = 0;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = 0;
	node->content = malloc (sizeof(char) * (n + 1));
	if (!node->content)
		return ;
	while (str[i] && i < n)
	{
		node->content[i] = str[i];
		i++;
	}
	node->content[i] = 0;
	if (*list == 0)
		*list = node;
	else
	{
		p_list = ft_lstlast(*list);
		p_list->next = node;
	}
}

void	stock_line(int fd, t_list **list)
{
	char	*str;
	int		n;

	n = 1;
	while (!new_line(*list) && n != 0)
	{
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return ;
		n = (int)read(fd, str, BUFFER_SIZE);
		if ((*list == NULL && n == 0) || n == -1)
		{
			free (str);
			return ;
		}
		str[n] = 0;
		new_node(str, list, n);
		free(str);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0 || fd < 0)
		return (0);
	line = 0;
	stock_line(fd, &list);
	if (!list)
		return (0);
	write_line(list, &line);
	empty_list(&list);
	if (line[0] == 0)
	{
		free(line);
		lstclear(&list);
		list = 0;
		return (0);
	}
	return (line);
}

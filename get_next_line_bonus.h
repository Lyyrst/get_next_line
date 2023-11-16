/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 06:31:13 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/16 07:08:54 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //JUST FOR MAIN//

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	int				n_fd;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*ft_lstlast_fd(t_list *list, int fd);
int		line_len(t_list *list, int fd);
int		new_line(t_list *list, int fd);
size_t	ft_strlen(const char *str);
void	lstclear(t_list **list, int fd);

#endif
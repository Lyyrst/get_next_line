/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:34:01 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/16 11:23:22 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*str;
	char	*str2;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd1);
		str2 = get_next_line(fd2);
		if (!str || !str2)
		{
			free(str);
			free(str2);
			return (0);
		}
		printf("test 1 : '%s'\n", str);
		printf("test 2 : '%s'\n", str2);
		free(str); free(str2);
	}
	return (0);
}
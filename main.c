/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:34:01 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/16 00:39:10 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int	main()
{
	int		fd;
	char	*str;

	fd = open("test", O_RDONLY);
	while (2)
	{
		str = get_next_line(fd);
		if (str == 0)
			break
		printf("%s", str);
		free(str);
	}
	return (0);
}
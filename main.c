/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwianni <dwianni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:06:02 by dwianni           #+#    #+#             */
/*   Updated: 2024/11/11 16:40:19 by dwianni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*file;
	char	*test;
	int		i;

	file = ft_strndup("read_error.txt", 0, 13);
	printf("file %s\n", file);
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (i < 5)
	{
		test = get_next_line(fd);
		printf("%s", test);
		free(test);
		i++;
	}
	free (file);
	close(fd);
	return (0);
}

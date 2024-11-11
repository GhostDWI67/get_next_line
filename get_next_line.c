/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwianni <dwianni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:31:25 by dwianni           #+#    #+#             */
/*   Updated: 2024/11/08 16:06:50 by dwianni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_endl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i]!= '\n' && i < BUFFER_SIZE)
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*next_buffer;
	char	*res;
	char	*s1;
	char	*s2;
	ssize_t	r_ctrl;

	//printf("Fd %d\n", fd);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	res = ft_strndup("\0", 1, 1);
	buffer = next_buffer;
	//printf("Strchr %s\n", ft_strchr(buffer, '\n'));
	while(ft_strchr(buffer, '\n') == NULL)
	{
		//printf("toto\n");
		r_ctrl = read (fd, buffer, BUFFER_SIZE);
		//printf("Read ctrl %ld\n", r_ctrl);
		/*
		if (r_ctrl == 0);
		{
			printf("titi\n");
			return (NULL);
		}
		*/
		//printf("Buffer %s\n", buffer);
		
		s1 = res;
		s2 = ft_strndup(buffer, 0, ft_find_endl(buffer));
		res = ft_strjoin(s1, s2);
		next_buffer = ft_strndup(buffer, ft_find_endl(buffer), BUFFER_SIZE);
		free (s1);
		free (s2);
	}
	return (res);
}
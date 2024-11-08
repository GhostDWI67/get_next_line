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

static int	ft_find_end(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i]!= '\n' && i < BUFFER_SIZE)
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*res;
	int		r_ctrl;

	res = ft_strdup("\0");
	if (fd == -1)
		return (NULL);
	while (ft_find_end(buffer) != BUFFER_SIZE)
	{
		r_ctrl = read(fd, buffer, BUFFER_SIZE);
		if (r_ctrl == -1)
			return (NULL);
		res = ft_strjoin(res, buffer);
	}
	res = ft_strjoin(res, buffer);
	return (res);
}
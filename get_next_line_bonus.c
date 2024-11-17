/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwianni <dwianni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:31:25 by dwianni           #+#    #+#             */
/*   Updated: 2024/11/15 16:23:24 by dwianni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strndup(char const *src, int first, int last)
{
	char	*dest;
	int		i;

	dest = (char *) malloc(sizeof(char) * (last - first + 2));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < (last - first + 1))
	{
		dest[i] = src[first + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_read_buffer(int fd, char *res)
{
	char	*buffer;
	char	*s1;
	ssize_t	nb_read;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (res == NULL)
		res = calloc(1, sizeof(char));
	nb_read = 1;
	while (ft_strchr(res, '\n') == NULL && nb_read != 0)
	{
		nb_read = read (fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(res);
			free(buffer);
			return (NULL);
		}
		s1 = res;
		res = ft_strjoin(s1, buffer);
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		free(s1);
	}
	free(buffer);
	return (res);
}

static int	ft_find_endl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD_OPEN];
	char		*res;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD_OPEN)
		return (NULL);
	res = NULL;
	buffer[fd] = ft_read_buffer(fd, buffer[fd]);
	if (buffer[fd] == NULL || buffer[fd][0] == 0)
	{
		free(res);
		res = NULL;
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	tmp = buffer[fd];
	res = ft_strndup(tmp, 0, ft_find_endl(buffer[fd]));
	buffer[fd] = ft_strndup(tmp, ft_find_endl(buffer[fd]) + 1,
			ft_strlen(buffer[fd]));
	free(tmp);
	tmp = NULL;
	return (res);
}

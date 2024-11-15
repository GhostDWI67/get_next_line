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
			free (res);
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

char	*get_next_line_bonus(int fd)
{
	static char	*buffer;
	char		*res;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = NULL;
	buffer = ft_read_buffer(fd, buffer);
	if (buffer == NULL || buffer[0] == 0)
	{
		free(res);
		res = NULL;
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	tmp = buffer;
	res = ft_strndup(tmp, 0, ft_find_endl(buffer));
	buffer = ft_strndup(tmp, ft_find_endl(buffer) + 1, ft_strlen(buffer));
	free(tmp);
	tmp = NULL;
	return (res);
}

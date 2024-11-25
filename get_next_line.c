/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwianni <dwianni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:31:25 by dwianni           #+#    #+#             */
/*   Updated: 2024/11/25 14:30:29 by dwianni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static void	ft_free(char **s1, char **s2)
{
	if (s1 != NULL && *s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 != NULL && *s2 != NULL)
	{
		free(*s2);
		*s2 = NULL;
	}
}

static char	*ft_read_buffer(int fd, char *res)
{
	char	*buffer;
	char	*s1;
	ssize_t	nb_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (res == NULL)
		res = ft_strndup("", 0, 0);
	nb_read = 1;
	while (ft_strchr(res, '\n') == NULL && nb_read != 0)
	{
		nb_read = read (fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			ft_free(&res, &buffer);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		s1 = res;
		res = ft_strjoin(s1, buffer);
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
	static char	*buffer;
	char		*res;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = NULL;
	buffer = ft_read_buffer(fd, buffer);
	if (buffer == NULL || buffer[0] == 0)
	{
		ft_free(&res, &buffer);
		return (NULL);
	}
	tmp = buffer;
	res = ft_strndup(tmp, 0, ft_find_endl(buffer));
	buffer = ft_strndup(tmp, ft_find_endl(buffer) + 1, ft_strlen(buffer));
	ft_free(&tmp, 0);
	return (res);
}

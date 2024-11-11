/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwianni <dwianni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:41:43 by dwianni           #+#    #+#             */
/*   Updated: 2024/11/04 16:40:29 by dwianni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compte les mots dans str // separateur c
*/

static int	ft_wcount(char const *str, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && i < ft_strlen(str))
			i++;
		if (i < ft_strlen(str))
			count++;
		while (str[i] != c && i < ft_strlen(str))
			i++;
	}
	return (count);
}

static void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		free (s[i]);
		i++;
	}
	free(s);
}

static char	**word_split(char **res, char const *s, char c)
{
	size_t	i;
	int		j;
	size_t	mem;

	i = 0;
	j = 0;
	while (j < ft_wcount(s, c))
	{
		while (s[i] == c && i < ft_strlen(s))
			i++;
		mem = i;
		while (s[i] != c && i < ft_strlen(s))
			i++;
		res[j] = ft_strndup(s, mem, i - 1);
		if (res[j] == NULL)
		{
			free_split(res);
			return (NULL);
		}
		j++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = (char **) malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	if (res == NULL)
		return (NULL);
	return (word_split(res, s, c));
}
/*
int	main(void)
{
	int		i;
	char	**test;	

	test = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	i = 0;
	while (test[i] != 0)
	{
		printf("%s\n", test[i]);
		i++;
	}
	free_split(test);
	return (0);
}
*/
/*
int	main(int argc, char **argv)
{
	int		i;
	char	**test;

	if (argc == 3)
	{
		test = ft_split(argv[1], argv[2][0]);
		i = 0;
		while (test[i] != 0)
		{
			printf("%s\n", test[i]);
			i++;
		}
		if (test[i] == 0)
			printf("chaine vide\n");
	}
	else
		printf("Pas le bon nombre d'arguments !!");
	return (0);
}
*/
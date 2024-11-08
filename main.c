/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwianni <dwianni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:06:02 by dwianni           #+#    #+#             */
/*   Updated: 2024/11/08 16:05:34 by dwianni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*file = "numbers.dict";

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	printf("%s",get_next_line(fd));
	return (0);
}
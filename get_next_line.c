/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:45 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/12 21:22:42 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	char	current;
	char	*str;

	i = 0;
	str = malloc(1024);
	if (!str)
		return (NULL);
	while (read(fd, &current, 1) != 0 && current != '\n')
	{
		str[i] = current;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s\n", s);
	s = get_next_line(fd);
	printf("%s\n", s);
	s = get_next_line(fd);
	printf("%s\n", s);
	return (0);
}
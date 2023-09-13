/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:45 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/13 09:28:41 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	char	current;
	char	*str;
	ssize_t	byte_read;

	i = 0;
	str = malloc(1);
	if (!str)
		return (NULL);
	byte_read = 1;
	while (byte_read)
	{
		byte_read = read(fd, &current, 1);
		if (!byte_read && !str)
		{
			free (str);
			return (NULL);
		}
		str[i] = current;
		if (str[i] == '\n')
			return (str);
		i++;
		str = ft_realloc_string(str, 1);
	}
	return (str);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *s = "heyy";
	int i = 0;
	
	while (i < 6)
	{
		s = get_next_line(fd);
		printf("LINE %d: %s", i, s);
		i++;
	}
	return (0);
}
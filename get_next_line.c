/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:45 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/13 12:21:46 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_string(int fd, char *s)
{
	char	*buffer;
	ssize_t	buffer_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer_read = 1;
	while (!(ft_strchr(s, '\n')) && buffer_read != 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[buffer_read] = '\0';
		s = ft_strjoin(s, buffer);
	}
	free (buffer);
	return (s);
}

char	*ft_trim_string(char *res, char *s)
{
	int	i;

	i = 0;
	while (*res != '\n')
	{
		res++;
		if (*res == '\n')
		{
			
			while(*res)
			{
				s[i] = res[i];
				
			}
		}	
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char	*res;
	char	*s = malloc(0);

	if (fd <= 0 || BUFFER_SIZE == 0)
		return (NULL);
	res = ft_fill_string(fd, s);
	if (!res)
		return (NULL);
	s = malloc((ft_strlen(res) + 1) * sizeof(char));
	res = ft_trim_string(res, s);
	return (res);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	const char *s = "heyy";

	s = get_next_line(fd);
	printf("LINE: %s", s);
	return (0);
}
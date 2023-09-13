/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:45 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/13 15:09:44 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_string(int fd, char *static_storage)
{
	char	*buffer;
	ssize_t	buffer_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer_read = 1;
	while (!(ft_strchr(static_storage, '\n')) && buffer_read != 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[buffer_read] = '\0';
		static_storage = ft_strjoin(static_storage, buffer);
	}
	free (buffer);
	return (static_storage);
}

char	*ft_cleanup_string(char *line)
{
	int		i;
	char	*clean;

	i = 0;
	while (line[i] != '\n')
	{
		i++;
	}
	clean = malloc((i + 1) * sizeof(char));
	if (!clean)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line[i] != '\n')
	{
		clean[i] = line[i];
		i++;
	}
	clean[i] = line[i];
	return (clean);
}

char	*ft_store_string(char *static_storage)
{
	int	i;
	int	j;

	i = 0;
	while (current_string[i] != '\n')
		i++;
	i++;
	j = 0;
	static_storage = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (current_string[i])
	{
		static_storage[j] = current_string[i];
		j++;
		i++;
	}
	return (static_storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_storage = ft_fill_string(fd, static_storage);//step 1
	if (!static_storage)
		return (NULL);
	line = ft_cleanup_string(static_storage);//step 2
	printf("stat_stor: %s\n", static_storage);
	static_storage = ft_store_string(static_storage);
	printf("stat_stor: %s\n", static_storage);
	return (line);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *s = "heyy";

	s = get_next_line(fd);
	printf("LINE: %s", s);
	s = get_next_line(fd);
	printf("LINE: %s", s);
	return (0);
}
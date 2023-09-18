/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:45 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/14 20:19:53 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_fill_string(int fd, char *static_storage)
{
	char	*buffer;
	int		buffer_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer_read = 1;
	while (!(ft_strchr(static_storage, '\n')) && buffer_read != 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read < 0)
		{
			free(static_storage);
			free(buffer);
			return (NULL);
		}
		buffer[buffer_read] = '\0';
		static_storage = ft_strjoin(static_storage, buffer);
	}
	free(buffer);
	return (static_storage);
}

static char	*ft_cleanup_string(char *static_storage)
{
	int		i;
	char	*clean;

	i = 0;
	if (!static_storage[i])
		return (NULL);
	while (static_storage[i] != '\0' && static_storage[i] != '\n')
		i++;
	clean = malloc((i + 2) * sizeof(char));
	if (!clean)
		return (NULL);
	i = 0;
	while (static_storage[i] != '\n' && static_storage[i] != '\0')
	{
		clean[i] = static_storage[i];
		i++;
	}
	if (static_storage[i] == '\n')
	{
		clean[i] = static_storage[i];
		i++;
	}
	clean[i] = '\0';
	return (clean);
}

static char	*ft_store_string(char *static_storage)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (static_storage[i] != '\n' && static_storage[i])
		i++;
	if (!static_storage[i])
	{
		free (static_storage);
		return (NULL);
	}
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	j = 0;
	i++;
	while (static_storage[i])
		temp[j++] = static_storage[i++];
	temp[j] = '\0';
	free(static_storage);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_storage = ft_fill_string(fd, static_storage);
	if (!static_storage)
		return (NULL);
	line = ft_cleanup_string(static_storage);
	static_storage = ft_store_string(static_storage);
	return (line);
}

/*int	main(void)
{
	int fd = open("empty.txt", O_RDONLY);
	char *s = "";

	for (int i = 0; i < 5; i++){
	printf("LINE %d: ", i);
	s = get_next_line(fd);
	free(s);
	printf("%s", s);
	}
	return (0);
}
*/
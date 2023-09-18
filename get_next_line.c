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

static char	*ft_free(char *to_free, char *tmp)
{
	if (to_free)
		free(to_free);
	to_free = NULL;
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

static char	*ft_fill_string(int fd, char *static_storage)
{
	char	*buffer;
	ssize_t	buffer_read;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (ft_free(static_storage, 0));
	buffer_read = 1;
	while (!(ft_strchr(static_storage, '\n')) && buffer_read != 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if ((buffer_read == 0 && !static_storage) || buffer_read == -1)
			return (ft_free(static_storage, buffer));
		if (buffer_read == 0)
			break ;
		buffer[buffer_read] = '\0';
		static_storage = ft_strjoin(static_storage, buffer);
		if (!static_storage)
			return(ft_free(static_storage, buffer));
	}
	free(buffer);
	return (static_storage);
}

static char	*ft_cleanup_string(char *line)
{
	int		i;
	char	*clean;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i])
		i++;
	clean = ft_calloc((i + 1), sizeof(char));
	if (!clean)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		clean[i] = line[i];
		i++;
	}
	clean[i] = line[i];
	if (line[i])
		clean[++i] = '\0';
	return (clean);
}

static char	*ft_store_string(char *static_storage)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (static_storage[i] != '\n' && static_storage[i] != '\0')
		i++;
	if (static_storage[i])
		i++;
	j = 0;
	temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!temp)
		return (NULL);
	while (static_storage[i])
		temp[j++] = static_storage[i++];
	temp[j] = '\0';
	i = -1;
	while (temp[++i])
		static_storage[i] = temp[i];
	while (static_storage[i])
		static_storage[i++] = '\0';
	static_storage[i] = '\0';
	ft_free(temp, 0);
	return (static_storage);
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
	if (line[0] == '\0')
		return (ft_free(static_storage, line));
	if (ft_strlen(line) == 0)
		return (NULL);
	return (line);
}

/*int	main(void)
{
	int fd = open("empty.txt", O_RDONLY);
	char *s = "";

	for (int i = 0; i < 5; i++){
	printf("LINE %d: ", i);
	s = get_next_line(fd);
	//free(s);
	printf("%s", s);
	}
	return (0);
}*/

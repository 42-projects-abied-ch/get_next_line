/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:45 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/14 16:36:01 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_string(int fd, char *static_storage)
{
	char	*buffer;
	ssize_t	buffer_read;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (free(buffer), NULL);
	buffer_read = 1;
	while (!(ft_strchr(static_storage, '\n')) && buffer_read != 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read == -1)
			return (free(buffer), NULL);
		if (buffer_read == 0)
			break ;
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
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i])
		i++;
	clean = ft_calloc((i + 1), sizeof(char));
	if (!clean)
		return (free(line), NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		clean[i] = line[i];
		i++;
	}
	clean[i] = line[i];
	clean[++i] = '\0';
	return (clean);
}

char	*ft_store_string(char *static_storage)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (static_storage[i] != '\n' && static_storage[i] != '\0')
		i++;
	i++;
	j = 0;
	temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!temp)
		return (free(temp), NULL);
	while (static_storage[i])
		temp[j++] = static_storage[i++];
	temp[j] = '\0';
	i = -1;
	while (temp[++i])
		static_storage[i] = temp[i];
	while (static_storage[i])
		static_storage[i++] = '\0';
	static_storage[i] = '\0';
	free(temp);
	return (static_storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!static_storage)
    	static_storage = ft_fill_string(fd, NULL);
    static_storage = ft_fill_string(fd, static_storage);
	if (!static_storage)
		return (NULL);
	line = ft_cleanup_string(static_storage);
	static_storage = ft_store_string(static_storage);
	return (line);
}

int	main(void)
{
	int fd = open("empty.txt", O_RDONLY);
	char *s = "";

	for (int i = 0; i < 5; i++){
	printf("LINE %d: ", i);
	s = get_next_line(fd);
	printf("%s", s);}
	
	return (0);
}
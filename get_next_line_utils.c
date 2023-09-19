/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:25:27 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/14 16:08:50 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *static_storage, char *buffer)
{
	char	*dest;
	size_t	j;
	int		i;

	i = -1;
	j = 0;
	if (!static_storage)
	{
		static_storage = malloc(1 * sizeof(char));
		static_storage[0] = '\0';
	}
	if (!static_storage || !buffer)
		return (NULL);
	dest = malloc((ft_strlen(static_storage) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (static_storage)
		while (static_storage[++i])
			dest[i] = static_storage[i];
	while (buffer[j])
		dest[i++] = buffer[j++];
	dest[ft_strlen(static_storage) + ft_strlen(buffer)] = '\0';
	free(static_storage);
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

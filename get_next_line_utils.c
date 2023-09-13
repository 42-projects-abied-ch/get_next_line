/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:25:27 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/13 11:36:34 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;
	size_t	s1_len;
	int		i;

	i = -1;
	s1_len = ft_strlen(s1);
	size = s1_len + ft_strlen(s2) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (0);
	while (s1[++i])
		dest[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		dest[s1_len] = s2[i];
		s1_len++;
	}
	dest[s1_len] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *) NULL);
}
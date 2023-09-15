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

void	*ft_memset(void *s, int x, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)x;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	dest = NULL;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((size * nmemb) / nmemb != size)
		return (NULL);
	dest = malloc(nmemb * size);
	if (dest == NULL)
		return (NULL);
	if (dest)
		ft_memset(dest, 0, size * nmemb);
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	s1_len;
	int		i;

	s1_len = ft_strlen(s1);
	i = -1;
	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	if (s1)
	{
		while (s1[++i])
			dest[i] = s1[i];
		free(s1);
	}
	i = -1;
	while (s2[++i])
		dest[s1_len++] = s2[i];
	dest[s1_len] = '\0';
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

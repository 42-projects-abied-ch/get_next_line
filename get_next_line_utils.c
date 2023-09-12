/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:25:27 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/12 21:11:03 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_realloc_string(char *old, size_t size)
{
	char	*new;
	int		i;

	i = -1;
	new = malloc((size + ft_strlen(old)) * sizeof(char));
	while (old[++i])
		new[i] = old[i];
	free(old);
	return (new);
}
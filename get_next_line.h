/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:23:57 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/12 21:12:27 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_realloc_string(char *old, size_t size);
size_t	ft_strlen(char *s);

#endif
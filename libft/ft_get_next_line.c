/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:46:46 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/15 15:57:17 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = ft_strlen_nl(s1);
	j = ft_strlen_nl(s2);
	dest = malloc(sizeof(char) * (i + j + 1));
	if (!dest)
		return (free(s1), NULL);
	i = -1;
	while (++i >= 0 && s1 && s1[i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j] && j < ft_strlen_nl(s2))
		dest[i++] = s2[j];
	dest[i] = '\0';
	if (s1)
		free(s1);
	return (dest);
}

static void	ft_buffer_flusher(char buffer[FOPEN_MAX][BUFFER_SIZE + 1], int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!buffer[fd][0])
		return ;
	while (i < BUFFER_SIZE && buffer[fd][i] != '\n')
		i++;
	if (buffer[fd][i] == '\n' && i < BUFFER_SIZE)
		i++;
	while (i < BUFFER_SIZE)
	{
		buffer[fd][j++] = buffer[fd][i];
		buffer[fd][i++] = '\0';
	}
	while (j < BUFFER_SIZE)
		buffer[fd][j++] = '\0';
}

char	*ft_get_next_line(int fd)
{
	char		*str;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	str = NULL;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
	{
		if (BUFFER_SIZE > 0 && fd > 0 && fd < FOPEN_MAX)
			ft_buffer_flusher(buffer, fd);
		return (NULL);
	}
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin_gnl(str, buffer[fd]);
		if (!str)
			return (NULL);
		ft_buffer_flusher(buffer, fd);
		if (str[ft_strlen_nl(str) - 1] == '\n')
			break ;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:00:32 by mlameira          #+#    #+#             */
/*   Updated: 2025/06/16 09:27:30 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_cpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	while (src[size + ++i])
		dst[i] = src[i + size];
	dst[i] = '\0';
	return (i);
}

size_t	ft_addback(char *dst, char *src, size_t size, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < size)
		dst[len + i] = src[i];
	return (size);
}

int	ft_findchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*get_lines(char *dest, char *src, char tofind)
{
	char	*ret;
	size_t	buff_len;
	size_t	i;

	i = ft_findchr(src, tofind);
	buff_len = ft_findchr(dest, '\0');
	ret = malloc(i + buff_len + 1);
	if (!ret)
		return (free(dest), NULL);
	ret[i + buff_len] = '\0';
	if (dest)
	{
		ft_addback(ret, dest, buff_len, 0);
		free(dest);
	}
	ft_addback(ret, src, i, buff_len);
	ft_cpy(src, src, i);
	return (ret);
}

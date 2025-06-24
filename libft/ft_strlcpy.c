/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:05:14 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/11/04 15:18:47 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	int		i;

	len_src = ft_strlen(src);
	if (dst == NULL || src == NULL)
		return (0);
	i = -1;
	if (size > 0)
	{
		while (src[++i] != '\0' && (size_t)i < (size - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (len_src);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:45:11 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/11/04 15:18:40 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len_dst;
	size_t		len_src;

	len_dst = ft_strlen((const char *)dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= len_dst)
		len_src += size;
	else
		len_src += len_dst;
	while (src[i] && len_dst + 1 < size)
		dst[len_dst++] = src[i++];
	dst[len_dst] = '\0';
	return (len_src);
}

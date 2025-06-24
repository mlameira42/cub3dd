/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:08:27 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/11/06 14:06:26 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*dest;

	i = -1;
	dest = (const char *)s;
	while (++i < n)
	{
		if (dest[i] == (char)c)
			return ((char *)dest + i);
	}
	return (NULL);
}

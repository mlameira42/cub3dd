/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:53:29 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/10/29 13:27:21 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*srce;
	char	*dst;
	int		i;

	i = (int)n;
	srce = (char *)src;
	dst = (char *)dest;
	if (srce < dst)
	{
		while (--i >= 0)
			dst[i] = srce[i];
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)dst);
}

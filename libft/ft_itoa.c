/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:08:04 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/11/05 11:23:29 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_pos(int n)
{
	char	*dest;
	int		temp;
	int		base_ten;

	temp = n;
	base_ten = 0;
	while (temp != 0 && base_ten++ < 11)
		temp /= 10;
	dest = malloc(sizeof(char) * (base_ten + 1));
	if (dest == NULL)
		return (NULL);
	while (n != 0)
	{
		dest[temp++] = (n % 10) + '0';
		n /= 10;
	}
	dest[temp] = '\0';
	while (n++ < temp--)
	{
		base_ten = dest[n - 1];
		dest[n - 1] = dest[temp];
		dest[temp] = base_ten;
	}
	return (dest);
}

static char	*ft_itoa_neg(int n)
{
	char	*dest;
	int		temp;
	int		base_ten;

	temp = n;
	base_ten = 0;
	while (temp != 0 && base_ten++ < 11)
		temp /= 10;
	dest = malloc(sizeof(char) * (base_ten + 2));
	if (dest == NULL)
		return (NULL);
	while (n != 0)
	{
		dest[temp++] = ((n % 10) * -1) + '0';
		n /= 10;
	}
	dest[temp++] = '-';
	dest[temp] = '\0';
	while (n++ < temp--)
	{
		base_ten = dest[n - 1];
		dest[n - 1] = dest[temp];
		dest[temp] = base_ten;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;

	if (n > 0)
		dest = ft_itoa_pos(n);
	else if (n < 0)
		dest = ft_itoa_neg(n);
	else
	{
		dest = malloc(sizeof(char) * 2);
		if (dest == NULL)
			return (NULL);
		dest[0] = '0';
		dest[1] = 0;
	}
	return (dest);
}

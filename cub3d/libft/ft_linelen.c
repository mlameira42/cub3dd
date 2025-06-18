/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:25:52 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/01/03 12:29:43 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_linelen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

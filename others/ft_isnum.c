/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:26:10 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/21 13:33:42 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_isnum(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (false);
	while (str[++i])
		if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
			return (false);
	return (true);
}

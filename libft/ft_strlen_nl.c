/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:25:52 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/12/17 15:27:27 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_nl(const char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str && str[++i])
		if (str[i] == '\n')
			return (++i);
	return (i);
}

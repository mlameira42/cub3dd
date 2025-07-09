/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:37:34 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/09 10:35:03 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_start(void)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (glob()->map[++i])
	{
		if (ft_strchr(glob()->map[i], 'N'))
			len = ft_strlen(ft_strchr(glob()->map[i], 'N'));
		else if (ft_strchr(glob()->map[i], 'S'))
			len = ft_strlen(ft_strchr(glob()->map[i], 'S'));
		else if (ft_strchr(glob()->map[i], 'E'))
			len = ft_strlen(ft_strchr(glob()->map[i], 'E'));
		else if (ft_strchr(glob()->map[i], 'W'))
			len = ft_strlen(ft_strchr(glob()->map[i], 'W'));
		if (len)
			break ;
	}
	if (i > glob()->rows)
		return ;
	glob()->start_point[0] = i;
	glob()->start_point[1] = ft_strlen(glob()->map[i]) - len;
}

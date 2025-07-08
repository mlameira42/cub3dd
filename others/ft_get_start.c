/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:37:34 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/08 12:42:32 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_start(void)
{
	int	i;
	int	j;

	i = -1;
	while (glob()->fld_map[++i])
	{
		j = -1;
		while (glob()->fld_map[i][++j])
			if (glob()->fld_map[i][++j] == 'N'
				|| glob()->fld_map[i][++j] == 'S'
				|| glob()->fld_map[i][++j] == 'E'
				|| glob()->fld_map[i][++j] == 'W'
				|| glob()->fld_map[i][++j] == '0')
				break ;
	}
	if (i > glob()->rows)
		return ;
	glob()->start_point[0] = i;
	glob()->start_point[1] = j;
}

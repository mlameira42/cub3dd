/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ver_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:30:26 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/23 12:37:29 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_ver_info(void)
{
	int	i;

	i = -1;
	if (!glob()->n_wall_tex || !glob()->s_wall_tex || !glob()->w_wall_tex
		|| !glob()->e_wall_tex || !glob()->isceilinfo || !glob()->isfloorinfo)
		return (false);
	while (++i < 3)
		if (glob()->floor_color[i] > 255 || glob()->floor_color[i] < 0
			|| glob()->ceil_color[i] > 255 || glob()->ceil_color[i] < 0)
			return (false);
	return (true);
}

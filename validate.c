/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:23:05 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/09 10:47:21 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate(char *av)
{
	ft_init_global(av);
	if (glob()->doc_len < 4)
		ft_exit(1);
	if ((ft_strncmp(glob()->doc + glob()->doc_len - 4, ".cub", 4)))
		ft_exit(1);
	if (!ft_main_ver())
		ft_exit(1);
	if (!ft_dup_map())
		ft_exit(1);
	if (glob()->start_point[0] + glob()->start_point[1] == 0)
		ft_exit(1);
	if (!ft_floodfill(glob()->fld_map, glob()->start_point[0],
			glob()->start_point[1]))
		ft_exit(1);
}

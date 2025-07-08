/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:56:16 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/08 12:15:18 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(int status)
{
	if (glob()->doc)
		free(glob()->doc);
	if (glob()->map)
		ft_free_strs(glob()->map);
	if (glob()->fld_map)
		ft_free_strs(glob()->fld_map);
	if (glob()->ceil_color)
		free(glob()->ceil_color);
	if (glob()->floor_color)
		free(glob()->floor_color);
	if (glob()->n_wall_tex)
		free(glob()->n_wall_tex);
	if (glob()->s_wall_tex)
		free(glob()->s_wall_tex);
	if (glob()->e_wall_tex)
		free(glob()->e_wall_tex);
	if (glob()->w_wall_tex)
		free(glob()->w_wall_tex);
	ft_close();
	if (status)
		ft_fprintf(2, "Error\n");
	exit(status);
}

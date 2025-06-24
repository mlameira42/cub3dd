/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:56:16 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/24 10:12:49 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(int status)
{
	if (glob()->doc)
		free(glob()->doc);
	if (glob()->map)
		ft_free_strs(glob()->map);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:56:16 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/16 09:05:03 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_game(t_game *g)
{
	int i;

	i = -1;
	if (glob()->render.mlx)
	{
		while (++i < 4)
			if (g->wall_text[i].img)
				mlx_destroy_image(g->mlx, g->wall_text[i].img);
		if (g->sprite_tex.img)
			mlx_destroy_image(g->mlx, g->sprite_tex.img);
		if (g->img)
			mlx_destroy_image(g->mlx, g->img);
		if (g->win)
			mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
		mlx_loop_end(g->mlx);
		free(g->mlx);
	}
}

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
	free_game(&glob()->render);
	ft_close();
	if (status)
		ft_fprintf(2, "Error\n");
	exit(status);
}

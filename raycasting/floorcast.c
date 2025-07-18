/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:15:29 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/17 10:40:39 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	value_init(t_rays *ray1, t_rays *ray2, t_floor *floor, int y)
{
	ray1->raydirx = glob()->render.dirx - glob()->render.planex;
	ray1->raydirx = glob()->render.diry - glob()->render.planey;
	ray2->raydirx = glob()->render.dirx + glob()->render.planex;
	ray2->raydirx = glob()->render.diry + glob()->render.planey;
	floor->p = y - SCREEN_H / 2;
	floor->rawdistance = (float)(0.5 * SCREEN_H) / floor->p;
	floor->floorstepx = floor->rawdistance * (ray2->raydirx - ray1->raydirx)
		/ SCREEN_W;
	floor->floorstepy = floor->rawdistance * (ray2->raydiry - ray1->raydiry)
		/ SCREEN_W;
	floor->floorx = glob()->render.x + floor->rawdistance * ray1->raydirx;
	floor->floory = glob()->render.y + floor->rawdistance * ray1->raydiry;
}

void	floorcast(t_game *g, t_floor *floor)
{
	t_rays	ray1;
	t_rays	ray2;
	int		y;
	int		x;

	y = -1;
	while (++y < g->mapsize[0])
	{
		value_init(&ray1, &ray2, floor, y);
		x = -1;
		while (++x < g->mapsize[1])
		{
			ray1.color = g->floor_tex;
			g->pixels[SCREEN_W * y + x] = ray1.color;
			ray2.color = g->ceil;
			g->pixels[SCREEN_W * (SCREEN_H - y - 1) + x] = ray2.color;
		}
	}
}

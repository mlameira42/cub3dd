/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:15:29 by mlameira          #+#    #+#             */
/*   Updated: 2025/06/23 11:50:33 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	value_init(t_game *g, t_rays *ray1, t_rays *ray2, t_floor *floor, int y)
{
		ray1->rayDirX = g->dirX - g->planeX;
		ray1->rayDirX = g->dirY - g->planeY;
		ray2->rayDirX = g->dirX + g->planeX;
		ray2->rayDirX = g->dirY + g->planeY;
		floor->p = y - SCREEN_H / 2;
		floor->rawDistance = (float)(0.5 * SCREEN_H) / floor->p;
		floor->floorStepX = floor->rawDistance * (ray2->rayDirX - ray1->rayDirX) / SCREEN_W;
    	floor->floorStepY = floor->rawDistance * (ray2->rayDirY - ray1->rayDirY) / SCREEN_W;
		floor->floorX = g->x + floor->rawDistance * ray1->rayDirX;
		floor->floorY = g->y + floor->rawDistance * ray1->rayDirY;
}

void	floorcast(t_game *g)
{
	t_rays	ray1;
	t_rays	ray2;
	t_floor	floor;
	int		y;
	int		x;

	
	y = -1;
	while (++y < g->mapsize[0])
	{
		value_init(g, &ray1, &ray2, &floor, y);
		x = -1;
		while(++x < g->mapsize[1])
		{
			floor.tx = (int)(g->floor_tex.txt_w * (floor.floorX - (int)(floor.floorX))) & (g->floor_tex.txt_w - 1);
			floor.ty = (int)(g->floor_tex.txt_h * (floor.floorY - (int)(floor.floorY))) & (g->floor_tex.txt_h - 1);
			floor.floorX += floor.floorStepX;
			floor.floorY += floor.floorStepY;
			ray1.color = g->floor_tex.tex[g->floor_tex.txt_w * floor.ty + floor.tx];
			g->pixels[SCREEN_W * y + x] = ray1.color;
			ray1.color = (ray1.color >> 1) & 8355711;
			g->pixels[SCREEN_W * (SCREEN_H - y - 1) + x] = ray1.color;
		}
		
	}
}

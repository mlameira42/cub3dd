/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dd_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:18:07 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/17 12:43:56 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	deltadistances(t_rays *ray)
{
	if (ray->raydirx == 0)
		ray->deltadistx = 1e30;
	else
		ray->deltadistx = fabs(1 / ray->raydirx);
	if (ray->raydiry == 0)
		ray->deltadisty = 1e30;
	else
		ray->deltadisty = fabs(1 / ray->raydiry);
}

void	rays_innit(t_rays *ray, t_game *g)
{
	ray->side = 0;
	deltadistances(ray);
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (g->x - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - g->x) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (g->y - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - g->y) * ray->deltadisty;
	}
}

void	get_wall_side(t_game *g, t_rays *rays)
{
	if (rays->side == 0)
	{
		if (g->dirx < 0)
			g->texside = WEST;
		else
			g->texside = EAST;
	}
	else
	{
		if (g->diry > 0)
			g->texside = SOUTH;
		else
			g->texside = NORTH;
	}
}

void	draw3d(t_game *g, t_rays *rays, int x, int h)
{
	int	lineheight;

	if (rays->side == 0)
		rays->prepdist = (rays->sidedistx - rays->deltadistx);
	else
		rays->prepdist = (rays->sidedisty - rays->deltadisty);
	lineheight = (int)(h / rays->prepdist);
	rays->drawstart = (-lineheight / 2) + (h / 2);
	rays->drawend = (lineheight / 2) + (h / 2);
	if (rays->drawstart < 0)
		rays->drawstart = 0;
	if (rays->drawend >= h)
		rays->drawend = h - 1;
	get_wall_side(g, rays);
	apply_texture(rays, g, x, lineheight);
	glob()->render.sprite_tex.zbuffer[x] = rays->prepdist;
}

t_rays	dda_ray(t_game *g, int x, int w, int h)
{
	t_rays	ray;

	ray.raydirx = g->dirx + g->planex * (double)(2 * x / (double)w - 1);
	ray.raydiry = g->diry + g->planey * (double)(2 * x / (double)w - 1);
	ray.mapx = (int)g->x;
	ray.mapy = (int)g->y;
	rays_innit(&ray, g);
	while (glob()->map[ray.mapy] && glob()->map[ray.mapy][ray.mapx] != '1')
	{
		sprite_visibility(g, ray.mapx, ray.mapy);
		if (ray.sidedistx < ray.sidedisty)
		{
			ray.sidedistx += ray.deltadistx;
			ray.mapx += ray.stepx;
			ray.side = 0;
		}
		else
		{
			ray.sidedisty += ray.deltadisty;
			ray.mapy += ray.stepy;
			ray.side = 1;
		}
	}
	draw3d(g, &ray, x, h);
	return (ray);
}

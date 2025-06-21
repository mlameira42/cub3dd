/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dd_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:18:07 by mlameira          #+#    #+#             */
/*   Updated: 2025/06/21 14:37:40 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
void    deltadistances(t_rays *ray)
{
    if (ray->rayDirX == 0)
        ray->deltaDistX = 1e30;
    else
        ray->deltaDistX = fabs(1 / ray->rayDirX);
     if (ray->rayDirY == 0)
        ray->deltaDistY = 1e30;
    else
        ray->deltaDistY = fabs(1 / ray->rayDirY);
}

void    rays_innit(t_rays *ray, t_game *g)
{
    deltadistances(ray);
    
    if (ray->rayDirX < 0)
    {
        ray->stepX = -1;
        ray->sideDistX = (g->x - ray->mapX) * ray->deltaDistX;
    }
    else
    {
        ray->stepX = 1;
        ray->sideDistX = (ray->mapX + 1.0 - g->x) * ray->deltaDistX;
    }
    if (ray->rayDirY < 0)
    {
        ray->stepY = -1;
        ray->sideDistY = (g->y - ray->mapY) * ray->deltaDistY;
    }
    else
    {
        ray->stepY = 1;       
        ray->sideDistY = (ray->mapY + 1.0 - g->y) * ray->deltaDistY;
    }
}
/*
    if (rays->side == 0)
        perpDist = (rays->mapX - g->x + (1 - rays->stepX) / 2.0) / rays->rayDirX;
    else
        perpDist = (rays->mapY - g->y + (1 - rays->stepY) / 2.0) / rays->rayDirY;
*/
void    draw3d(t_game *g, t_rays *rays, int x, int h)
{
    int lineHeight;

    if (rays->side == 0)
        rays->prepDist = (rays->sideDistX - rays->deltaDistX);
    else
        rays->prepDist = (rays->sideDistY - rays->deltaDistY);
    lineHeight = (int)(h / rays->prepDist);
    rays->drawStart = (-lineHeight / 2) + (h / 2);
    rays->drawEnd = (lineHeight / 2) + (h / 2);
    if (rays->drawStart < 0) 
        rays->drawStart = 0;
    if (rays->drawEnd >= h) 
        rays->drawEnd = h - 1;
    apply_texture(rays, g, x, g->wall_text.txt_w, lineHeight); 
}

t_rays dda_ray(t_game *g, int x, int w, int h)
{
    t_rays  ray;

    ray.rayDirX = g->dirX + g->planeX * (double)(2 * x / (double)w - 1);
    ray.rayDirY = g->dirY + g->planeY * (2 * x / (double)w - 1);
    ray.mapX = (int)g->x;
    ray.mapY = (int)g->y;

    rays_innit(&ray, g);
    while (g->map[ray.mapY] && g->map[ray.mapY][ray.mapX] != '1') 
    {
        if (ray.sideDistX < ray.sideDistY) 
        {
            ray.sideDistX += ray.deltaDistX;
            ray.mapX += ray.stepX;
            ray.side = 0;
        } 
        else 
        {
            ray.sideDistY += ray.deltaDistY;
            ray.mapY += ray.stepY;
            ray.side = 1;
        }
    }
    draw3d(g, &ray, x, h);
    return ray;
}

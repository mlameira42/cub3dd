/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:19:18 by mlameira          #+#    #+#             */
/*   Updated: 2025/06/26 09:52:22 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int framerender (t_game *g)
{
    int x;
    
    x = -1;
    while (++x < g->mapsize[0] * g->mapsize[1])
        g->pixels[x] = 0x000000;
    mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
    mlx_clear_window(g->mlx, g->win);
    floorcast(g);
    x = -1;
    while (++x < g->mapsize[1])
        dda_ray(g, x, g->mapsize[1], g->mapsize[0]);
    mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
    return 1;
}
int createv(int key, t_game *vars)
{
    moviment(key, vars);
    if (key == 'q')    
        exit(2);
   framerender(vars);
    return 1;
}
/*
int main(int argc, char **argv)
{
    t_game g;
    
    g.dirX = -1;
    g.dirY = 0;
    g.planeX = 0;
    g.planeY = 0.66;
    g.mapsize[1] = SCREEN_W;
    g.mapsize[0] = SCREEN_H;
    if (argc <= 1)
        return 1;
    if (!getmap(argv[1], &g))
        return 1;
    getplayerpos(&g);
    g.mlx = mlx_init();
    g.win = mlx_new_window(g.mlx, g.mapsize[1], g.mapsize[0], "Raycaster");
    texture(&g);
    g.img = mlx_new_image(g.mlx, g.mapsize[1], g.mapsize[0]);
    g.pixels = (int*)mlx_get_data_addr(g.img, &g.bpp, &g.line_len, &g.endian);
    framerender (&g);
    mlx_put_image_to_window(g.mlx, g.win, g.img, 0, 0);
    mlx_hook(g.win, 2, 1L<<0, createv, &g);
    mlx_loop(g.mlx);
    return 0;
}
*/
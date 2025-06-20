/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:22:42 by mlameira          #+#    #+#             */
/*   Updated: 2025/06/20 17:12:04 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void    updown_mov(int key, t_game *vars)
{
    char up1;
    char up2;

    //printf("%d, %d \n", (int)vars->x, (int)(vars->y + vars->dirY * MOVESPEED));
    up1 = vars->map[(int)vars->y][(int)(vars->x + vars->dirX * MOVESPEED)];
    up2 = vars->map[(int)(vars->y + vars->dirY * MOVESPEED)][(int)vars->x];
    if (key == 'w')
    {
        if(up2 && up2 != '1')
            vars->x += vars->dirX * MOVESPEED;
        if(up1 && up1 != '1')
            vars->y += vars->dirY * MOVESPEED;
    }
    else
    {
        if(vars->map[(int)(vars->x - vars->dirX * MOVESPEED)][(int)vars->y] != '1')
            vars->x -= vars->dirX * MOVESPEED;
        if(vars->map[(int)vars->x][(int)(vars->y - vars->dirY * MOVESPEED)] != '1')
            vars->y -= vars->dirY * MOVESPEED;
    }
}

void moviment(int key, t_game *vars)
{
    double olddirx;
    double  oldplanex;

    olddirx = vars->dirX;
    oldplanex = vars->planeX;
    
    if (key == 'w' || key == 's')
        updown_mov(key, vars);
    else if (key == 'd')
    {
        vars->dirX = vars->dirX * cos(-0.0174523) - vars->dirY * sin(-0.0174523);
        vars->dirY = olddirx * sin(-0.0174523) + vars->dirY * cos(-0.0174523);
        vars->planeX = vars->planeX * cos(-0.0174523) - vars->planeY * sin(-0.0174523);
        vars->planeY = oldplanex * sin(-0.0174523) + vars->planeY * cos(-0.0174523);
    }
    else if (key == 'a')
    {
        vars->dirX = vars->dirX * cos(0.0174523) - vars->dirY * sin(0.0174523);
        vars->dirY = olddirx * sin(0.0174523) + vars->dirY * cos(0.0174523);
        vars->planeX = vars->planeX * cos(0.0174523) - vars->planeY * sin(0.0174523);
        vars->planeY = oldplanex * sin(0.0174523) + vars->planeY * cos(0.0174523);
    }
}
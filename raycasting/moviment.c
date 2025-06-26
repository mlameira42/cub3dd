/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:22:42 by mlameira          #+#    #+#             */
/*   Updated: 2025/06/26 08:32:08 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void    updown_mov(int key, t_game *vars)
{
    char up1;
    char up2;

    up1 = glob()->map[(int)vars->y][(int)(vars->x + vars->dirX * MOVESPEED)];
    up2 = glob()->map[(int)(vars->y + vars->dirY * MOVESPEED)][(int)vars->x];
    if (key == 'w')
    {
        if(up1 && up1 != '1')
            vars->x += vars->dirX * MOVESPEED;
        if(up2 && up2 != '1')
            vars->y += vars->dirY * MOVESPEED;
    }
    else
    {
        if(glob()->map[(int)(vars->y - vars->dirY * MOVESPEED)][(int)vars->x] != '1')
            vars->y -= vars->dirY * MOVESPEED;
        if(glob()->map[(int)vars->y][(int)(vars->x - vars->dirX * MOVESPEED)] != '1')
            vars->x -= vars->dirX * MOVESPEED;
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
    else if (key == 'a')
    {
        vars->dirX = vars->dirX * cos(-ROTSPEED) - vars->dirY * sin(-ROTSPEED);
        vars->dirY = olddirx * sin(-ROTSPEED) + vars->dirY * cos(-ROTSPEED);
        vars->planeX = vars->planeX * cos(-ROTSPEED) - vars->planeY * sin(-ROTSPEED);
        vars->planeY = oldplanex * sin(-ROTSPEED) + vars->planeY * cos(-ROTSPEED);
    }
    else if (key == 'd')
    {
        vars->dirX = vars->dirX * cos(ROTSPEED) - vars->dirY * sin(ROTSPEED);
        vars->dirY = olddirx * sin(ROTSPEED) + vars->dirY * cos(ROTSPEED);
        vars->planeX = vars->planeX * cos(ROTSPEED) - vars->planeY * sin(ROTSPEED);
        vars->planeY = oldplanex * sin(ROTSPEED) + vars->planeY * cos(ROTSPEED);
    }
}
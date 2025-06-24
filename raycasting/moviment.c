/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:22:42 by mlameira          #+#    #+#             */
/*   Updated: 2025/06/24 13:30:00 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void    updown_mov(int key, t_game *vars)
{
    char up1;
    char up2;

    up1 = glob()->map[(int)vars->x][(int)(vars->y + vars->dirY * MOVESPEED)];
    up2 = glob()->map[(int)(vars->x + vars->dirX * MOVESPEED)][(int)vars->y];
    if (key == 'w')
    {
        if(up1 && up1 != '1')
            vars->x += vars->dirX * MOVESPEED;
        printf("%c\n", up2);
        if(up2 && up2 != '1')
            vars->y += vars->dirY * MOVESPEED;
        printf("%c\n", up2);
    }
    else
    {
        if(glob()->map[(int)(vars->x - vars->dirX * MOVESPEED)][(int)vars->y] != '1')
            vars->x -= vars->dirX * MOVESPEED;
        if(glob()->map[(int)vars->x][(int)(vars->y - vars->dirY * MOVESPEED)] != '1')
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
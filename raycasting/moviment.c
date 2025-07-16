/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:22:42 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/16 09:53:09 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void    updown_mov(int key, t_game *vars)
{
    char up1;
    char up2;

    up1 = glob()->map[(int)vars->y][(int)((vars->x + 0.1) + vars->dirX * MOVESPEED)];
    up2 = glob()->map[(int)((vars->y - 0.1) + vars->dirY * MOVESPEED)][(int)vars->x];
    if (key == 'w')
    {
        if(up1 && up1 != '1')
            vars->x += vars->dirX * MOVESPEED;
        if(up2 && up2 != '1')
            vars->y += vars->dirY * MOVESPEED;
    }
    else
    {
        if(glob()->map[(int)((vars->y + 0.1) - vars->dirY * MOVESPEED)]\
			[(int)vars->x] != '1')
            vars->y -= vars->dirY * MOVESPEED;
        if(glob()->map[(int)vars->y] \
			[(int)(vars->x - vars->dirX * MOVESPEED)] != '1')
            vars->x -= vars->dirX * MOVESPEED;
    }
}

static void rotate(int key, t_game *vars, double olddirx, double oldplanex)
{
    if (key == 65361)
    {
        vars->dirX = vars->dirX * cos(-ROTSPEED) - vars->dirY * sin(-ROTSPEED);
        vars->dirY = olddirx * sin(-ROTSPEED) + vars->dirY * cos(-ROTSPEED);
        vars->planeX = vars->planeX * cos(-ROTSPEED) - vars->planeY * sin(-ROTSPEED);
        vars->planeY = oldplanex * sin(-ROTSPEED) + vars->planeY * cos(-ROTSPEED);
    }
    else if (key == 65363)
    {
        vars->dirX = vars->dirX * cos(ROTSPEED) - vars->dirY * sin(ROTSPEED);
        vars->dirY = olddirx * sin(ROTSPEED) + vars->dirY * cos(ROTSPEED);
        vars->planeX = vars->planeX * cos(ROTSPEED) - vars->planeY * sin(ROTSPEED);
        vars->planeY = oldplanex * sin(ROTSPEED) + vars->planeY * cos(ROTSPEED);
    }
}
static void sideways_walk(int key, t_game *vars)
{
   
    if (key == 'a')
    {
        movecorr(vars, vars->x + vars->dirY * MOVESPEED, \
			vars->y + vars->dirX * MOVESPEED, 1);
    }
    else if (key == 'd')
    {
        movecorr(vars, vars->x - vars->dirY * MOVESPEED, \
			vars->y - vars->dirX * MOVESPEED, -1);
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

    sideways_walk(key, vars);
    rotate(key, vars, olddirx, oldplanex);    
}

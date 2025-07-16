/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:22:42 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/16 13:06:00 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	updown_mov(int key, t_game *vars)
{
	char	up1;
	char	up2;

	up1 = glob()->map[(int)vars->y]
	[(int)((vars->x + 0.1) + vars->dirx * MOVESPEED)];
	up2 = glob()->map[(int)((vars->y - 0.1) + vars->diry * MOVESPEED)]
	[(int)vars->x];
	if (key == 'w')
	{
		if (up1 && up1 != '1')
			vars->x += vars->dirx * MOVESPEED;
		if (up2 && up2 != '1')
			vars->y += vars->diry * MOVESPEED;
	}
	else
	{
		if (glob()->map[(int)((vars->y + 0.1) - vars->diry * MOVESPEED)]
			[(int)vars->x] != '1')
			vars->y -= vars->diry * MOVESPEED;
		if (glob()->map[(int)vars->y]
			[(int)(vars->x - vars->dirx * MOVESPEED)] != '1')
			vars->x -= vars->dirx * MOVESPEED;
	}
}

static void	rotate(int key, t_game *vars, double olddirx, double oldplanex)
{
	if (key == 65361)
	{
		vars->dirx = vars->dirx * cos(-ROTSPEED) - vars->diry * sin(-ROTSPEED);
		vars->diry = olddirx * sin(-ROTSPEED) + vars->diry * cos(-ROTSPEED);
		vars->planex = vars->planex * cos(-ROTSPEED) - vars->planey
			* sin(-ROTSPEED);
		vars->planey = oldplanex * sin(-ROTSPEED) + vars->planey
			* cos(-ROTSPEED);
	}
	else if (key == 65363)
	{
		vars->dirx = vars->dirx * cos(ROTSPEED) - vars->diry * sin(ROTSPEED);
		vars->diry = olddirx * sin(ROTSPEED) + vars->diry * cos(ROTSPEED);
		vars->planex = vars->planex * cos(ROTSPEED) - vars->planey
			* sin(ROTSPEED);
		vars->planey = oldplanex * sin(ROTSPEED) + vars->planey * cos(ROTSPEED);
	}
}

static void	sideways_walk(int key, t_game *vars)
{
	if (key == 'a')
	{
		movecorr(vars, vars->x + vars->diry * MOVESPEED,
			vars->y + vars->dirx * MOVESPEED, 1);
	}
	else if (key == 'd')
	{
		movecorr(vars, vars->x - vars->diry * MOVESPEED,
			vars->y - vars->dirx * MOVESPEED, -1);
	}
}

void	moviment(int key, t_game *vars)
{
	double	olddirx;
	double	oldplanex;

	olddirx = vars->dirx;
	oldplanex = vars->planex;
	if (key == 'w' || key == 's')
		updown_mov(key, vars);
	sideways_walk(key, vars);
	rotate(key, vars, olddirx, oldplanex);
}

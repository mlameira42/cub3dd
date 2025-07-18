/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:22:42 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/18 09:33:13 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	updwncorr(t_game *vars, double x, double y, int side)
{
	char	up1;
	char	up2;

	up1 = glob()->map[(int)vars->y][(int)x];
	up2 = glob()->map[(int)y][(int)vars->x];
	if ((up1 && up2) && (up1 != '1' && up2 != '1'))
	{
		vars->x += (vars->dirx * MOVESPEED) * side;
		vars->y += (vars->diry * MOVESPEED) * side;
	}
}

void	updown_mov(int key, t_game *vars)
{
	if (key == 'w')
	{
		updwncorr(vars, (vars->x + 0.1) + vars->dirx * MOVESPEED,
			vars->y - 0.1 + (vars->diry) * MOVESPEED, 1);
	}
	else
	{
		updwncorr(vars, (vars->x - 0.1) - vars->dirx * MOVESPEED,
			(vars->y + 0.1) - vars->diry * MOVESPEED, -1);
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
		movecorr(vars, (vars->x + 0.2) + vars->diry * MOVESPEED,
			(vars->y - 0.2) + vars->dirx * MOVESPEED, 1);
	}
	else if (key == 'd')
	{
		movecorr(vars, (vars->x - 0.2) - vars->diry * MOVESPEED,
			(vars->y + 0.2) - vars->dirx * MOVESPEED, -1);
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

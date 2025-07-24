/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:22:42 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/24 14:08:04 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	updwncorr(t_game *vars, double x, double y, int side)
{
	char	up1;
	char	up2;

	if (!glob()->map)
		return (ft_fprintf(2, "Map "), ft_exit(1));
	if (!glob()->map[(int)vars->y][(int)x] ||
		!glob()->map[(int)y][(int)vars->x])
		return ;
	up1 = glob()->map[(int)vars->y][(int)x];
	up2 = glob()->map[(int)y][(int)vars->x];
	if ((up1 == '1' || up2 == '1') || \
(up2 == ' ' || up1 == ' '))
		return ;
	vars->x = vars->x + (vars->dirx * MOVESPEED) * side;
	vars->y = vars->y + (vars->diry * MOVESPEED) * side;
}

void	updown_mov(int key, t_game *vars)
{
	if (key == 'w')
	{
		if (vars->diry > 0)
			updwncorr(vars, (vars->x) + vars->dirx * MOVESPEED,
				(vars->y) + vars->diry * ceil(MOVESPEED), 1);
		else
			updwncorr(vars, (vars->x) + vars->dirx * ceil(MOVESPEED),
				(vars->y) + vars->diry * MOVESPEED, 1);
	}
	else
	{
		if (vars->dirx > 0)
			updwncorr(vars, (vars->x) - vars->dirx * MOVESPEED,
				(vars->y) - vars->diry * ceil(MOVESPEED), -1);
		else
			updwncorr(vars, (vars->x) - vars->dirx * ceil(MOVESPEED),
				(vars->y) - vars->diry * MOVESPEED, -1);
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
		if (vars->diry < 0)
			movecorr(vars, vars->x + vars->diry * (MOVESPEED),
				vars->y - vars->dirx * ceil(MOVESPEED), 1);
		else
			movecorr(vars, vars->x + vars->diry * ceil(MOVESPEED),
				vars->y - vars->dirx * (MOVESPEED), 1);
	}
	else if (key == 'd')
	{
		if (vars->diry < 0)
			movecorr(vars, (vars->x) - vars->diry * (MOVESPEED),
				(vars->y) + vars->dirx * ceil(MOVESPEED), -1);
		else
			movecorr(vars, (vars->x) - vars->diry * ceil(MOVESPEED),
				(vars->y) + vars->dirx * (MOVESPEED), -1);
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

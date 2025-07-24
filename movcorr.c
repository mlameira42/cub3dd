/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movcorr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:58:05 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/24 11:30:11 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	movecorr(t_game *g, int posX, double posY, int side)
{
	char	up1;
	char	up2;

	if (!glob()->map)
		return (ft_fprintf(2, "Map "), ft_exit(1), 1);
	up1 = glob()->map[(int)g->y][(int)posX];
	up2 = glob()->map[(int)posY][(int)g->x];
	if (!up1 || !up2)
		return 1;
	if ((up1 == '1' || up2 == '1') || \
	(up2 == ' ' || up1 == ' '))
		return 1;
	g->x = g->x + (g->diry * MOVESPEED) * side;
	g->y = g->y - (g->dirx * MOVESPEED) * side;
	return 0;
}

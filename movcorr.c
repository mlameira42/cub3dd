/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movcorr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:58:05 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/18 09:34:31 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	movecorr(t_game *g, int posX, double posY, int side)
{
	char	mov1;
	char	mov2;

	mov1 = glob()->map[(int)g->y][posX];
	mov2 = glob()->map[(int)posY][(int)g->x];
	if ((mov1 && mov2) && (mov1 != '1' && mov2 != '1'))
	{
		g->x += (g->diry * MOVESPEED) * side;
		g->y -= (g->dirx * MOVESPEED) * side;
	}
	return (1);
}

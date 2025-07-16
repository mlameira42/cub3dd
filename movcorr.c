/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movcorr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:58:05 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/16 12:55:46 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	movecorr(t_game *g, int posX, double posY, int side)
{
	char	mov1;
	char	mov2;
	char	mov3;

	mov1 = glob()->map[(int)g->y][posX];
	mov2 = glob()->map[(int)posY][(int)g->x];
	if (side < 0)
		mov3 = glob()->map[(int)(posY + 0.1)][(int)g->x];
	else
		mov3 = glob()->map[(int)(posY + 0.2)][(int)g->x];
	if (mov1 && mov1 != '1')
		g->x += (g->diry * MOVESPEED) * side;
	if (mov2 && mov2 != '1' && mov3 != '1')
		g->y -= (g->dirx * MOVESPEED) * side;
	return (1);
}

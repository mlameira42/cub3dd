/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_innit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:17:45 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/15 15:28:19 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void sprite_find(t_texture *sprite)
{
	int	i;
	int	j;

	i = -1;
	while (glob()->map[++i])
	{
		j = 0;
		while(glob()->map[i][++j])
		{
			if (glob()->map[i][j] == '0' && \
				glob()->map[i][j-1] == '0' && \
				glob()->map[i][j+1] == '0' && \
				glob()->map[i-1][j] == '0' && \
				glob()->map[i+1][j] == '0')
			{
				sprite->spriteX = i;
				sprite->spriteY = j;
			}
		}
	}
}

void sprite_visibility(t_game *g, int rayX, int rayY)
{
	if (g->sprite_tex.spriteX == rayX && g->sprite_tex.spriteY == rayY)
		g->sprite_tex.isHiting = 1;
}
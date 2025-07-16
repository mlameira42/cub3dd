/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_innit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:17:45 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/16 13:05:27 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_find(t_texture *sprite)
{
	int	i;
	int	j;

	i = -1;
	while (glob()->map[++i])
	{
		j = 0;
		while (glob()->map[i][++j])
		{
			if (glob()->map[i][j] == '0'
				&& glob()->map[i][j - 1] == '0'
				&& glob()->map[i][j + 1] == '0'
				&& glob()->map[i - 1][j] == '0'
				&& glob()->map[i + 1][j] == '0')
			{
				sprite->spritex = i;
				sprite->spritey = j;
			}
		}
	}
}

void	sprite_visibility(t_game *g, int rayX, int rayY)
{
	if (g->sprite_tex.spritex == rayX && g->sprite_tex.spritey == rayY)
		g->sprite_tex.ishiting = 1;
}

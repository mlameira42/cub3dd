/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:44:26 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/16 12:56:37 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	find_player(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (glob()->map[++i])
	{
		j = -1;
		while (glob()->map[i][++j])
		{
			if (ft_strchr("NWSE", glob()->map[i][j]))
			{
				g->x = j + 0.5;
				g->y = i + 0.5;
				g->dir = glob()->map[i][j];
				glob()->map[i][j] = '0';
				return (0);
			}
		}
	}
	g->dir = '\0';
	return ('\0');
}

static void	player_updown(t_game *player)
{
	if (player->dir == 'S')
	{
		player->dirx = 0;
		player->diry = 1;
		player->planex = -0.66;
		player->planey = 0;
	}
	else if (player->dir == 'N')
	{
		player->dirx = 0;
		player->diry = -1;
		player->planex = 0.66;
		player->planey = 0;
	}
}

static void	player_sides(t_game *player)
{
	if (player->dir == 'E')
	{
		player->dirx = -1;
		player->diry = 0;
		player->planex = 0;
		player->planey = -0.66;
	}
	else if (player->dir == 'W')
	{
		player->dirx = 1;
		player->diry = 0;
		player->planex = 0;
		player->planey = 0.66;
	}
}

void	init_game(t_game *g)
{
	find_player(g);
	player_sides(g);
	player_updown(g);
	g->mapsize[1] = SCREEN_W;
	g->mapsize[0] = SCREEN_H;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->mapsize[1], g->mapsize[0], "Cub3d");
	if (!texture(g))
		return (ft_printf("Texture "), ft_exit(2));
	sprite_find(&g->sprite_tex);
	g->img = mlx_new_image(g->mlx, g->mapsize[1], g->mapsize[0]);
	if (!g->img)
		return (ft_printf("Img load "), ft_exit(2));
	g->pixels = (int *)mlx_get_data_addr(g->img, &g->bpp, &g->line_len,
			&g->endian);
	g->texside = 0;
	framerender(g);
	mlx_hook(g->win, 2, 1L << 0, createv, g);
	mlx_loop(g->mlx);
}

void	init_all( char *map)
{
	validate(map);
	init_game(&glob()->render);
}

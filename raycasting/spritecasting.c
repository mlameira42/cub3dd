/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:11:53 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/16 13:05:10 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	sprite_tex(t_game *g)
{
	int	bpp;
	int	endian;
	int	sl;

	g->sprite_tex.ishiting = 0;
	g->sprite_tex.img = mlx_xpm_file_to_image(g->mlx, "./textures/barril.xpm",
			&g->sprite_tex.txt_w, &g->sprite_tex.txt_h);
	if (g->sprite_tex.img)
		return (g->sprite_tex.tex = (int *)mlx_get_data_addr(g->sprite_tex.img,
				&bpp, &sl, &endian), true);
	return (false);
}

static void	sprite_utils(t_game *g, t_texture *sprite, double sX, double sY)
{
	double	invdet;
	double	transformx;

	invdet = 1.0 / (g->planex * g->diry - g->dirx * g->planey);
	transformx = invdet * (g->diry * (sX - g->x) - g->dirx * (sY - g->y));
	sprite->transformy = invdet * ((-g->planey)
			* (sX - g->x) + g->planex * (sY - g->y));
	sprite->spritescreenx = (int)((SCREEN_W / 2)
			* (1 + transformx / sprite->transformy));
	sprite->spriteheight = abs((int)(SCREEN_H / (sprite->transformy))) / 1.5;
}

static void	drawingcalcs(t_texture *sprite)
{
	sprite->drawstarty = -sprite->spriteheight / 2 + SCREEN_H / 2 + 5;
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = sprite->spriteheight / 2 + SCREEN_H / 2;
	if (sprite->drawendy >= SCREEN_H)
		sprite->drawendy = SCREEN_H - 1;
	sprite->spritewidth = abs((int)(SCREEN_H / (sprite->transformy))) / 2;
	sprite->drawstartx = -sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	sprite->drawendx = sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawendx >= SCREEN_W)
		sprite->drawendx = SCREEN_W - 1;
}

static void	drawstart(t_game *g, t_texture *sprite)
{
	int			stripe;
	int			texx;
	int			texy;
	int			d;
	int			y;
	__uint32_t	color;

	stripe = sprite->drawstartx - 1;
	while (++stripe < sprite->drawendx)
	{
		texx = (int)(256 * (stripe - (-sprite->spritewidth / 2
						+ sprite->spritescreenx)) * sprite->txt_w
				/ sprite->spritewidth) / 256;
		if (sprite->transformy > 0 && stripe > 0 && stripe < SCREEN_W
			&& sprite->transformy < sprite->zbuffer[stripe])
			y = sprite->drawstarty - 1;
		while (++y < sprite->drawendy)
		{
			d = (y) * 256 - SCREEN_H * 128 + sprite->spriteheight * 128;
			texy = ((d * g->sprite_tex.txt_h) / sprite->spriteheight) / 256;
			color = g->sprite_tex.tex[g->sprite_tex.txt_w * texy + texx];
			if ((color & 0x00FFFFFF) != 0)
				g->pixels[SCREEN_W * y + stripe] = color;
		}
	}
}

void	spritecasting(t_game *g, t_texture *sprite, double sX, double sY)
{
	if (!sprite->ishiting)
		return ;
	sprite_utils(g, sprite, sX, sY);
	drawingcalcs(sprite);
	drawstart(g, sprite);
}

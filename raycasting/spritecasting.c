/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:11:53 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/03 11:16:03 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int	sprite_tex(t_game *g)
{
	int bpp;
	int endian;
	int sl;
	
	g->sprite_tex.img = mlx_xpm_file_to_image(g->mlx, "./textures/barril.xpm", &g->sprite_tex.txt_w, &g->sprite_tex.txt_h);
	if (g->sprite_tex.img)
		g->sprite_tex.tex = (int *)mlx_get_data_addr(g->sprite_tex.img, &bpp, &sl, &endian);
	else
		return 0;
	printf("%d\n", g->sprite_tex.tex[2]);
	return 1;
}



void sprite_utils(t_game *g, t_texture *sprite, double sX, double sY)
{
	double invDet;
	double transformX;
	
	invDet = 1.0 / (g->planeX * g->dirY - g->dirX * g->planeY);
	transformX = invDet * (g->dirY * (sX - g->x) - g->dirX * (sY - g->y));
	sprite->transformY = invDet * ((-g->planeY) * (sX - g->x) + g->planeX * (sY - g->y));
	sprite->spriteScreenX = (int)((SCREEN_W / 2) * (1 + transformX / sprite->transformY));
	sprite->spriteHeight = abs((int)(SCREEN_H / (sprite->transformY))) / 1.5;
}

void drawingcalcs(t_texture *sprite)
{
	sprite->drawStartY = -sprite->spriteHeight / 2 + SCREEN_H / 2 + 5;
	if (sprite->drawStartY < 0)
		sprite->drawStartY = 0;
	sprite->drawEndY = sprite->spriteHeight / 2 + SCREEN_H / 2;
	if (sprite->drawEndY >= SCREEN_H)
		sprite->drawEndY = SCREEN_H - 1;
	sprite->spriteWidth = abs((int)(SCREEN_H / (sprite->transformY))) / 2;
	sprite->drawStartX = -sprite->spriteWidth / 2 + sprite->spriteScreenX;
	if (sprite->drawStartX < 0)
		sprite->drawStartX = 0;
	sprite->drawEndX = sprite->spriteWidth / 2 + sprite->spriteScreenX;
	if (sprite->drawEndX >= SCREEN_W)
		sprite->drawEndX = SCREEN_W - 1;
}
void drawstart(t_game *g, t_texture *sprite)
{
	int stripe;
	int texX;
	int texY;
	int d;
	int y;
	__uint32_t color;
	
	stripe = sprite->drawStartX - 1;
	while (++stripe < sprite->drawEndX)
	{
		texX = (int)(256 * (stripe - (-sprite->spriteWidth / 2 + \
		sprite->spriteScreenX)) * sprite->txt_w / \
		sprite->spriteWidth)/ 256;
		if (sprite->transformY > 0 && stripe > 0 && stripe < SCREEN_W && \
			sprite->transformY < sprite->ZBuffer[stripe])
		y = sprite->drawStartY - 1;
		while (++y < sprite->drawEndY)
		{
			d = (y) * 256 - SCREEN_H * 128 + sprite->spriteHeight * 128;
			texY = ((d * g->sprite_tex.txt_h) / sprite->spriteHeight) / 256;
			color = g->sprite_tex.tex[g->sprite_tex.txt_w * texY + texX];
			if ((color & 0x00FFFFFF) != 0)
				g->pixels[SCREEN_W * y + stripe] = color;
		}
	}
}

void spritecasting(t_game *g, double sX, double sY)
{
	sprite_utils(g, &g->sprite_tex, sX, sY);
	drawingcalcs(&g->sprite_tex);
	drawstart(g, &g->sprite_tex);
}

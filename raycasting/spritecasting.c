/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:11:53 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/02 12:24:37 by mlameira         ###   ########.fr       */
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
	return 1;
}
/*
void sprite_utils(t_game *g)
{
	
}
*/

void spritecasting(t_game *g, double sX, double sY)
{
	double spriteX;
	double spriteY;
	double invDet;
	double transformX;
	double transformY;

	spriteX = sX - g->x;
	spriteY = sY - g->y;
	invDet = 1.0 / (g->planeX * g->dirY - g->dirX * g->planeY); // required for correct matrix multiplication
	transformX = invDet * (g->dirY * spriteX - g->dirX * spriteY);
	transformY = invDet * ((-g->planeY) * spriteX + g->planeX * spriteY); // this is actually the depth inside the screen, that what Z is in 3D

	int spriteScreenX = (int)((SCREEN_W / 2) * (1 + transformX / transformY));
	int spriteHeight = abs((int)(SCREEN_H / (transformY))) / 1.5; // using 'transformY' instead of the real distance prevents fisheye
	int drawStartY = -spriteHeight / 2 + SCREEN_H / 2 + 5;
	if (drawStartY < 0)
		drawStartY = 0;
	int drawEndY = spriteHeight / 2 + SCREEN_H / 2;
	if (drawEndY >= SCREEN_H)
		drawEndY = SCREEN_H - 1;
	int spriteWidth = abs((int)(SCREEN_H / (transformY))) / 2;
	int drawStartX = -spriteWidth / 2 + spriteScreenX;
	if (drawStartX < 0)
		drawStartX = 0;
	int drawEndX = spriteWidth / 2 + spriteScreenX;
	if (drawEndX >= SCREEN_W)
		drawEndX = SCREEN_W - 1;
	for (int stripe = drawStartX; stripe < drawEndX; stripe++)
	{
		int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * g->sprite_tex.txt_w / spriteWidth) / 256;
		if (transformY > 0 && stripe > 0 && stripe < SCREEN_W && transformY < g->sprite_tex.ZBuffer[stripe])
			for (int y = drawStartY; y < drawEndY; y++) // for every pixel of the current stripe
			{
				int d = (y) * 256 - SCREEN_H * 128 + spriteHeight * 128; // 256 and 128 factors to avoid floats
				int texY = ((d * g->sprite_tex.txt_h) / spriteHeight) / 256;
				__uint32_t color = g->sprite_tex.tex[g->sprite_tex.txt_w * texY + texX]; // get current color from the texture
				if ((color & 0x00FFFFFF) != 0)
					g->pixels[SCREEN_W * y + stripe] = color; // paint pixel if it isn't black, black is the invisible color
			}
    }
}

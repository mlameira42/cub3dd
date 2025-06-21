/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:30:53 by mlameira          #+#    #+#             */
/*   Updated: 2025/06/21 14:37:28 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	texture(t_game *g)
{
	int bpp;
	int llen;
	int endian;

	g->wall_text.img = mlx_xpm_file_to_image(g->mlx, "./textures/wall.xpm", &g->wall_text.txt_w,\
		&g->wall_text.txt_h);
	g->wall_text.tex = (int *)mlx_get_data_addr(g->wall_text.img, &bpp, &llen, &endian);
	if (!g->wall_text.img)
		return 0;
	return 1;
}

void	apply_texture(t_rays *r, t_game *g, int x, int tex_size, int lineHeight)
{
	double wallX;
	int texX;
	int texY;
	int y;
	double texPos;
	double step;

	if (r->side == 0)
		wallX = g->y + r->prepDist * r->rayDirY;
	else
		wallX = g->x + r->prepDist * r->rayDirX;
    wallX -= floor((wallX));
    texX = (int)(wallX * (double)tex_size);
    if((r->side==0 && r->rayDirX>0) || (r->side==1 && r->rayDirY<0))
		texX = tex_size - texX-1;
	y = r->drawStart - 1;
	step = (double)g->wall_text.txt_h / lineHeight;
	texPos = (r->drawStart - SCREEN_H / 2 + lineHeight / 2) * step;
	while(++y < r->drawEnd)
	{
		texY = (int)texPos;
		if (texY < 0)
        	texY = 0;
		if (texY >= tex_size)
			texY = tex_size - 1;
		texPos += step;
		r->color = g->wall_text.tex[texY * tex_size + texX];
		if(r->side)
			r->color = (r->color>>1) & 8355711;
        g->pixels[y * SCREEN_W + x] = r->color;
    }
}
//d = y*256 - SCREEN_H*128 + lineHeight*128;
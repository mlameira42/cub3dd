/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:30:53 by mlameira          #+#    #+#             */
/*   Updated: 2025/06/26 07:36:13 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned long get_color(int *rgb)
{
	int	r;
	int	g;
	int	b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	if (r > 255 && r < 0)
		return 0;
	if (g > 255 && g < 0)
		return 0;
	if (g > 255 && g < 0)
		return 0;
	return ((r & 0x0ff) >> 16) + ((g & 0x0ff) >> 8) + (b & 0x0ff);
}

int	texture(t_game *g)
{
	int bpp;
	int llen;
	int endian;
	int i;

	i = -1;
	g->wall_text[NORTH].img = mlx_xpm_file_to_image(g->mlx, glob()->e_wall_tex, \
		&g->wall_text[NORTH].txt_w, &g->wall_text[NORTH].txt_h);
	g->wall_text[WEST].img = mlx_xpm_file_to_image(g->mlx, glob()->e_wall_tex, \
		&g->wall_text[WEST].txt_w, &g->wall_text[WEST].txt_h);
	g->wall_text[EAST].img = mlx_xpm_file_to_image(g->mlx, glob()->e_wall_tex, \
		&g->wall_text[EAST].txt_w, &g->wall_text[EAST].txt_h);
	g->wall_text[SOUTH].img = mlx_xpm_file_to_image(g->mlx, glob()->e_wall_tex, \
		&g->wall_text[SOUTH].txt_w, &g->wall_text[SOUTH].txt_h);
	g->ceil = get_color(glob()->ceil_color);
	g->floor_tex = get_color(glob()->floor_color);
	while(++i < 4)
	{
		g->wall_text[i].tex = (int *)mlx_get_data_addr(g->wall_text[i].img, &bpp, &llen, &endian);
		if (!g->wall_text[i].img || !g->wall_text[i].tex)
			return 0;
	}
	return 1;
}

static void	calculate_tex(t_rays *r, t_game *g, int *texX, int tex_size)
{
	double wallX;

	if (r->side == 0)
		wallX = g->y + r->prepDist * r->rayDirY;
	else
		wallX = g->x + r->prepDist * r->rayDirX;
    wallX -= floor((wallX));
    *(texX) = (int)(wallX * (double)tex_size);
    if((r->side==0 && r->rayDirX>0) || (r->side==1 && r->rayDirY<0))
		*(texX) = tex_size - *(texX)-1;
}
void	apply_texture(t_rays *r, t_game *g, int x, int tex_size, int lineHeight)
{
	int texX;
	int texY;
	int y;
	double texPos;
	double step;

	calculate_tex(r, g, &texX, tex_size);
	y = r->drawStart - 1;
	step = (double)g->wall_text[g->texside].txt_h / lineHeight;
	texPos = (r->drawStart - SCREEN_H / 2 + lineHeight / 2) * step;
	while(++y < r->drawEnd)
	{
		texY = (int)texPos;
		if (texY < 0)
        	texY = 0;
		if (texY >= tex_size)
			texY = tex_size - 1;
		texPos += step;
		r->color = g->wall_text[g->texside].tex[texY * tex_size + texX];
		if(r->side)
			r->color = (r->color>>1) & 8355711;
        g->pixels[y * SCREEN_W + x] = r->color;
    }
}
//d = y*256 - SCREEN_H*128 + lineHeight*128;
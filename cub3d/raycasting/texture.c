/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:30:53 by mlameira          #+#    #+#             */
/*   Updated: 2025/06/20 18:05:49 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	texture(t_game *g, t_texture *wall)
{
	int bpp;
	int llen;
	int endian;

	g->wall_text.img = mlx_xpm_file_to_image(g->mlx, "./textures/wall.xpm", &wall->txt_w,\
		&wall->txt_h);
	wall->tex = (int *)mlx_get_data_addr(wall->img, &bpp, &llen, &endian);
qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq	if (!g->wall_text.img)
		exit(2);
	return wall->txt_w;
}

void	apply_texture(t_rays *r, t_game *g, int x, int tex_size, int lineHeight)
{
	double wallX;
	int texX;
	int texY;
	int y;
	int d;

	if (r->side == 0)
		wallX = g->y + r->prepDist * r->rayDirY;
	else
		wallX = g->x + r->prepDist * r->rayDirX;
    wallX -= floor(wallX);
    texX = (int)(wallX * tex_size);
    if(r->side==0 && r->rayDirX>0) texX = tex_size - texX-1; //  
    if(r->side==1 && r->rayDirY<0) texX = tex_size - texX-1; //
	y = r->drawStart - 1;
	while(++y < r->drawEnd){
        d = y*256 - SCREEN_H*128 + lineHeight*128;
        texY = ((d * tex_size)/lineHeight)/256;
        r->color = g->wall_text.tex[tex_size * texY + texX];
		if(r->side)
			r->color = (r->color>>1)&0x7F7F7F;
            g->pixels[y * SCREEN_W + x] = r->color;
    }
}

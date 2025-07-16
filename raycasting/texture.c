/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:30:53 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/16 13:08:57 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned long	get_color(int *rgb)
{
	int	r;
	int	g;
	int	b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	if (r > 255 && r < 0)
		return (0);
	if (g > 255 && g < 0)
		return (0);
	if (g > 255 && g < 0)
		return (0);
	return (((r & 0x0ff) >> 16) + ((g & 0x0ff) >> 8) + (b & 0x0ff));
}

bool	texture(t_game *g)
{
	int	bpp;
	int	llen;
	int	endian;
	int	i;

	i = -1;
	g->wall_text[NORTH].img = mlx_xpm_file_to_image(g->mlx, glob()->e_wall_tex,
			&g->wall_text[NORTH].txt_w, &g->wall_text[NORTH].txt_h);
	g->wall_text[WEST].img = mlx_xpm_file_to_image(g->mlx, glob()->e_wall_tex,
			&g->wall_text[WEST].txt_w, &g->wall_text[WEST].txt_h);
	g->wall_text[EAST].img = mlx_xpm_file_to_image(g->mlx, glob()->e_wall_tex,
			&g->wall_text[EAST].txt_w, &g->wall_text[EAST].txt_h);
	g->wall_text[SOUTH].img = mlx_xpm_file_to_image(g->mlx, glob()->e_wall_tex,
			&g->wall_text[SOUTH].txt_w, &g->wall_text[SOUTH].txt_h);
	g->ceil = get_color(glob()->ceil_color);
	g->floor_tex = get_color(glob()->floor_color);
	if (!sprite_tex(g))
		return (ft_printf("Sprite "), 0);
	while (++i < 4 && g->wall_text[i].img)
		g->wall_text[i].tex = (int *)mlx_get_data_addr(g->wall_text[i].img,
				&bpp, &llen, &endian);
	return (i == 4);
}

static void	calculate_tex(t_rays *r, t_game *g, int *texx, int tex_size)
{
	double	wallx;

	if (r->side == 0)
		wallx = g->y + r->prepdist * r->raydiry;
	else
		wallx = g->x + r->prepdist * r->raydirx;
	wallx -= floor((wallx));
	*(texx) = (int)(wallx * (double)tex_size);
	if ((r->side == 0 && r->raydirx > 0) || (r->side == 1 && r->raydiry < 0))
		*(texx) = tex_size - *(texx) - 1;
}

void	apply_texture(t_rays *r, t_game *g, int x, int tex_size, int lineheight)
{
	int		texx;
	int		texy;
	int		y;
	double	texpos;
	double	step;

	calculate_tex(r, g, &texx, tex_size);
	y = r->drawstart - 1;
	step = (double)g->wall_text[g->texside].txt_h / lineheight;
	texpos = (r->drawstart - SCREEN_H / 2 + lineheight / 2) * step;
	while (++y < r->drawend)
	{
		texy = (int)texpos;
		if (texy < 0)
			texy = 0;
		if (texy >= tex_size)
			texy = tex_size - 1;
		texpos += step;
		r->color = g->wall_text[g->texside].tex[texy * tex_size + texx];
		if (r->side)
			r->color = (r->color >> 1) & 8355711;
		g->pixels[y * SCREEN_W + x] = r->color;
	}
}

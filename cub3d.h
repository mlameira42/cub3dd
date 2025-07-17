/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:38:51 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/17 13:35:15 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <stdarg.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define SCREEN_W 960
# define SCREEN_H 720
# define TILE_SIZE 64
# define MOVESPEED 0.1
# define ROTSPEED 0.0174523

enum
{
	NORTH = 0,
	WEST = 1,
	EAST = 2,
	SOUTH = 3,
};

typedef struct s_texture
{
	int		*tex;
	void	*img;
	int		txt_h;
	int		txt_w;
	double	zbuffer[SCREEN_W];
	double	transformy;
	int		spritewidth;
	int		drawstarty;
	int		drawendy;
	int		drawstartx;
	int		drawendx;
	int		spritescreenx;
	int		spriteheight;
	double	spritex;
	double	spritey;
	int		ishiting;
	int		stripe;
}			t_texture;

typedef struct s_game
{
	double			x;
	double			y;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	void			*mlx;
	void			*win;
	void			*img;
	int				*pixels;
	int				bpp;
	int				line_len;
	int				endian;
	char			dir;
	int				mapsize[2];
	int				texside;
	t_texture		wall_text[4];
	t_texture		sprite_tex;
	unsigned long	ceil;
	unsigned long	floor_tex;
}					t_game;

typedef struct s_floor
{
	int		p;
	float	rawdistance;
	float	floorstepx;
	float	floorstepy;
	float	floorx;
	float	floory;
	int		tx;
	int		ty;
}	t_floor;

typedef struct s_rays
{
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	prepdist;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
	int		color;
	int		drawstart;
	int		drawend;
}	t_rays;

typedef struct s_global
{
	char		**map;
	char		**fld_map;
	char		*doc;
	int			doc_len;
	int			fd;
	int			rows;
	size_t		max_cols;
	int			nsew_count;
	int			ver_wall[2];
	char		*n_wall_tex;
	char		*s_wall_tex;
	char		*e_wall_tex;
	char		*w_wall_tex;
	int			*floor_color;
	int			*ceil_color;
	int			empty_lines;
	int			start_point[2];
	bool		isfloorinfo;
	bool		isceilinfo;
	t_game		render;
}				t_global;

t_global	*glob(void);
void		ft_init_global(char *str);
void		ft_exit(int status);
bool		ft_main_ver(void);
void		ft_get_info(void);
bool		ft_ver_line(char *line);
bool		ft_copy_map(void);
void		ft_free_strs(char **strs);
int			*ft_copy_ints(char *str, char c);
void		ft_copy_info(char *str, char c);
bool		ft_ver_info(void);
void		ft_close(void);
void		ft_get_map_size(void);
void		ft_debugger(void);
void		validate(char *av);
void		init_all(char *map);
bool		ft_dup_map(void);
bool		ft_floodfill(char **map, int y, int x);
void		ft_get_start(void);
t_rays		dda_ray(t_game *g, int x, int w, int h);
void		apply_texture(t_rays *r, t_game *g, int x,
				int lineHeight);
bool		texture(t_game *g);
void		floorcast(t_game *g, t_floor *floor);
void		moviment(int key, t_game *vars);
int			framerender(t_game *g);
int			createv(int key, t_game *vars);
void		sprite_find(t_texture *sprite);
void		sprite_visibility(t_game *g, int rayX, int rayY);
int			sprite_tex(t_game *g);
void		spritecasting(t_game *g, t_texture *sprite, double sX, double sY);
int			movecorr(t_game *g, int posX, double posY, int side);

#endif
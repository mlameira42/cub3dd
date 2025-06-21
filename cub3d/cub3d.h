/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:23:34 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/21 14:42:09 by mlameira         ###   ########.fr       */
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

#define SCREEN_W 640
#define SCREEN_H 480
#define TILE_SIZE 64
#define MOVESPEED 0.5

typedef struct s_texture {
	int 	*tex;
    void    *img;
    int     txt_h;
    int     txt_w;
} t_texture;

typedef struct s_game {
    double x, y;    // posição do jogador
    double dirX, dirY;      // direção
    double planeX, planeY;  // plano da câmera
    void *mlx, *win, *img;
    int *pixels;
    int bpp, line_len, endian;
	char **map;
	int	mapsize[2];
    t_texture   wall_text;
} t_game;

typedef struct s_rays
{
    double rayDirX;
    double rayDirY;
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;
    double prepDist;
    int mapX;
    int mapY;
    int stepX;
    int stepY;
    int side;
    int color;
    int drawStart; 
    int drawEnd;
}   t_rays;

typedef	struct	s_player
{
	void	*img;
	int		pos[2];
}	t_player;

typedef struct s_global
{
	char		**map;
	char		*doc;
	void		*ptr;
	void		*win;
	int			doc_len;
	int			fd;
	int			rows;
	size_t		max_cols;
	int			nsew_count;
	int			ver_wall[2];
	t_game		camera;
}			t_global;

t_global	*glob(void);
void		ft_init_global(char *str);
void		ft_exit(int status);
bool		ft_main_ver(void);
bool		ft_get_size(void);
bool		ft_ver_line(char *line);
bool		ft_copy_map(void);
void		ft_free_strs(char **strs);
char		*get_lines(char *dest, char *src, char tofind);
char		*get_next_line(int fd); 
int			ft_findchr(char *s, char c);
t_rays		dda_ray(t_game *g, int x, int w, int h);
void		moviment(int key, t_game *vars);
int			getmap(char *filename, t_game *vars);
int         getplayerpos(t_game *vars);
void	    apply_texture(t_rays *r, t_game *g, int x, int tex_size, int lineHeight);
int         texture(t_game *g);

// bool		ft_ver_walls(void);

#endif
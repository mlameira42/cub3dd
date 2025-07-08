/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:38:51 by mlameira          #+#    #+#             */
/*   Updated: 2025/07/08 12:46:56 by nsilva-n         ###   ########.fr       */
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
#define MOVESPEED 0.1
#define	ROTSPEED 0.0174523

enum {
	NORTH = 0,
	WEST = 1,
	EAST = 2,
	SOUTH = 3,
};

typedef struct s_texture {
	int 	*tex;
    void    *img;
    int     txt_h;
    int     txt_w;
	double	ZBuffer[SCREEN_W];
	double transformY;
	int spriteWidth;
	int drawStartY;
	int drawEndY;
	int drawStartX;
	int drawEndX;
	int spriteScreenX;
	int spriteHeight;
} t_texture;

typedef struct s_game {
    double			x;
	double			y;    // posição do jogador
    double			dirX;
	double			dirY;      // direção
    double			planeX;
	double			planeY;  // plano da câmera
    void			*mlx;
	void			*win;
	void			*img;
    int				*pixels;
    int				bpp;
	int				line_len;
	int				endian;
	//char			**map;
	char			dir;
	int				mapsize[2];
	int				texside;
    t_texture   	wall_text[4];
	t_texture		sprite_tex;
	unsigned long	ceil;
    unsigned long	floor_tex;
}					t_game;

typedef struct s_floor {
	int		p;
	float	rawDistance;
	float	floorStepX;
	float	floorStepY;
    float   floorX;
    float   floorY;
    int     tx;
    int     ty;
} t_floor;

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
//int			ft_findchr(char *s, char c);
//////////////////RAYS///////////////////////////////////
t_rays		dda_ray(t_game *g, int x, int w, int h);
void	    apply_texture(t_rays *r, t_game *g, int x, int tex_size, int lineHeight);
int         texture(t_game *g);
void        floorcast(t_game *g);
void		moviment(int key, t_game *vars);
int			framerender (t_game *g);
int			createv(int key, t_game *vars);
int			sprite_tex(t_game *g);
void		spritecasting(t_game *g, double sX, double sY);
int			movecorr(t_game *g, int posX, double posY, int side);
//int			getmap(char *filename, t_game *vars);
//int         getplayerpos(t_game *vars);
// bool		ft_ver_walls(void);

#endif
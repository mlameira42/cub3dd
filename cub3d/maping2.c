#include "cub3d.h"

typedef struct	s_data {
	void	*ptr;
	void	*win;
	int		pos[2];
	char	**map;
	void	*player_img;
	int		player_size[2];
	void	*img_wall;
	int		wall_size[2];
	void	*background;
	int		bk_size[2];

}				t_data;

int	map_gen(t_data *vars)
{
	int	i;
	int	j;

	i = -1;
	if (!vars->map || !vars->background || !vars->img_wall || !vars->player_img)
		return 1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] != '1')
			{
				mlx_put_image_to_window(vars->ptr, vars->win, vars->background, \
				j * vars->bk_size[0], i * vars->bk_size[1]);
				if (vars->map[i][j] == 'P')
				{
					vars->pos[0] = j * vars->bk_size[0], vars->pos[1] = i * vars->bk_size[1];
					vars->map[i][j] = '0';
					mlx_put_image_to_window(vars->ptr, vars->win, vars->player_img,\
						vars->pos[0], vars->pos[1]);
				}
			}
			else
				mlx_put_image_to_window(vars->ptr, vars->win, \
				vars->img_wall, j * vars->wall_size[0], i * vars->wall_size[1]);
		}
	}
	mlx_put_image_to_window(vars->ptr, vars->win, vars->player_img, \
			vars->pos[0], vars->pos[1]);
	return (0);
}

int	colide(int key, t_data	*vars)
{

	if (key == 'd')
		vars->pos[0] += 5;
	if (key == 'a')
		vars->pos[0] -= 5;
	if (key == 's')
		vars->pos[1] += 5;
	if (key == 'w')
		vars->pos[1] -= 5;
	
	return 1;
}

int	minimap(int key, t_data *metadata)
{
	if (key == 'a' || key == 'd' || key == 'w' || key == 's')
		colide(key, metadata);
//	else if (key == 65363 || key == 65361 || key == 65362 || key == 65364) //left, rigth, up, down arrows
//		colide2();
	else if (key == 'q')
		return  exit(5), 54;
	else
		return printf("%d\n", key);
	map_gen(metadata);
	return 1;
}
int loophook(t_data *player)
{
	(void)player;
	return 1;
}
void	loadimg(t_data	*metadata){
	
	metadata->img_wall = mlx_xpm_file_to_image(metadata->ptr, \
	"./textures/wall.xpm", &metadata->wall_size[0], &metadata->wall_size[1]);
	metadata->background = mlx_xpm_file_to_image(metadata->ptr, "./textures/back.xpm", \
	&metadata->bk_size[0], &metadata->bk_size[1]);
	metadata->player_img = mlx_xpm_file_to_image(metadata->ptr, "./textures/walk0.xpm",
				&metadata->player_size[0], &metadata->player_size[1]);
	if (!metadata->background)
		return (void)printf("errorn on background");
	if (!metadata->player_img)
		return (void)printf("errorn on player");
	if (!metadata->img_wall)
		return (void)printf("errorn on wall");
}


int	getmap(char *filename, t_data *vars)
{
	char	*hld;
	char	*maphld;
	int		fd;

	(void)vars;
	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (0);
	hld = get_next_line(fd);
	maphld = NULL;
	while (hld)
	{
		if (hld[0] == '\n')
			return (free(hld), free(maphld), 0);
		maphld = get_lines(maphld, hld, '\0');
		free(hld);
		hld = get_next_line(fd);
	}
	if (!ft_strrchr(maphld, 'P') )
		return (close(fd), free(maphld), 0);
	vars->map = NULL;
	vars->map = ft_split(maphld, '\n');
	free(maphld);
	close(fd);
	return (1);
}

int main(int argc, char **argv)
{
	t_data	metadata;

	if (argc <= 1)
		return 1;
	metadata.ptr = mlx_init();
	metadata.win = mlx_new_window(metadata.ptr, 1024, 512, "ADFG");
	loadimg(&metadata);
	if (!getmap(argv[1], &metadata))
		return 1;
	map_gen(&metadata);
	mlx_hook(metadata.win, 2, 1L<<0, minimap, &metadata);
	mlx_loop_hook(metadata.ptr, loophook, &metadata);
	mlx_loop(metadata.ptr);
	return 0;
}

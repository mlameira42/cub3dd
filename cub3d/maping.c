#include "cub3d.h"

int	getmap(char *filename, t_game *vars)
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

int	getmapsize(t_game *vars)
{
	int	i;

	i = -1;
	vars->mapsize[1] = ft_strlen(vars->map[++i]) * 50;
	while(vars->map[++i])
		;
	vars->mapsize[0] = i * 50;
	//printf("(%d, %d)\n", vars->mapsize[1], vars->mapsize[0]);
	return i;
}
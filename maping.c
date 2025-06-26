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
	if (!ft_strrchr(maphld, 'P'))
		return (close(fd), free(maphld), 0);
	vars->map = NULL;
	vars->map = ft_split(maphld, '\n');
	free(maphld);
	close(fd);
	return (1);
}

int	getplayerpos(t_game *vars)
{
	int	i;
	int	j;

	i = -1;
	while(vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
			if (vars->map[i][j] == 'P')
				{
					vars->x = j;
					vars->y = i;
					return 0;
				}
	}
	return 1;
}
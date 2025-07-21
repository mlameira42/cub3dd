/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:22:39 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/21 10:33:02 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	validate_space(char **map, int i, int j)
{
	if (map[i][j] != ' ')
		return (0);
	if (j < (int) ft_strlen(map[i - 1]) && map[i - 1][j] == '0')
		return ((ft_printf("Map not closed "), ft_exit(1)), 1);
	if (j < (int) ft_strlen(map[i + 1]) && map[i - 1][j] == '0')
		return ((ft_printf("Map not closed "), ft_exit(1)), 1);
	if (map[i][j - 1] == '0')
		return ((ft_printf("Map not closed "), ft_exit(1)), 1);
	if (map[i][j + 1] == '0')
		return ((ft_printf("Map not closed "), ft_exit(1)), 1);
	return (1);
}

void	validate_borders(char **map, int i, int j)
{
	if (validate_space(map, i, j))
		return ;
	if (ft_strlen(map[i]) > ft_strlen(map[i - 1])
		&& j >= (int)ft_strlen(map[i - 1]))
	{
		if (map[i][j] != '1')
			return (ft_printf("Map not closed "), ft_exit(1));
	}
	if (j < (int)ft_strlen(map[i - 1]) && map[i - 1][j] == ' ')
	{
		if (map[i][j] != '1')
			return (ft_printf("Map not closed "), ft_exit(1));
	}
	if (ft_strlen(map[i]) > ft_strlen(map[i + 1])
		&& j >= (int)ft_strlen(map[i + 1]))
	{
		if (map[i][j] != '1')
			return (ft_printf("Map not closed "), ft_exit(1));
	}
	if (j < (int)ft_strlen(map[i + 1]) && map[i + 1][j] == ' ')
	{
		if (map[i][j] != '1')
			return (ft_printf("Map not closed "), ft_exit(1));
	}
}

int	check_f_l(int i, int j)
{
	--j;
	while (glob()->map[i][++j])
	{
		if (glob()->map[i][j] != '1' && glob()->map[i][j] != ' ')
			return (ft_printf("Map opened "), ft_exit(1), 1);
	}
	return (0);
}

bool	validate_map(void)
{
	int		i;
	int		j;
	char	**map;

	map = glob()->map;
	i = -1;
	while (++i < glob()->rows)
	{
		j = -1;
		while (map[i][++j] && map[i][j] == ' ')
			;
		if ((i == 0 || i == glob()->rows - 1) && !check_f_l(i, j))
			continue ;
		if (map[i][j--] != '1')
			return (ft_printf("Map not closed "), ft_exit(1), false);
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (ft_printf("Map not closed "), ft_exit(1), false);
		while (map[i][++j])
			validate_borders(map, i, j);
	}
	return (true);
}

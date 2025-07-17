/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:29:31 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/17 13:36:25 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_copy_map(void)
{
	char	*line;
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (glob()->rows + 1));
	if (!map)
		return (false);
	line = ft_get_next_line(glob()->fd);
	i = -1;
	while (line)
	{
		if (!glob()->empty_lines)
		{
			map[++i] = ft_strtrim(line, "\n");
			if (!map[i])
				return (free(line), false);
		}
		if (!ft_linelen(line))
			glob()->empty_lines--;
		free(line);
		line = ft_get_next_line(glob()->fd);
	}
	map[++i] = NULL;
	glob()->map = map;
	return (true);
}

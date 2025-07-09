/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:29:31 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/09 11:01:49 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_copy_map(void)
{
	char	*line;
	int		i;

	glob()->map = malloc(sizeof(char *) * (glob()->rows + 1));
	if (!glob()->map)
		return (false);
	line = ft_get_next_line(glob()->fd);
	i = -1;
	while (line)
	{
		if (!glob()->empty_lines)
		{
			glob()->map[++i] = ft_strtrim(line, "\n");
			if (!glob()->map[i])
				return (free(line), false);
		}
		if (!ft_linelen(line))
			glob()->empty_lines--;
		free(line);
		line = ft_get_next_line(glob()->fd);
	}
	glob()->map[++i] = NULL;
	return (true);
}

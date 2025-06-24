/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:49:26 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/24 10:52:48 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_map_size(void)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_get_next_line(glob()->fd);
	while (line && i != glob()->empty_lines)
	{
		if (!ft_linelen(line))
			i++;
		free(line);
		line = ft_get_next_line(glob()->fd);
	}
	while (line)
	{
		glob()->rows++;
		free(line);
		line = ft_get_next_line(glob()->fd);
	}
}

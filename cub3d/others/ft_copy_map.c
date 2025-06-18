/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:29:31 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/10 15:28:51 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_copy_map(void)
{
	char	*line;
	int		i;

	glob()->map = malloc(sizeof(char *) * (glob()->rows + 1));
	if (!glob()->map)
		return (close(glob()->fd), false);
	line = ft_get_next_line(glob()->fd);
	i = -1;
	while (line)
	{
		line[ft_strlen(line) - 1] = 0;
		glob()->map[++i] = ft_strdup(line);
		if (!glob()->map[i])
			return (close(glob()->fd), free(line), false);
		free(line);
		line = ft_get_next_line(glob()->fd);
	}
	glob()->map[++i] = NULL;
	return (close(glob()->fd), true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:26:00 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/10 14:57:41 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_get_size(void)
{
	char	*line;

	line = ft_get_next_line(glob()->fd);
	if (!line)
		return (false);
	while (line)
	{
		glob()->rows++;
		if (!ft_ver_line(line))
			return (close(glob()->fd), free(line), false);
		if (ft_strlen(line) > glob()->max_cols)
			glob()->max_cols = ft_strlen(line);
		free(line);
		line = ft_get_next_line(glob()->fd);
	}
	return (close(glob()->fd), glob()->nsew_count == 1);
}

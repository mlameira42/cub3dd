/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:22:39 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/09 11:03:50 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_floodfill(char **map, int y, int x)
{
	if (x < 0 || y < 0 || y >= glob()->rows || x > (int)ft_strlen(map[y]))
		return (false);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (false);
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (true);
	map[y][x] = 'x';
	return (ft_floodfill(map, y + 1, x)
		&& ft_floodfill(map, y - 1, x)
		&& ft_floodfill(map, y, x + 1)
		&& ft_floodfill(map, y, x - 1));
}

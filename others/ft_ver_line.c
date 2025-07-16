/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ver_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:58:40 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/16 11:09:14 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_ver_line(char *line)
{
	int		i;
	bool	has_char;

	i = -1;
	has_char = false;
	while (line[++i])
	{
		if (!ft_strchr("01NSEW\t\r\v\f\n ", line[i]))
			return (false);
		if (ft_strchr("01NSEW", line[i]))
			has_char = true;
		if (ft_strchr("NSEW", line[i]))
			glob()->nsew_count++;
	}
	return (has_char);
}

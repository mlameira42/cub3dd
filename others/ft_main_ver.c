/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_ver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:12:29 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/17 13:35:29 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_main_ver(void)
{
	glob()->fd = open(glob()->doc, O_RDONLY);
	if (glob()->fd == -1)
		return (false);
	ft_get_info();
	if (!ft_ver_info())
		return (false);
	glob()->fd = open(glob()->doc, O_RDONLY);
	if (glob()->fd == -1)
		return (false);
	ft_get_map_size();
	glob()->fd = open(glob()->doc, O_RDONLY);
	if (glob()->fd == -1)
		return (false);
	if (!ft_copy_map() || !glob()->map[0])
		return (false);
	return (true);
}

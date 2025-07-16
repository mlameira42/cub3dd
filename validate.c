/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:23:05 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/16 11:53:57 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate(char *av)
{
	int	i;

	i = -1;
	ft_init_global(av);
	if (glob()->doc_len < 4)
		return (ft_printf("File name "), ft_exit(1));
	if ((ft_strncmp(glob()->doc + glob()->doc_len - 4, ".cub", 4)))
		return (ft_printf("File name "), ft_exit(1));
	if (!ft_main_ver())
		return (ft_printf("File info "), ft_exit(1));
	if (!ft_dup_map())
		return (ft_printf("Map malloc "), ft_exit(1));
	while (glob()->map[++i])
		if (!ft_ver_line(glob()->map[i]))
			return (ft_printf("Invalid Char "), ft_exit(1));
	if (glob()->nsew_count != 1)
		return (ft_printf("More than 1 player"), ft_exit(1));
	if (glob()->start_point[0] + glob()->start_point[1] == 0)
		return (ft_printf("No player "), ft_exit(1));
	if (!ft_floodfill(glob()->fld_map, glob()->start_point[0],
			glob()->start_point[1]))
		return (ft_printf("Map walls "), ft_exit(1));
}

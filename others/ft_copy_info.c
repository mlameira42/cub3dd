/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:29:01 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/20 16:18:36 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_copy_info(char *str, char c)
{
	if (c == 'N')
		glob()->n_wall_tex = ft_strtrim(str + 3, "\n");
	else if (c == 'S')
		glob()->s_wall_tex = ft_strtrim(str + 3, "\n");
	else if (c == 'E')
		glob()->e_wall_tex = ft_strtrim(str + 3, "\n");
	else if (c == 'W')
		glob()->w_wall_tex = ft_strtrim(str + 3, "\n");
	else if (c == 'F')
		glob()->floor_color = ft_copy_ints(str, c);
	else if (c == 'C')
		glob()->ceil_color = ft_copy_ints(str, c);
}

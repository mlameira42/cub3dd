/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:04:48 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/20 16:12:42 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_debugger(void)
{
	int	i;

	ft_printf("North: %s\n", glob()->n_wall_tex);
	ft_printf("South: %s\n", glob()->s_wall_tex);
	ft_printf("East: %s\n", glob()->e_wall_tex);
	ft_printf("West: %s\n", glob()->w_wall_tex);
	i = -1;
	while (++i < 3)
		ft_printf("floor: %d\n", glob()->floor_color[i]);
	i = -1;
	while (++i < 3)
		ft_printf("ceiling: %d\n", glob()->ceil_color[i]);
	i = -1;
	while (glob()->map[++i])
		ft_printf("map line %d: %s\n", i, glob()->map[i]);
}

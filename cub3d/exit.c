/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:56:16 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/10 14:42:08 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(int status)
{
	if (glob()->doc)
		free(glob()->doc);
	if (glob()->map)
		ft_free_strs(glob()->map);
	if (status)
		ft_fprintf(2, "Error\n");
	exit(status);
}

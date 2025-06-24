/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:23:05 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/24 10:15:50 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate(char *av)
{
		ft_init_global(av);
		if (glob()->doc_len >= 4
			&& !(ft_strncmp(glob()->doc + glob()->doc_len - 4, ".cub", 4)))
		{
			if (ft_main_ver())
				return ;//ft_exit(ft_fprintf(1, "Au rait\n") * 0);
			else
				ft_exit(1);
		}
		else
			ft_exit(1);
}

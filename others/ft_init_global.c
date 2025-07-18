/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_global.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:45:58 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/16 12:39:16 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_global(char *str)
{
	t_global	*global;

	global = glob();
	global->doc = ft_strdup(str);
	if (!global->doc)
		return (ft_printf("Malloc "), ft_exit(1));
	global->map = NULL;
	global->fld_map = NULL;
	global->doc_len = ft_strlen(str);
	global->fd = 0;
	global->rows = 0;
	global->max_cols = 0;
	global->nsew_count = 0;
	global->n_wall_tex = NULL;
	global->s_wall_tex = NULL;
	global->e_wall_tex = NULL;
	global->w_wall_tex = NULL;
	global->empty_lines = 0;
	global->isceilinfo = false;
	global->isfloorinfo = false;
	global->start_point[0] = 0;
	global->start_point[1] = 0;
}

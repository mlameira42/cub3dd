/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_global.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:45:58 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/10 14:55:45 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_global(char *str)
{
	t_global	*global;

	global = glob();
	global->doc = ft_strdup(str);
	if (!global->doc)
		ft_exit(1);
	global->map = NULL;
	global->doc_len = ft_strlen(str);
	global->fd = 0;
	global->rows = 0;
	global->max_cols = 0;
	global->nsew_count = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:04:41 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/07/08 12:37:24 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_dup_map(void)
{
	int		i;

	glob()->fld_map = malloc(sizeof(char *) * (glob()->rows + 1));
	if (!glob()->fld_map)
		return (false);
	i = -1;
	while (glob()->map[++i])
	{
		glob()->fld_map[i] = ft_strdup(glob()->map[i]);
		if (!glob()->fld_map[i])
			return (false);
	}
	glob()->fld_map[i] = NULL;
	return (ft_get_start(), true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:41:51 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/10 14:42:44 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_strs(char **strs)
{
	size_t	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
		i++;
	while (i > 0)
		free(strs[--i]);
	free(strs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_ints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:07:42 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/06/23 15:27:56 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	*ft_copy_ints(char *str, char c)
{
	char	**temp;
	int		i;
	int		*res;

	temp = ft_split(str + 2, ',');
	res = malloc(sizeof(int) * 3);
	if (!temp || !res)
	{
		if (res)
			free(res);
		if (temp)
			ft_free_strs(temp);
		return (NULL);
	}
	i = -1;
	while (temp[++i] && i < 3)
		res[i] = ft_atoi(temp[i]);
	if (i != 3 || (!ft_strchr(temp[2], '0') && !res[2]) || temp[3])
		return (ft_free_strs(temp), free(res), NULL);
	if (c == 'C')
		return (ft_free_strs(temp), glob()->isceilinfo = true, res);
	return (ft_free_strs(temp), glob()->isfloorinfo = true, res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:26:24 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/11/05 14:18:05 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l_list;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	l_list = ft_lstlast(*lst);
	l_list->next = new;
}

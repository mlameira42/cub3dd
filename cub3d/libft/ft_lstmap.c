/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:42:51 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/11/06 18:51:15 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*new_content;
	void	*set;

	if (!lst || !del || !f)
		return (NULL);
	new_l = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_content = ft_lstnew(set);
		if (!new_content)
		{
			del(set);
			ft_lstclear(&new_content, (*del));
			return (new_l);
		}
		ft_lstadd_back(&new_l, new_content);
		lst = lst->next;
	}
	return (new_l);
}

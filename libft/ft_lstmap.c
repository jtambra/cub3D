/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:08:20 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/04 20:49:22 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newptr;
	t_list	*firstptr;

	if (!lst || !f)
		return (NULL);
	firstptr = ft_lstnew(f(lst->content));
	if (!firstptr)
		return (NULL);
	newptr = firstptr;
	while (lst->next)
	{
		lst = lst->next;
		newptr->next = ft_lstnew(f(lst->content));
		if (!(newptr->next))
		{
			ft_lstclear(&firstptr, del);
			return (NULL);
		}
		newptr = newptr->next;
	}
	return (firstptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:16:05 by jtambra           #+#    #+#             */
/*   Updated: 2020/11/24 21:18:35 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*fixedptr;
	t_list	*moveptr;

	if (!*lst)
		return ;
	moveptr = *lst;
	while (moveptr->next)
	{
		fixedptr = moveptr;
		moveptr = moveptr->next;
		if (del)
		{
			del(fixedptr->content);
			free(fixedptr);
		}
	}
	if (del)
	{
		del(moveptr->content);
		free(moveptr);
		*lst = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:35:51 by jtambra           #+#    #+#             */
/*   Updated: 2020/11/28 18:32:36 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;
	size_t				i;

	cdst = (unsigned char *)dst;
	csrc = (const unsigned char *)src;
	i = 0;
	if (!src && !dst)
		return (NULL);
	if (dst > src)
	{
		while (len--)
			cdst[len] = csrc[len];
		return (dst);
	}
	else
	{
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
		return (dst);
	}
}

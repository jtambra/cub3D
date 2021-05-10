/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:58:36 by jtambra           #+#    #+#             */
/*   Updated: 2020/11/11 20:44:55 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ldst;

	i = 0;
	j = ft_strlen(dst);
	ldst = j;
	if (j <= dstsize)
	{
		while (src[i] != '\0' && j + 1 < dstsize)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
		return (ldst + ft_strlen(src));
	}
	return (ft_strlen(src) + dstsize);
}

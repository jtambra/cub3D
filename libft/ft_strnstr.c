/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:50:08 by jtambra           #+#    #+#             */
/*   Updated: 2020/11/26 20:02:29 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;
	size_t	l;

	l = 0;
	h = 0;
	n = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (l < len && haystack[h] && needle[n])
	{
		if ((haystack[h] != needle[n]) && needle[n])
			n = 0;
		if (haystack[h] == needle[n])
			n++;
		h++;
		if (needle[n] == '\0')
			return ((char *)(haystack + h - n));
		l++;
	}
	return (NULL);
}

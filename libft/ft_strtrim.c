/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:30:57 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/04 22:09:08 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	len;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && (ft_strchr(set, *s1)))
		s1++;
	len = ft_strlen(s1);
	while (*s1 && (ft_strrchr(set, s1[len - 1])))
		len--;
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (NULL);
	i = len;
	while (i--)
		*(s2++) = *(s1++);
	*s2 = '\0';
	return (s2 - len);
}

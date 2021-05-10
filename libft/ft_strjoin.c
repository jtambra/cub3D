/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:51:06 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/04 22:07:16 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!(s1 && s2))
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = s1_len + s2_len;
	new = (char *)malloc(i + 1);
	if (!new)
		return (NULL);
	if (s1)
		while (*s1)
			*(new++) = *(s1++);
	if (s2)
		while (*s2)
			*(new++) = *(s2++);
	*new = '\0';
	return (new - i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:41:55 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/23 18:38:37 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char *remainder, int count)
{
	if ((count == -1) || (count == 0 && !remainder))
		return (count);
	return (1);
}

int	ft_n_exist(char **ptr_n, char **remainder)
{
	**ptr_n = '\0';
	(*ptr_n)++;
	*remainder = ft_strdup(*ptr_n);
	if (!(*remainder))
		return (-1);
	return (0);
}

int	ft_rem_exist(char **remainder, char **line, char **ptr_n)
{
	char	*box;

	*ptr_n = ft_strchr(*remainder, '\n');
	if (*ptr_n)
	{
		**ptr_n = '\0';
		(*ptr_n)++;
		if (ft_join_line(&box, remainder, line) == -1)
			return (-1);
		box = *remainder;
		*remainder = ft_strdup(*ptr_n);
		if (!(*remainder))
			return (-1);
	}
	else
	{
		if (ft_join_line(&box, remainder, line) == -1)
			return (-1);
		box = *remainder;
		*remainder = NULL;
	}
	free(box);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			len;
	void			*array;

	len = count * size;
	array = (void *)malloc(len);
	if (!array)
		return (NULL);
	ptr = (unsigned char *)array;
	while (len--)
		ptr[len] = 0;
	return (ptr);
}

int	get_next_line(int fd, char **line)
{
	int			count;
	char		buf[BUFFER_SIZE + 1];
	static char	*remainder;
	char		*ptr_n;

	ptr_n = NULL;
	*line = ft_calloc(1, sizeof(1));
	if ((fd < 0 || BUFFER_SIZE < 1 || !line || !(*line)) || \
		(remainder && (ft_rem_exist(&remainder, line, &ptr_n) == -1)))
		return (-1);
	count = read(fd, buf, BUFFER_SIZE);
	while (!remainder && (count > 0))
	{
		buf[count] = '\0';
		ptr_n = (ft_strchr(buf, '\n'));
		if (ptr_n && ((ft_n_exist(&ptr_n, &remainder)) == -1))
			return (-1);
		ft_add_buf_to_line(line, buf);
		if (!(*line))
			return (-1);
		count = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_check(remainder, count));
}

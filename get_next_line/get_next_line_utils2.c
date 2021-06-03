/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:23:13 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/23 18:35:56 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_add_buf_to_line(char **line, char *buf)
{
	char *box;

	box = *line;
	*line = ft_strjoin(*line, buf);
	free(box);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <jtambra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:09:49 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 21:02:21 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_is_map(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if ((ft_strchr(" 012NSEW", line[i])) != NULL)
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_check_map(char *line, t_parse *parse)
{
	int	y;

	y = 0;
	while (parse->map[y])
	{
		if (!(ft_is_map(parse->map[y])))
		{
			ft_free_all(line, parse);
			ft_exit_cub("Error\nMap should contain only ' 012NSEW'");
		}
		y++;
	}
}

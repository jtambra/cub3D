/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:23:34 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 14:59:56 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_check_wall(char **str, t_parse *parse, size_t y, size_t x)
{
	if ((x == 0) && ((str[y][x] != '1') && (str[y][x] != ' ')))
		return (0);
	if ((y == 0) && ((str[y][x] != '1') && (str[y][x] != ' ')))
		return (0);
	if ((str[y][x + 1] == '\0') && ((str[y][x] != '1')
				&& (str[y][x] != ' ')))
		return (0);
	if ((y == (parse->map_rows - 1)) && ((str[y][x] != '1')
		&& (str[y][x] != ' ')))
		return (0);
	if (str[y][x] == '0')
	{
		if ((str[y][x - 1] == ' ') || (str[y][x + 1] == ' ')
			|| (str[y - 1][x] == ' ') || (str[y + 1][x] == ' ')
			|| (str[y - 1][x - 1] == ' ') || (str[y - 1][x + 1] == ' ')
			|| (str[y + 1][x - 1] == ' ') || (str[y + 1][x + 1] == ' ')
			|| (str[y - 1][x + 1] == '\0') || (str[y + 1][x + 1] == '\0'))
			return (0);
	}
	return (1);
}

static int	ft_check_construction(char **str, t_parse *parse)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (str[y])
	{
		while (str[y][x])
		{
			if (!(ft_check_wall(str, parse, y, x)))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	ft_check_config_map(t_parse *parse)
{
	if (parse->view == ((char) NULL))
	{
		ft_free_all(NULL, parse);
		ft_exit_cub("Error\nThere must be player on the map");
	}
	if (!(ft_check_construction(parse->map, parse)))
	{
		ft_free_all(NULL, parse);
		ft_exit_cub("Error\nMap has bad construction");
	}
}

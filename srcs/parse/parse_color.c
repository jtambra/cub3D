/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:29:30 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 21:02:27 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_init_color(char **arr_color, t_parse *parse, int counter)
{
	int		color[3];

	color[0] = ft_atoi(arr_color[0]);
	color[1] = ft_atoi(arr_color[1]);
	color[2] = ft_atoi(arr_color[2]);
	if ((color[0] < 0 || color[1] < 0 || color[2] < 0 )
		|| (color[0] > 255 || color[1] > 255 || color[2] > 255 ))
		return (1);
	parse->color_arr[counter - 6] = color[0] << 16 | color[1] << 8 | color[2];
	return (0);
}

void	ft_parse_color(char *line, t_parse *parse, int counter)
{
	char	**arr;
	char	**arr_color;

	arr = ft_split(line + 1, ' ');
	if (!arr)
	{
		ft_free_all(line, parse);
		ft_exit_cub("Error\nMemory not allocated for split of color array");
	}
	if (ft_arrlen(arr) != 1)
		free_params(line, parse, arr, "Error\nColor must have one argumet");
	arr_color = ft_split(arr[0], ',');
	if (!arr_color)
		free_params(line, parse, arr, "Error\nMemory not allocated for color");
	ft_free_strs(arr);
	if (ft_arrlen(arr_color) != 3)
		free_params(line, parse, arr_color,
			"Error\nColor must have RGB params, separeted by commas");
	if (!(ft_str_isdigit(arr_color[0])) || !(ft_str_isdigit(arr_color[1]))
		|| !(ft_str_isdigit(arr_color[2])))
		free_params(line, parse, arr_color,
			"Error\nColor value should contain only digits");
	if (ft_init_color(arr_color, parse, counter))
		free_params(line, parse, arr_color, "Error\nIncorrect color value");
	ft_free_strs(arr_color);
}

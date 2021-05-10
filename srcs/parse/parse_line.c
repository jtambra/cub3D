/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:50:17 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 15:00:14 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_config(int *array_flags)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (array_flags[i] == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

static void	fill_config_params(char *line, t_parse *parse, int *counter)
{
	static char		array_pattern[8][4]
					= {"NO ", "SO ", "WE ", "EA ", "S ", "R ", "F ", "C "};
	static	void	(*array_funcs[])(char *parse_line, t_parse *parse,
					int counter)
					= {ft_parse_texture, ft_parse_texture, ft_parse_texture,
					ft_parse_texture, ft_parse_texture, ft_parse_resolution,
					ft_parse_color, ft_parse_color};

	while (*counter < 8)
	{
		if (!ft_strncmp(line, array_pattern[*counter],
				ft_strlen(array_pattern[*counter])))
		{
			if (parse->flags[*counter])
				free_param(line, parse, NULL,
					"Error\nMap arguments cannot repeat");
			parse->flags[*counter] = 1;
			array_funcs[*counter](line, parse, *counter);
			break ;
		}
		(*counter)++;
	}
	if (*counter == 8)
		free_param(line, parse, NULL, "Error\nInvalid map config");
}

void	ft_parse_line(char *line, t_parse *parse)
{
	int		flag;
	int		counter;

	counter = 0;
	if (!(ft_check_config(parse->flags)))
	{
		if (line[0] == 0)
			return ;
		fill_config_params(line, parse, &counter);
	}
	else if (line[0] == 0 && parse->map == NULL)
		return ;
	else if (line[0] == 0 && parse->map != NULL)
		free_param(line, parse, NULL, "Error\nMap cannot contain empty lines");
	else
		ft_parse_map(line, parse);
}

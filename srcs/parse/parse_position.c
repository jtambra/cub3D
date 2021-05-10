/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:13:58 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 15:00:28 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	count_sprites(t_parse *parse, int x, int y)
{
	while (parse->map[y])
	{
		x = 0;
		while (parse->map[y][x])
		{
			if (parse->map[y][x] == '2')
				parse->sprites++;
			x++;
		}
		y++;
	}
}

static void	put_sprites(t_parse *parse, int x, int y, int i)
{
	parse->sprite_arr[i].x = (float)x;
	parse->sprite_arr[i].y = (float)y;
	parse->map[y][x] = '0';
}

static void	put_position(t_parse *parse, int y, int x, int *i)
{
	while (parse->map[y][x])
	{
		if (parse->map[y][x] == 'N' || parse->map[y][x] == 'S' ||
				parse->map[y][x] == 'E' || parse->map[y][x] == 'W')
		{
			parse->view = parse->map[y][x];
			if (parse->player.x == 0 && parse->player.y == 0)
			{
				parse->player.x = (float)x + 0.5;
				parse->player.y = (float)y + 0.5;
				parse->map[y][x] = '0';
			}
			else
				free_param(NULL, parse, NULL,
					"Error\nThere must be only one player on the map");
		}
		if (parse->map[y][x] == '2')
		{
			put_sprites(parse, x, y, *i);
			(*i)++;
		}
		x++;
	}
}

void	ft_parse_position(t_parse *parse)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	count_sprites(parse, x, y);
	parse->sprite_arr = (t_position *)malloc(sizeof(t_position) * \
			parse->sprites);
	if (!(parse->sprite_arr))
		free_param(NULL, parse, NULL, "Error\nThere must be player on the map");
	while (parse->map[y])
	{
		x = 0;
		put_position(parse, y, x, &i);
		y++;
	}
	ft_check_config_map(parse);
}

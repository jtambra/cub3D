/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:38:42 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 21:01:42 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	next_left_y_is_not_wall(t_config *config)
{
	return (config->parse.map[(int)(config->parse.player.y
			+ config->raycast.plane_y * MOVE_SPEED)]
		[(int)config->parse.player.x] != '1');
}

static int	next_left_x_is_not_wall(t_config *config)
{
	return (config->parse.map[(int)config->parse.player.y]
		[(int)(config->parse.player.x
			+ config->raycast.plane_x * MOVE_SPEED)] != '1');
}

static int	next_right_y_is_not_wall(t_config *config)
{
	return (config->parse.map[(int)(config->parse.player.y
			- config->raycast.plane_y * MOVE_SPEED)]
		[(int)config->parse.player.x] != '1');
}

static int	next_right_x_is_not_wall(t_config *config)
{
	return (config->parse.map[(int)config->parse.player.y]
		[(int)(config->parse.player.x
			- config->raycast.plane_x * MOVE_SPEED)] != '1');
}

int	move_left_right(t_config *config)
{
	if (config->keys.d == 1)
	{
		if (next_left_y_is_not_wall(config))
			config->parse.player.y += config->raycast.plane_y * MOVE_SPEED;
		if (next_left_x_is_not_wall(config))
			config->parse.player.x += config->raycast.plane_x * MOVE_SPEED;
	}
	if (config->keys.a == 1)
	{
		if (next_right_y_is_not_wall(config))
			config->parse.player.y -= config->raycast.plane_y * MOVE_SPEED;
		if (next_right_x_is_not_wall(config))
			config->parse.player.x -= config->raycast.plane_x * MOVE_SPEED;
	}
	return (0);
}

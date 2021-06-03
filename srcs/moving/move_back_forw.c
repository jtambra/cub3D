/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back_forw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:30:48 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 21:01:33 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	next_y_is_not_wall(t_config *config)
{
	return (config->parse.map[(int)(config->parse.player.y
			+ config->raycast.dir_y * MOVE_SPEED)]
		[(int)config->parse.player.x] != '1');
}

static int	next_x_is_not_wall(t_config *config)
{
	return (config->parse.map[(int)config->parse.player.y]
		[(int)(config->parse.player.x
			+ config->raycast.dir_x * MOVE_SPEED)] != '1');
}

static int	previous_y_is_not_wall(t_config *config)
{
	return (config->parse.map[(int)(config->parse.player.y
			- config->raycast.dir_y * MOVE_SPEED)]
		[(int)config->parse.player.x] != '1');
}

static int	previous_x_is_not_wall(t_config *config)
{
	return (config->parse.map[(int)config->parse.player.y]
		[(int)(config->parse.player.x
			- config->raycast.dir_x * MOVE_SPEED)] != '1');
}

int	move_forward_backward(t_config *config)
{
	if (config->keys.w == 1)
	{
		if (next_y_is_not_wall(config))
			config->parse.player.y += config->raycast.dir_y * MOVE_SPEED;
		if (next_x_is_not_wall(config))
			config->parse.player.x += config->raycast.dir_x * MOVE_SPEED;
	}
	if (config->keys.s == 1)
	{
		if (previous_y_is_not_wall(config))
			config->parse.player.y -= config->raycast.dir_y * MOVE_SPEED;
		if (previous_x_is_not_wall(config))
			config->parse.player.x -= config->raycast.dir_x * MOVE_SPEED;
	}
	return (0);
}

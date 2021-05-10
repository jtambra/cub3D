/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_left_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:38:59 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/07 23:54:27 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	turn_left(t_config *config)
{
	config->raycast.old_dir_x = config->raycast.dir_x;
	config->raycast.dir_x = config->raycast.dir_x * cos(-ROTATION)
		- config->raycast.dir_y * sin(-ROTATION);
	config->raycast.dir_y = config->raycast.old_dir_x * sin(-ROTATION)
		+ config->raycast.dir_y * cos(-ROTATION);
	config->raycast.old_plane_x = config->raycast.plane_x;
	config->raycast.plane_x = config->raycast.plane_x * cos(-ROTATION)
		- config->raycast.plane_y * sin(-ROTATION);
	config->raycast.plane_y = config->raycast.old_plane_x * sin(-ROTATION)
		+ config->raycast.plane_y * cos(-ROTATION);
}

static void	turn_right(t_config *config)
{
	config->raycast.old_dir_x = config->raycast.dir_x;
	config->raycast.dir_x = config->raycast.dir_x * cos(ROTATION)
		- config->raycast.dir_y * sin(ROTATION);
	config->raycast.dir_y = config->raycast.old_dir_x * sin(ROTATION)
		+ config->raycast.dir_y * cos(ROTATION);
	config->raycast.old_plane_x = config->raycast.plane_x;
	config->raycast.plane_x = config->raycast.plane_x * cos(ROTATION)
		- config->raycast.plane_y * sin(ROTATION);
	config->raycast.plane_y = config->raycast.old_plane_x * sin(ROTATION)
		+ config->raycast.plane_y * cos(ROTATION);
}

void	turn_left_right(t_config *config)
{
	if (config->keys.q == 1 && config->keys.e == 1)
		return ;
	if (config->keys.q == 1)
		turn_left(config);
	if (config->keys.e == 1)
		turn_right(config);
}

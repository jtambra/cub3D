/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <jtambra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:51:54 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 19:02:36 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	calc_start_draw(t_config *config)
{
	config->raycast.draw_start = -config->raycast.line_height / 2
		+ config->raycast.h / 2;
	if (config->raycast.draw_start < 0)
		config->raycast.draw_start = 0;
	config->raycast.draw_end = config->raycast.line_height / 2
		+ config->raycast.h / 2;
	if (config->raycast.draw_end >= (int)config->raycast.h)
		config->raycast.draw_end = config->raycast.h - 1;
}

void	init_images(t_config *config)
{
	if (config->raycast.side == 1)
	{
		if (config->raycast.step_y > 0)
			config->textures.main = &config->textures.north;
		if (config->raycast.step_y < 0)
			config->textures.main = &config->textures.south;
	}
	if (config->raycast.side == 0)
	{
		if (config->raycast.step_x > 0)
			config->textures.main = &config->textures.west;
		if (config->raycast.step_x < 0)
			config->textures.main = &config->textures.east;
	}
}

void	calc_texture(t_config *config, int x)
{
	(void)(x);
	if (config->raycast.side == 0)
		config->draw.wall_coor = config->parse.player.y
			+ config->raycast.perp_wall_dist * config->raycast.ray_dir_y;
	else
		config->draw.wall_coor = config->parse.player.x
			+ config->raycast.perp_wall_dist * config->raycast.ray_dir_x;
	config->draw.wall_coor = config->draw.wall_coor
		- floor(config->draw.wall_coor);
	config->draw.texture_coor_x = (int)(config->draw.wall_coor
			* (double)(config->textures.main->width));
	if (config->raycast.side == 0 && config->raycast.ray_dir_x > 0)
		config->draw.texture_coor_x = config->textures.main->width
			- config->draw.texture_coor_x - 1;
	if (config->raycast.side == 1 && config->raycast.ray_dir_y < 0)
		config->draw.texture_coor_x = config->textures.main->width
			- config->draw.texture_coor_x - 1;
	config->draw.increment = 1.0 * config->textures.main->height
		/ config->raycast.line_height;
	config->draw.texture_pos = (config->raycast.draw_start - config->raycast.h
			/ 2 + config->raycast.line_height / 2) * config->draw.increment;
}

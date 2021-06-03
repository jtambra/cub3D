/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:40:22 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 21:03:22 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	calc_perp_wall(t_config *config)
{
	if (config->raycast.side == 0)
		config->raycast.perp_wall_dist = (config->raycast.map_x
				- config->parse.player.x + (1 - config->raycast.step_x) / 2)
			/ config->raycast.ray_dir_x;
	else
		config->raycast.perp_wall_dist = (config->raycast.map_y
				- config->parse.player.y + (1 - config->raycast.step_y) / 2)
			/ config->raycast.ray_dir_y;
}

static void	move_to_next_square(t_config *config)
{
	if (config->raycast.side_dist_x < config->raycast.side_dist_y)
	{
		config->raycast.side_dist_x += config->raycast.delta_dist_x;
		config->raycast.map_x += config->raycast.step_x;
		config->raycast.side = 0;
	}
	else
	{
		config->raycast.side_dist_y += config->raycast.delta_dist_y;
		config->raycast.map_y += config->raycast.step_y;
		config->raycast.side = 1;
	}
	if (config->parse.map[config->raycast.map_y][config->raycast.map_x] == '1')
		config->raycast.wall_flag = 1;
}

static void	calc_side_distance(t_config *config)
{
	if (config->raycast.ray_dir_x < 0)
	{
		config->raycast.step_x = -1;
		config->raycast.side_dist_x = (config->parse.player.x - config->raycast.map_x) \
							 * config->raycast.delta_dist_x;
	}
	else
	{
		config->raycast.step_x = 1;
		config->raycast.side_dist_x = (config->raycast.map_x + 1.0 - config->parse.player.x) \
							 * config->raycast.delta_dist_x;
	}
	if (config->raycast.ray_dir_y < 0)
	{
		config->raycast.step_y = -1;
		config->raycast.side_dist_y = (config->parse.player.y - config->raycast.map_y) \
							 * config->raycast.delta_dist_y;
	}
	else
	{
		config->raycast.step_y = 1;
		config->raycast.side_dist_y = (config->raycast.map_y + 1.0 - config->parse.player.y) \
							 * config->raycast.delta_dist_y;
	}
}

static void	declare_raycast_params(t_config *config, int x)
{
	config->raycast.camera_x = 2 * x / (double)(config->raycast.w) - 1;
	config->raycast.ray_dir_x = config->raycast.dir_x + config->raycast.plane_x
		* config->raycast.camera_x;
	config->raycast.ray_dir_y = config->raycast.dir_y + config->raycast.plane_y
		* config->raycast.camera_x;
	config->raycast.map_x = (int)(config->parse.player.x);
	config->raycast.map_y = (int)(config->parse.player.y);
	config->raycast.delta_dist_x = fabs(1 / config->raycast.ray_dir_x);
	config->raycast.delta_dist_y = fabs(1 / config->raycast.ray_dir_y);
	config->raycast.wall_flag = 0;
}

void	calculations(t_config *config, int x)
{
	declare_raycast_params(config, x);
	calc_side_distance(config);
	while (config->raycast.wall_flag == 0)
		move_to_next_square(config);
	calc_perp_wall(config);
	config->raycast.line_height = (int)(config->raycast.h
			/ config->raycast.perp_wall_dist);
	calc_start_draw(config);
	init_images(config);
	calc_texture(config, x);
	config->draw.y = config->raycast.draw_start;
}

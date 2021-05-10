/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:46:50 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 14:59:40 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_NS(t_config *config)
{
	if (config->parse.view == 'S')
	{
		config->raycast.dir_x = 0;
		config->raycast.dir_y = 1;
		config->raycast.plane_x = -0.66;
		config->raycast.plane_y = 0;
	}
	else if (config->parse.view == 'N')
	{
		config->raycast.dir_x = 0;
		config->raycast.dir_y = -1;
		config->raycast.plane_x = 0.66;
		config->raycast.plane_y = 0;
	}
}

static void	set_WE(t_config *config)
{
	if (config->parse.view == 'E')
	{
		config->raycast.dir_x = 1;
		config->raycast.dir_y = 0;
		config->raycast.plane_x = 0;
		config->raycast.plane_y = 0.66;
	}
	else if (config->parse.view == 'W')
	{
		config->raycast.dir_x = -1;
		config->raycast.dir_y = 0;
		config->raycast.plane_x = 0;
		config->raycast.plane_y = -0.66;
	}
}

void	set_direction(t_config *config)
{
	if (config->parse.view == 'N' || config->parse.view == 'S')
		set_NS(config);
	else if (config->parse.view == 'W' || config->parse.view == 'E')
		set_WE(config);
}

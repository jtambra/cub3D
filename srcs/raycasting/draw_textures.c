/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:00:13 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 21:03:37 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_textures(t_config *config, int x)
{
	config->draw.texture_coor_y = (int)config->draw.texture_pos
		& (config->textures.main->height - 1);
	config->draw.texture_pos = config->draw.texture_pos
		+ config->draw.increment;
	config->draw.color = ((int *)config->textures.main->addr) \
						 [config->textures.main->height
		* config->draw.texture_coor_y + config->draw.texture_coor_x];
	my_mlx_pixel_put(&config->data, x, config->draw.y, \
			config->draw.color);
}

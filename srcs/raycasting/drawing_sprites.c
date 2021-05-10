/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:19:21 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 15:01:17 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	calc_key_coor(t_config *config, t_sprites *sprites)
{
	sprites->draw_start_y = -sprites->sprite_h / 2 + config->raycast.h / 2;
	sprites->draw_end_y = sprites->sprite_h / 2 + config->raycast.h / 2;
	sprites->draw_start_x = -sprites->sprite_w / 2 + sprites->screen_x;
	sprites->draw_end_x = sprites->sprite_w / 2 + sprites->screen_x;
}

static void	calc_special_cases(t_config *config, t_sprites *sprites)
{
	if (sprites->draw_start_x < 0)
		sprites->draw_start_x = 0;
	if (sprites->draw_start_y < 0)
		sprites->draw_start_y = 0;
	if (sprites->draw_end_y >= config->raycast.h)
		sprites->draw_end_y = config->raycast.h - 1;
}

void	calc_sprite_params(t_config *config, t_sprites *sprites, int i)
{
	sprites->sprite_x = config->parse.sprite_arr[sprites->sprite_order[i]].x
		- config->parse.player.x + 0.5;
	sprites->sprite_y = config->parse.sprite_arr[sprites->sprite_order[i]].y
		- config->parse.player.y + 0.5;
	sprites->inv = 1.0 / (config->raycast.plane_x * config->raycast.dir_y
			- config->raycast.plane_y * config->raycast.dir_x);
	sprites->transform_x = sprites->inv * (config->raycast.dir_y
			* sprites->sprite_x - config->raycast.dir_x * sprites->sprite_y);
	sprites->transform_y = sprites->inv * (-config->raycast.plane_y
			* sprites->sprite_x + config->raycast.plane_x
			* sprites->sprite_y);
	sprites->screen_x = (int)((config->raycast.w / 2)
			* (1 + sprites->transform_x / sprites->transform_y));
	sprites->sprite_h = ((int)fabs(config->raycast.h
				/ (sprites->transform_y)));
	sprites->sprite_w = ((int)fabs(config->raycast.h
				/ (sprites->transform_y)));
	calc_key_coor(config, sprites);
	calc_special_cases(config, sprites);
}

static void	calc_coor_x(t_config *config, t_sprites *sprites)
{
	sprites->tex_coor_x = (int)((256 * (sprites->stripe
					- (-sprites->sprite_w / 2 + sprites->screen_x))
				* config->textures.sprite.width / sprites->sprite_w) / 256);
}

void	drawing(t_config *config, t_sprites *sprites, double *z_buffer)
{
	int	y;
	int	color;

	calc_coor_x(config, sprites);
	if (sprites->transform_y > 0 && sprites->stripe > 0
		&& sprites->stripe < config->raycast.w && sprites->transform_y
		< z_buffer[sprites->stripe])
	{
		y = sprites->draw_start_y;
		while (y < sprites->draw_end_y)
		{
			sprites->d = (int)((y) * 256 - config->raycast.h * 128
					+ sprites->sprite_h * 128);
			sprites->tex_coor_y = ((sprites->d
						* config->textures.sprite.height)
					/ sprites->sprite_h) / 256;
			color = ((int *)config->textures.sprite.addr)
			[config->textures.sprite.height * sprites->tex_coor_y
				+ sprites->tex_coor_x];
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(&config->data, sprites->stripe, \
						y, color);
			y++;
		}
	}
}

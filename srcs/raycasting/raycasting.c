/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <jtambra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 23:57:02 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 19:46:06 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	draw_ceiling(t_config *config)
{
	size_t	x;
	size_t	y;
	int		color;

	y = 0;
	color = config->parse.color_arr[1];
	while (y < config->parse.res[1] / 2)
	{
		x = 0;
		while (x < config->parse.res[0])
		{
			my_mlx_pixel_put(&config->data, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_floor(t_config *config)
{
	size_t	x;
	size_t	y;
	int		color;

	y = config->parse.res[1] / 2;
	color = config->parse.color_arr[0];
	while (y < config->parse.res[1])
	{
		x = 0;
		while (x < config->parse.res[0])
		{
			my_mlx_pixel_put(&config->data, x, y, color);
			x++;
		}
		y++;
	}
}

static void	put_settings(t_config *config)
{
	config->raycast.w = config->parse.res[0];
	config->raycast.h = config->parse.res[1];
	draw_ceiling(config);
	draw_floor(config);
}

static void	malloc_z_buffer(t_config *config, double **z_buffer)
{
	*z_buffer = (double *)malloc(sizeof(double) * config->parse.res[0]);
	if (!z_buffer)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nMemory is not allocated for z_buffer");
	}
}

int	raycasting(t_config *config)
{
	size_t		x;
	double		*z_buffer;

	malloc_z_buffer(config, &z_buffer);
	x = 0;
	put_settings(config);
	player_move(config);
	while (x < config->raycast.w)
	{
		calculations(config, x);
		while (config->draw.y <= config->raycast.draw_end)
		{
			draw_textures(config, x);
			config->draw.y++;
		}
		z_buffer[x] = config->raycast.perp_wall_dist;
		x++;
	}
	draw_sprites(z_buffer, config);
	free(z_buffer);
	mlx_put_image_to_window(config->mlx, config->mlx_win, \
			config->data.img, 0, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 23:46:34 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/07 23:46:37 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	get_texture(t_config *config)
{
	get_north(config);
	get_south(config);
	get_west(config);
	get_east(config);
	get_sprite(config);
}

void	open_window(t_config *config)
{
	config->mlx = mlx_init();
	get_texture(config);
	config->mlx_win = mlx_new_window(config->mlx, config->parse.res[0], \
		config->parse.res[1], "Ortal's Cub");
	config->data.img = mlx_new_image(config->mlx, config->parse.res[0], \
		config->parse.res[1]);
	config->data.addr = mlx_get_data_addr(config->data.img, \
		&config->data.bits_per_pixel, &config->data.line_length, \
		&config->data.endian);
	set_direction(config);
}

void	render(t_config *config)
{
	mlx_do_key_autorepeatoff(config->mlx);
	mlx_hook(config->mlx_win, 2, 0, pressed_key, config);
	mlx_hook(config->mlx_win, 3, 0, unpressed_key, config);
	mlx_loop_hook(config->mlx, raycasting, config);
	mlx_loop(config->mlx);
}

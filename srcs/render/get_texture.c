/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:02:54 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/07 22:06:05 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_north(t_config *config)
{
	config->textures.north.img = mlx_xpm_file_to_image(config->mlx,
			config->parse.texture_arr[0], &config->textures.north.width,
			&config->textures.north.height);
	if (!config->textures.north.img)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nRead texture failed");
	}
	config->textures.north.addr
		= mlx_get_data_addr(config->textures.north.img,
			&config->textures.north.bits_per_pixel,
			&config->textures.north.line_length,
			&config->textures.north.endian);
	if (!config->textures.north.addr)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nRead texture failed");
	}
}

void	get_south(t_config *config)
{
	config->textures.south.img = mlx_xpm_file_to_image(config->mlx,
			config->parse.texture_arr[1], &config->textures.south.width,
			&config->textures.south.height);
	if (!config->textures.south.img)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nRead texture failed");
	}
	config->textures.south.addr
		= mlx_get_data_addr(config->textures.south.img,
			&config->textures.south.bits_per_pixel,
			&config->textures.south.line_length,
			&config->textures.south.endian);
	if (!config->textures.south.addr)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nRead texture failed");
	}
}

void	get_west(t_config *config)
{
	config->textures.west.img = mlx_xpm_file_to_image(config->mlx,
			config->parse.texture_arr[2], &config->textures.west.width,
			&config->textures.west.height);
	if (!config->textures.west.img)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nRead texture failed");
	}
	config->textures.west.addr
		= mlx_get_data_addr(config->textures.west.img,
			&config->textures.west.bits_per_pixel,
			&config->textures.west.line_length,
			&config->textures.west.endian);
	if (!config->textures.west.addr)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nRead texture failed");
	}
}

void	get_east(t_config *config)
{
	config->textures.east.img = mlx_xpm_file_to_image(config->mlx,
			config->parse.texture_arr[3], &config->textures.east.width,
			&config->textures.east.height);
	if (!config->textures.east.img)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nRead texture failed");
	}
	config->textures.east.addr
		= mlx_get_data_addr(config->textures.east.img,
			&config->textures.east.bits_per_pixel,
			&config->textures.east.line_length,
			&config->textures.east.endian);
	if (!config->textures.east.addr)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nRead texture failed");
	}
}

void	get_sprite(t_config *config)
{
	config->textures.sprite.img = mlx_xpm_file_to_image(config->mlx,
			config->parse.texture_arr[4],
			&config->textures.sprite.width,
			&config->textures.sprite.height);
	if (!config->textures.sprite.img)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nRead texture failed");
	}
	config->textures.sprite.addr
		= mlx_get_data_addr(config->textures.sprite.img,
			&config->textures.sprite.bits_per_pixel,
			&config->textures.sprite.line_length,
			&config->textures.sprite.endian);
	if (!config->textures.sprite.addr)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nRead texture failed");
	}
}

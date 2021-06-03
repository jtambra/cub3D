/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <jtambra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:07:10 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 21:03:30 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	change_sort(t_position *sprites, int amount)
{
	int			i;
	int			j;
	t_position	tmp;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (sprites[j].x > sprites[j + 1].x)
			{
				tmp.x = sprites[j].x;
				tmp.y = sprites[j].y;
				sprites[j].x = sprites[j + 1].x;
				sprites[j].y = sprites[j + 1].y;
				sprites[j + 1].x = tmp.x;
				sprites[j + 1].y = tmp.y;
			}
			j++;
		}
		i++;
	}
}

static void	sort_sprites(t_config *config, int *order, double *dist, int amount)
{
	int			i;
	t_position	*sprites;

	sprites = malloc_sp(config, order, dist, amount);
	i = 0;
	while (i < amount)
	{
		sprites[i].x = dist[i];
		sprites[i].y = order[i];
		i++;
	}
	change_sort(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].x;
		order[i] = sprites[amount - i - 1].y;
		i++;
	}
	free(sprites);
}

static void	calc_sprite_order(t_config *config, t_sprites *sprites, int i)
{
	while (i < config->parse.sprites)
	{
		sprites->sprite_order[i] = i;
		sprites->sprite_dist[i] = ((config->parse.player.x
					- config->parse.sprite_arr[i].x)
				* (config->parse.player.x - config->parse.sprite_arr[i].x)
				* (config->parse.player.y - config->parse.sprite_arr[i].y)
				* (config->parse.player.y - config->parse.sprite_arr[i].y));
		i++;
	}
	sort_sprites(config, sprites->sprite_order, sprites->sprite_dist, \
			config->parse.sprites);
}

void	malloc_params(t_config *config, t_sprites *sprites, double *z_buffer)
{
	sprites->sprite_order = (int *)malloc(sizeof(int)
			* config->parse.sprites);
	sprites->sprite_dist = (double *)malloc(sizeof(double)
			* config->parse.sprites);
	if (!(sprites->sprite_order) || !(sprites->sprite_dist))
	{
		if (sprites->sprite_order)
			free(sprites->sprite_order);
		if (sprites->sprite_dist)
			free(sprites->sprite_dist);
		free(z_buffer);
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\n Memory is not allocated for sprites param");
	}
}

void	draw_sprites(double *z_buffer, t_config *config)
{
	int			i;
	t_sprites	*sprites;

	sprites = &config->sprites;
	malloc_params(config, sprites, z_buffer);
	i = 0;
	calc_sprite_order(config, sprites, i);
	while (i < config->parse.sprites)
	{
		calc_sprite_params(config, sprites, i);
		sprites->stripe = sprites->draw_start_x;
		while (sprites->stripe < sprites->draw_end_x)
		{
			drawing(config, sprites, z_buffer);
			sprites->stripe++;
		}
		i++;
	}
	free(sprites->sprite_order);
	free(sprites->sprite_dist);
}

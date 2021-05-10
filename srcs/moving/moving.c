/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:55:27 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/07 23:54:10 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	pressed_key(int keycode, t_config *config)
{
	if (keycode == ESC)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Game is over");
	}
	if (keycode == KEY_W)
		config->keys.w = 1;
	if (keycode == KEY_S)
		config->keys.s = 1;
	if (keycode == KEY_A)
		config->keys.a = 1;
	if (keycode == KEY_D)
		config->keys.d = 1;
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		config->keys.q = 1;
	if (keycode == KEY_RIGHT || keycode == KEY_E)
		config->keys.e = 1;
	return (0);
}

int	unpressed_key(int keycode, t_config *config)
{
	if (keycode == KEY_W)
		config->keys.w = 0;
	if (keycode == KEY_S)
		config->keys.s = 0;
	if (keycode == KEY_A)
		config->keys.a = 0;
	if (keycode == KEY_D)
		config->keys.d = 0;
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		config->keys.q = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_E)
		config->keys.e = 0;
	return (0);
}

static int	unpressed(t_keys *keys)
{
	return (keys->w == 0 && keys->s == 0 && keys->a == 0 && keys->d == 0
		&& keys->q == 0 && keys->e == 0);
}

void	player_move(t_config *config)
{
	if (unpressed(&config->keys) == 1)
		return ;
	if (config->keys.w == 1 || config->keys.s == 1)
		move_forward_backward(config);
	if (config->keys.a == 1 || config->keys.d == 1)
		move_left_right(config);
	if (config->keys.q == 1 || config->keys.e == 1)
		turn_left_right(config);
}

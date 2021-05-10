/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:26:52 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 15:01:24 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_position	*malloc_sp(t_config *config, int *order, double *dist, int amount)
{
	t_position	*sprites;

	sprites = (t_position *)malloc(sizeof(t_position) * amount);
	if (!sprites)
	{
		free(order);
		free(dist);
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nMemory is not allocated for tmp to sort sprites");
	}
	return (sprites);
}

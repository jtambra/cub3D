/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <jtambra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:22:57 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 19:13:03 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	config_bmp(t_config *config)
{
	ft_bzero(config->screen.beatmap_file, 54);
	config->screen.beatmap_file[0] = 'B';
	config->screen.beatmap_file[1] = 'M';
	*((int *)(config->screen.beatmap_file + 2)) = 14 + 40 + \
		4 * config->parse.res[0] * config->parse.res[1];
	*(int *)(config->screen.beatmap_file + 10) = 54;
	*(int *)(config->screen.beatmap_file + 14) = 40;
	*(int *)(config->screen.beatmap_file + 18) = config->parse.res[0];
	*(int *)(config->screen.beatmap_file + 22) = config->parse.res[1];
	*(config->screen.beatmap_file + 26) = 1;
	*(config->screen.beatmap_file + 28) = 32;
}

static void	fill_bmp(t_config *config, int fd)
{
	size_t	x;
	size_t	y;
	int		color;

	y = config->parse.res[1] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < config->parse.res[0])
		{
			color = *(int *)(config->data.addr + (y * config->data.line_length
						+ x * (config->data.bits_per_pixel / 8)));
			if ((write(fd, &color, 4)) == -1)
			{
				ft_free_all(NULL, &config->parse);
				ft_exit_cub("Error\n can not write to a bmp file");
			}
			x++;
		}
		y--;
	}
}

void	make_screenshot(t_config *config)
{
	int	fd;

	open_window(config);
	raycasting(config);
	fd = open("Cub3D.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd < 0)
	{
		ft_free_all(NULL, &config->parse);
		ft_exit_cub("Error\nCan not create bmp file");
	}
	config_bmp(config);
	write(fd, config->screen.beatmap_file, 54);
	fill_bmp(config, fd);
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <jtambra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:56:37 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/09 18:24:25 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_exit_cub(char *str)
{
	ft_putendl_fd(str, 1);
	exit(1);
}

void	ft_open_file(const char *file, t_config *config)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_exit_cub("Error\nFailed to open source file");
	while ((get_next_line(fd, &line)) > 0)
	{
		ft_parse_line(line, &config->parse);
		free(line);
		line = NULL;
	}
	if (!(ft_check_config(config->parse.flags)))
		ft_exit_cub("Error\nFile has no configuration for map");
	ft_check_map(line, &config->parse);
	ft_parse_position(&config->parse);
	free(line);
	close(fd);
}

void	ft_check_unvalid_arg(char *s1, char *s2)
{
	int		i;
	char	*tmp;

	tmp = s1;
	tmp = ft_strrchr(tmp, '/');
	if (tmp)
		tmp++;
	else
		 tmp = s1;
	i = ft_strlen(tmp) - 4;
	if (i < 1)
		ft_exit_cub("Error\nInvalid argument name");
	if (s2)
		if (ft_strncmp(s2, "--save", 7))
			ft_exit_cub("Error\nSecond argument must be \"--save\"");
	if (s1)
	{
		tmp = tmp + i;
		if (ft_strncmp((tmp), ".cub", 5))
			 ft_exit_cub("Error\nFirst argument must end with \".cub\"");
	}
}

int	main(int argc, char **argv)
{
	t_config	config;
	int			i;

	i = 0;
	if (argc < 2 || argc > 3)
		ft_exit_cub("Error\nInvalid argument count");
	if (argc == 2)
		ft_check_unvalid_arg(argv[1], 0);
	else
		ft_check_unvalid_arg(argv[1], argv[2]);
	ft_init_config(&config);
	ft_open_file(argv[1], &config);
	open_window(&config);
	if (argc == 3)
		make_screenshot(&config);
	else
		render(&config);
	ft_free_all(NULL, &config.parse);
	return (0);
}

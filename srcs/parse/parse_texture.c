/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:31:32 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 15:00:41 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static size_t	ft_count_spaces(char *line)
{
	size_t	i;
	size_t	spaces;

	spaces = 0;
	i = ft_strlen(line);
	i--;
	while (line[i] == ' ' && i > 0)
	{
		if (line[i] == ' ' && line[i - 1] == '\\')
			return (spaces);
		i--;
		spaces++;
	}
	return (spaces);
}

static size_t	ft_check_path(char *texture_path)
{
	size_t	i;

	i = 0;
	while (texture_path[i])
	{
		if (texture_path[i] == ' ' && texture_path[i - 1] != '\\')
			return (1);
		i++;
	}
	return (0);
}

void	ft_parse_texture(char *line, t_parse *parse, int counter)
{
	char	*texture_path;
	char	*copy_line;
	size_t	size;

	copy_line = line;
	line = line + 2;
	while (*line == ' ')
		line++;
	if (!line)
		free_param(line, parse, NULL, "Error\nTexture path is empty");
	size = ft_strlen(line) - ft_count_spaces(line);
	texture_path = ft_substr(line, 0, size);
	if (!texture_path)
		free_param(line, parse, NULL,
			"Error\nMemory not allocated for texture path");
	if (ft_check_path(texture_path))
		free_param(copy_line, parse, texture_path,
			"Error\nToo many arguments for texture path");
	parse->texture_arr[counter] = ft_strdup(texture_path);
	if (!(parse->texture_arr[counter]))
		free_param(line, parse, texture_path,
			"Error\nMemory is not allocated for substr of texture array");
	free(texture_path);
}

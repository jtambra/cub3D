/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:00:10 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 15:00:20 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*ft_realloc(char *dst, char *str)
{
	str = ft_strdup(dst);
	if (!str)
		return (NULL);
	return (str);
}

static void	realloc_map(char *line, t_parse *parse, char **ptr, size_t i)
{
	while (ptr[i])
	{
		parse->map[i] = ft_realloc(ptr[i], parse->map[i]);
		if (!(parse->map[i]))
			free_params(line, parse, ptr,
				"Error\nMemory is not reallocated for map string");
		i++;
	}
}

void	ft_parse_map(char *line, t_parse *parse)
{
	char	**ptr;
	size_t	i;

	i = 0;
	if (line[0] != 0)
	{
		if (parse->map_rows == (size_t) NULL)
			parse->map_rows = 0;
		parse->map_rows++;
		ptr = parse->map;
		parse->map = (char **)malloc(sizeof(char *) * parse->map_rows + 1);
		if (!(parse->map))
			free_params(line, parse, ptr,
				"Error\nMemory is not allocated for map array");
		parse->map[parse->map_rows] = NULL;
		if (ptr != NULL)
			realloc_map(line, parse, ptr, i);
		ft_free_strs(ptr);
		parse->map[parse->map_rows - 1] = ft_strdup(line);
	}
	else
	{
		ft_free_all(line, parse);
		ft_exit_cub("Error\nMap cannot contain empty lines");
	}
}

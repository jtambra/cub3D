/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:44:17 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 15:00:48 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (i);
	while (arr[i])
		i++;
	return (i);
}

void	ft_free_strs(char **strs)
{
	char	**tmp;

	if (!strs)
		return ;
	tmp = strs;
	while (*tmp != NULL)
	{
		if (*tmp)
			free(*tmp);
		tmp++;
	}
	free(strs);
}

void	ft_free_all(char *line, t_parse *parse)
{
	int	i;

	i = 0;
	if (line)
		free(line);
	while (i < 5)
	{
		if (parse->texture_arr[i])
		{
			free(parse->texture_arr[i]);
			parse->texture_arr[i] = 0;
		}
		i++;
	}
	ft_free_strs(parse->map);
	parse->map = 0;
	if (parse->sprite_arr)
		free(parse->sprite_arr);
}

void	free_param(char *line, t_parse *parse, char *str, char *error)
{
	ft_free_all(line, parse);
	if (str)
		free(str);
	ft_exit_cub(error);
}

void	free_params(char *line, t_parse *parse, char **strs, char *error)
{
	ft_free_all(line, parse);
	ft_free_strs(strs);
	ft_exit_cub(error);
}

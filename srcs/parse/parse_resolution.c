/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:56:21 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 15:00:34 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_parse_resolution(char *line, t_parse *parse, int counter)
{
	char	**arr_res;

	(void)counter;
	arr_res = ft_split(line + 2, ' ');
	if (!arr_res)
	{
		ft_free_all(line, parse);
		ft_exit_cub("Error\nMemory not allocated for split of resolution value");
	}
	if ((ft_arrlen(arr_res)) != 2)
		free_params(line, parse, arr_res,
			"Error\nToo many arguments for resolution");
	if (!(ft_str_isdigit(arr_res[0])) || !(ft_str_isdigit(arr_res[1])))
		free_params(line, parse, arr_res, "Error\nIncorrect resolution value");
	parse->res[0] = ft_atoi(arr_res[0]);
	parse->res[1] = ft_atoi(arr_res[1]);
	if ((parse->res[0] < 100) || (parse->res[1] < 100))
		free_params(line, parse, arr_res,
			"Error\nMinimal screen resolution must be 100x100");
	if (parse->res[0] >= 5120)
		parse->res[0] = 2880;
	if (parse->res[1] >= 2880)
		parse->res[1] = 1575;
	ft_free_strs(arr_res);
}

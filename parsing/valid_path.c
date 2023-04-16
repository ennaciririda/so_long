/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:24:30 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/16 16:34:23 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	coll_valid_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				error("Error : invalid path\n");
			j++;
		}
		i++;
	}
}

void	exit_valid_path(char **map)
{
	int	*dim;

	dim = return_dim(map, 'E');
	if (map[dim[0]][dim[1] + 1] != 'P' && map[dim[0]][dim[1] - 1] != 'P'
	&& map[dim[0] +1][dim[1]] != 'P' && map[dim[0] - 1][dim[1]] != 'P')
	{
		free(dim);
		error("Error : invalid path\n");
	}
	free(dim);
}

void	valid_path(char **argv)
{
	char	**map;
	int		i;

	i = 0;
	map = read_map(argv);
	change_map(map, 0, 0);
	coll_valid_path(map);
	exit_valid_path(map);
	free_all(map);
}

void	help_fun(int i, int j, char **map)
{
	map[i][j] = 'P';
	change_map(map, i, j);
}

void	change_map(char **map, int i, int j)
{
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (map[i][j + 1] == '0' || map[i][j + 1] == 'C')
					help_fun(i, j + 1, map);
				if (map[i][j - 1] == '0' || map[i][j - 1] == 'C')
					help_fun(i, j - 1, map);
				if (map[i - 1][j] == '0' || map[i - 1][j] == 'C')
					help_fun(i - 1, j, map);
				if (map[i + 1][j] == '0' || map[i + 1][j] == 'C')
					help_fun(i + 1, j, map);
			}
			j++;
		}
		i++;
	}
}

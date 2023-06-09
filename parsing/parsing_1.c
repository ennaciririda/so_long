/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 01:10:02 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/16 16:05:54 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_elements_1(int p, int e, int c)
{
	if (p != 1)
		error("Error : about player\n");
	if (e != 1)
		error("Error : about Exit\n");
	if (c < 1)
		error("Error : at least one collectible\n");
}

void	check_elements(char **split, int e, int c, int p)
{
	int	i;
	int	j;

	i = -1;
	while (split[++i])
	{
		j = 0;
		while (split[i][j])
		{
			if (split[i][j] == '0' || split[i][j] == '1'
			|| split[i][j] == 'E' || split[i][j] == 'P' || split[i][j] == 'C')
			{
				if (split[i][j] == 'E')
					e++;
				if (split[i][j] == 'P')
					p++;
				if (split[i][j] == 'C')
					c++;
			}
			else
				error("Error : map contains foreign element\n");
			j++;
		}
	}
	check_elements_1(p, e, c);
}

void	check_rectengle(char **split)
{
	int		i;
	size_t	size;

	i = 1;
	size = ft_strlen(split[0]);
	while (split[i])
	{
		if (ft_strlen(split[i]) != size)
			error("Error : map must be triengle\n");
		i++;
	}
}

void	check_map_is_close(char **argv, char **split)
{
	int	count;
	int	i;

	i = 0;
	count = count_lines(argv);
	while (split[0][i] && split[count - 1][i])
	{
		if (split[0][i] != '1' || split[count - 1][i] != '1')
			error("Error: map should be close\n");
		i++;
	}
	i = 0;
	while (split[i])
	{
		if (split[i][0] != '1' || split[i][ft_strlen(split[i]) - 1] != '1')
			error("Error: map should be close\n");
		i++;
	}
}

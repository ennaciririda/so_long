/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_dim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:38:02 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/16 16:07:46 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	*return_dim(char **map, char c)
{
	int	row;
	int	col;
	int	*dim;

	row = 0;
	dim = NULL;
	dim = malloc(8);
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == c)
			{
				dim[0] = row;
				dim[1] = col;
				return (dim);
			}
			col++;
		}
		row++;
	}
	return (dim);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:37:41 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/16 13:56:59 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	help_func(t_data *d, int i, int j)
{
	if (d->map[i][j] == '0')
		mlx_put_image_to_window(d->m_p, d->win_p, d->z_p, j * 75, i * 75);
	if (d->map[i][j] == '1')
		mlx_put_image_to_window(d->m_p, d->win_p, d->o_p, j * 75, i * 75);
	if (d->map[i][j] == 'P')
	{
		mlx_put_image_to_window(d->m_p, d->win_p, d->z_p, j * 75, i * 75);
		mlx_put_image_to_window(d->m_p, d->win_p, d->p_p, j * 75, i * 75);
	}
	if (d->map[i][j] == 'C')
	{
		mlx_put_image_to_window(d->m_p, d->win_p, d->z_p, j * 75, i * 75);
		mlx_put_image_to_window(d->m_p, d->win_p, d->c_p, j * 75, i * 75);
	}
	if (d->map[i][j] == 'E')
	{
		mlx_put_image_to_window(d->m_p, d->win_p, d->z_p, j * 75, i * 75);
		if (d->col_n == 0)
			mlx_put_image_to_window(d->m_p, d->win_p, d->f_p, j * 75, i * 75);
		else
			mlx_put_image_to_window(d->m_p, d->win_p, d->e_p, j * 75, i * 75);
	}
}

void	draw_map(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			help_func(d, i, j);
			j++;
		}
		i++;
	}
}

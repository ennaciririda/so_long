/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:37:41 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/14 17:09:23 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *data)
{
	int i = 0;
	int j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->zero_ptr, j *75, i *75);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->one_ptr, j * 75, i * 75);
			if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->zero_ptr, j *75, i *75);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->p_ptr, j * 75, i * 75);
			}
			if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->zero_ptr, j *75, i *75);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->c_ptr, j * 75, i * 75);
			}
			if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->zero_ptr, j *75, i *75);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->e_ptr, j * 75, i * 75);
			}
			j++;
		}
		i++;
	}
}
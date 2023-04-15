/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 00:02:29 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/14 22:37:36 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *data)
{
	if (data->map[data->p_x][data->p_y - 1] == '0')
	{
		data->map[data->p_x][data->p_y - 1] = 'P';
		data->map[data->p_x][data->p_y] = '0';
		data->p_y--;
		data->count++;
		ft_putnbr(data->count);
		ft_putchar('\n');
	}
	else if (data->map[data->p_x][data->p_y - 1] == 'C')
	{
		data->map[data->p_x][data->p_y] = '0';
		data->map[data->p_x][data->p_y - 1] = 'P';
		data->p_y--;
		data->col_n--;
		data->count++;
		ft_putnbr(data->count);
		ft_putchar('\n');
	}
	else if (data->map[data->p_x][data->p_y - 1] == 'E')
		if (data->col_n == 0)
			exit(0);
}

void	move_right(t_data *data)
{
	if (data->map[data->p_x][data->p_y + 1] == '0')
	{
		data->map[data->p_x][data->p_y] = '0';
		data->map[data->p_x][data->p_y + 1] = 'P';
		data->p_y++;
		data->count++;
		ft_putnbr(data->count);
		ft_putchar('\n');
	}
	else if (data->map[data->p_x][data->p_y + 1] == 'C')
	{
		data->map[data->p_x][data->p_y] = '0';
		data->map[data->p_x][data->p_y + 1] = 'P';
		data->p_y++;
		data->col_n--;
		data->count++;
		ft_putnbr(data->count);
		ft_putchar('\n');
	}
	else if (data->map[data->p_x][data->p_y + 1] == 'E')
		if (data->col_n == 0)
			exit(0);
}

void	move_top(t_data *data)
{
	if (data->map[data->p_x - 1][data->p_y] == '0')
	{
		data->map[data->p_x][data->p_y] = '0';
		data->map[data->p_x - 1][data->p_y] = 'P';
		data->p_x--;
		data->count++;
		ft_putnbr(data->count);
		ft_putchar('\n');
	}
	else if (data->map[data->p_x - 1][data->p_y] == 'C')
	{
		data->map[data->p_x][data->p_y] = '0';
		data->map[data->p_x - 1][data->p_y] = 'P';
		data->p_x--;
		data->col_n--;
		data->count++;
		ft_putnbr(data->count);
		ft_putchar('\n');
	}
	else if (data->map[data->p_x - 1][data->p_y] == 'E')
		if (data->col_n == 0)
			exit(0);
}

void	move_bottom(t_data *data)
{
	if (data->map[data->p_x + 1][data->p_y] == '0')
	{
		data->map[data->p_x][data->p_y] = '0';
		data->map[data->p_x + 1][data->p_y] = 'P';
		data->p_x++;
		data->count++;
		ft_putnbr(data->count);
		ft_putchar('\n');
	}
	else if (data->map[data->p_x + 1][data->p_y] == 'C')
	{
		data->map[data->p_x][data->p_y] = '0';
		data->map[data->p_x + 1][data->p_y] = 'P';
		data->p_x++;
		data->col_n--;
		data->count++;
		ft_putnbr(data->count);
		ft_putchar('\n');
	}
	else if (data->map[data->p_x + 1][data->p_y] == 'E')
		if (data->col_n == 0)
			exit(0);
}
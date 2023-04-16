/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:55:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/16 17:40:52 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

t_data	*init_str(char **split)
{
	t_data	*d;
	int		*dim;

	dim = return_dim(split, 'P');
	d = malloc(sizeof(t_data));
	if (!d)
		exit(1);
	d->m_p = mlx_init();
	d->win_p = mlx_new_window(d->m_p, 2025, 600, "so_long");
	d->e_p = mlx_xpm_file_to_image(d->m_p, "textures/E.xpm", &d->i_w, &d->i_w);
	d->f_p = mlx_xpm_file_to_image(d->m_p, "textures/O.xpm", &d->i_w, &d->i_w);
	d->c_p = mlx_xpm_file_to_image(d->m_p, "textures/C.xpm", &d->i_w, &d->i_w);
	check_elemnt(d->m_p, d->win_p, d->e_p, d->f_p);
	d->p_p = mlx_xpm_file_to_image(d->m_p, "textures/P.xpm", &d->i_w, &d->i_w);
	d->z_p = mlx_xpm_file_to_image(d->m_p, "textures/0.xpm", &d->i_w, &d->i_w);
	d->o_p = mlx_xpm_file_to_image(d->m_p, "textures/1.xpm", &d->i_w, &d->i_w);
	d->map = split;
	check_elemnt_1(d->c_p, d->p_p, d->z_p, d->o_p);
	d->i_w = 0;
	d->count = 0;
	d->p_x = dim[0];
	d->p_y = dim[1];
	free(dim);
	d->col_n = count_coll(split);
	return (d);
}

int	move_image(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 123)
	{
		move_left(data);
		draw_map(data);
	}
	else if (keycode == 124)
	{
		move_right(data);
		draw_map(data);
	}
	else if (keycode == 125)
	{
		move_bottom(data);
		draw_map(data);
	}
	else if (keycode == 126)
	{
		move_top(data);
		draw_map(data);
	}
	return (0);
}

int	close_window(t_data *data)
{
	free_all(data->map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**split;
	t_data	*data;

	if (argc == 2)
	{
		check_extension(argc, argv);
		split = read_map(argv);
		check_rectengle(split);
		check_map_is_close(argv, split);
		check_elements(split, 0, 0, 0);
		valid_path(argv);
		data = init_str(split);
		draw_map(data);
		mlx_hook(data->win_p, 2, 0, move_image, data);
		mlx_hook(data->win_p, 17, 0, close_window, data);
		mlx_loop(data->m_p);
	}
	return (0);
}

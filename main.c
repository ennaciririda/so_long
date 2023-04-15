/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:55:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/14 23:08:10 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void fun()
{
	system("leaks so_long");
}

void	check_elemnt(void *elm)
{
	if (!elm)
		exit(EXIT_FAILURE);
}

t_data	*init_str(char **split)
{
	t_data *data;
	int *dim;
	dim = return_dim(split,'P');
	data = malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1425, 600, "so_long");
	data->e_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/E.xpm", &data->img_width, &data->img_width);
	data->c_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/C.xpm", &data->img_width, &data->img_width);
	data->p_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/P.xpm", &data->img_width, &data->img_width);
	data->zero_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/0.xpm", &data->img_width, &data->img_width);
	data->one_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/1.xpm", &data->img_width, &data->img_width);
	data->img_width = 0;
	data->map = split;
	data->count = 0;
	data->p_x = dim[0];
	data->p_y = dim[1];
	data->col_n = count_coll(split);
	return data;
}

int		move_image(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 123) // left
	{
		move_left(data);
		draw_map(data);
	}
	else if (keycode == 124) // right
	{
		move_right(data);
		draw_map(data);
	}
	else if (keycode == 125) // down
	{
		move_bottom(data);
		draw_map(data);
	}
	else if (keycode == 126) // up
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
	return 0;
}


int main(int argc, char **argv)
{
	char **split;
	t_data	*data;

	int i = 0;
	int j = 0;
	if (argc == 2)
	{
		check_extension(argc, argv);
		split = read_map(argv);
		check_rectengle(split);
		check_map_is_close(argv, split);
		check_elements(split);
		valid_path(argv);
		data = init_str(split);
		draw_map(data);
		mlx_hook(data->win_ptr, 2, 0, move_image, data);
		mlx_hook(data->win_ptr, 17, 0, close_window, data);
		mlx_loop(data->mlx_ptr);
	}
	return 0;
}
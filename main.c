/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:55:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/09 20:39:24 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	check_elemnt(void *elm)
{
	if (!elm)
		exit(EXIT_FAILURE);
}

t_data	init_str(t_data data)
{
	data.mlx_ptr = NULL;
	data.win_ptr = NULL;
	data.e_ptr = NULL;
	data.c_ptr = NULL;
	data.p_ptr = NULL;
	data.zero_ptr = NULL;
	data.one_ptr = NULL;
	data.img_width = 0;
	data.map = NULL;
	return data;
}

int		move_image(int keycode, t_data data)
{
	int *dim;
	dim = return_dim( data.map,'P');
	if (keycode == 123) // left arrow
	{
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.zero_ptr, dim[0], dim[1]);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.p_ptr, dim[0] -= 1, dim[1]);
	}
	else if (keycode == 124) // right arrow
	{
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.zero_ptr, dim[0], dim[1]);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.p_ptr, dim[0] += 1, dim[1]);
	}
	else if (keycode == 125) // down arrow
	{
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.zero_ptr, dim[0], dim[1]);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.p_ptr, dim[0], dim[1] += 1);
	}
	else if (keycode == 126) // up arrow
	{
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.zero_ptr, dim[0], dim[1]);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.p_ptr, dim[0], dim[1] -= 1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	char **split;
	t_data	data;

	int i = 0;
	int j = 0;
	data = init_str(data);
	if (argc == 2)
	{
		check_extension(argc, argv);
		split = read_map(argv);
		check_rectengle(split);
		check_map_is_close(argv, split);
		check_elements(split);
		valid_path(argv);
		data.mlx_ptr = mlx_init();
		check_elemnt(data.mlx_ptr);
		data.win_ptr = mlx_new_window(data.mlx_ptr, 1425, 600, "so_long");
		check_elemnt(data.win_ptr);
		data.e_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "textures/E.xpm", &data.img_width, &data.img_width);
		check_elemnt(data.e_ptr);
		data.c_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "textures/C.xpm", &data.img_width, &data.img_width);
		check_elemnt(data.c_ptr);
		data.p_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "textures/P.xpm", &data.img_width, &data.img_width);
		check_elemnt(data.p_ptr);
		data.zero_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "textures/0.xpm", &data.img_width, &data.img_width);
		check_elemnt(data.zero_ptr);
		data.one_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "textures/1.xpm", &data.img_width, &data.img_width);
		check_elemnt(data.one_ptr);
		data.map = split;
		while (split[i])
		{
			j = 0;
			while (split[i][j])
			{
				if (split[i][j] == '0')
					mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.zero_ptr, j *75, i *75);
				if (split[i][j] == '1')
					mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.one_ptr, j * 75, i * 75);
				if (split[i][j] == 'P')
				{
					mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.zero_ptr, j *75, i *75);
					mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.p_ptr, j * 75, i * 75);
				}
				if (split[i][j] == 'C')
				{
					mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.zero_ptr, j *75, i *75);
					mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.c_ptr, j * 75, i * 75);
				}
				if (split[i][j] == 'E')
				{
					mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.zero_ptr, j *75, i *75);
					mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.e_ptr, j * 75, i * 75);
				}
				j++;
			}
			i++;
		}
		mlx_hook(data.win_ptr, 2, (1L<<2), move_image, &data);
		// mlx_hook(win_ptr, 17, 0, close_window, &img);
		mlx_loop(data.mlx_ptr);
	}
	return 0;
}
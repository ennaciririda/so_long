/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:55:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/08 09:33:21 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int deal_key(int key, void *param)
{
	(void)param;
	(void)key;
	char count = 'A';
	count++;
	write(1,&count,1);
	return 0;
}

int main(int argc, char **argv)
{
	char **split;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*e_ptr;
	void	*c_ptr;
	void	*p_ptr;
	void	*zero_ptr;
	void	*one_ptr;
	int		img_width;

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
		mlx_ptr = mlx_init();
		if (!mlx_ptr)
			printf("mlx_ptr\n");
		win_ptr = mlx_new_window(mlx_ptr, 1425, 600, "so_long");
		if (!win_ptr)
			printf("win_ptr\n");
		e_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/E.xpm", &img_width, &img_width);
				if (!e_ptr)
			printf("e_ptr\n");
		c_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/C.xpm", &img_width, &img_width);
				if (!c_ptr)
			printf("c_ptr\n");
		p_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/P.xpm", &img_width, &img_width);
				if (!p_ptr)
			printf("p_ptr\n");
		zero_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/0.xpm", &img_width, &img_width);
				if (!zero_ptr)
			printf("zero_ptr\n");
		one_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/1.xpm", &img_width, &img_width);
				if (!one_ptr)
			printf("one_ptr\n");
		while (split[i])
		{
			j = 0;
			while (split[i][j])
			{
				if (split[i][j] == '0')
					mlx_put_image_to_window(mlx_ptr, win_ptr, zero_ptr, j *75, i *75);
				if (split[i][j] == '1')
					mlx_put_image_to_window(mlx_ptr, win_ptr, one_ptr, j * 75, i * 75);
				if (split[i][j] == 'P')
					mlx_put_image_to_window(mlx_ptr, win_ptr, p_ptr, j * 75, i * 75);
				if (split[i][j] == 'C')
				{
					mlx_put_image_to_window(mlx_ptr, win_ptr, zero_ptr, j *75, i *75);
					mlx_put_image_to_window(mlx_ptr, win_ptr, c_ptr, j * 75, i * 75);
				}
				if (split[i][j] == 'E')
					mlx_put_image_to_window(mlx_ptr, win_ptr, e_ptr, j * 75, i * 75);
				j++;
			}
			i++;
		}
		mlx_key_hook(win_ptr, deal_key, (void *)0);
		mlx_loop(mlx_ptr);

	}
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:24:45 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/09 03:35:45 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

int		close_window(int keycode, t_data *img)
{
	mlx_destroy_image(mlx_ptr, img->img);
	exit(0);
}

int		move_image(int keycode, t_data data)
{
	if (keycode == 123) // left arrow
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img->img, x -= 10, y);
	else if (keycode == 124) // right arrow
		mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, x += 10, y);
	else if (keycode == 125) // down arrow
		mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, x, y += 10);
	else if (keycode == 126) // up arrow
		mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, x, y -= 10);
	return (0);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Image Window");
	img.img = mlx_xpm_file_to_image(mlx_ptr, "image.xpm", &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	// initial position of image
	int x = 50;
	int y = 50;

	// display the image on the window
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, x, y);

	// register callback functions
	mlx_hook(win_ptr, 2, 0, move_image, &img);
	mlx_hook(win_ptr, 17, 0, close_window, &img);

	// start event loop
	mlx_loop(mlx_ptr);

	return (0);
}

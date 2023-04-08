/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:55:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/07 23:52:04 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

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
	if (argc == 2)
	{
		check_extension(argc, argv);
		split = read_map(argv);
		check_rectengle(split);
		check_map_is_close(argv, split);
		check_elements(split);
		valid_path(argv);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 1000, 500, "mlx test");
		mlx_pixel_put(mlx_ptr, win_ptr, 700, 200, 0x42F557);
		mlx_key_hook(win_ptr, deal_key, (void *)0);
		mlx_loop(mlx_ptr);
	}
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:55:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/06 01:26:45 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	char **split;
	if (argc == 2)
	{
		check_extension(argc, argv);
		split = read_map(argv);
		check_rectengle(split);
		check_map_is_close(argv, split);
		check_elements(split);

	}
	return 0;
}
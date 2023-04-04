/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:34:35 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/04 01:16:29 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(int argc, char **argv)
{
char *ext;
if (argc == 2)
{
	ext = argv[1] + ft_strlen(argv[1]) - 4;
	if (ft_strcmp(ext,".ber") != 0)
	{
		write(2,"error of extension\n",19);
		exit(1);
	}
}
}

int main(int argc, char **argv)
{

	check_extension(argc,argv);
}


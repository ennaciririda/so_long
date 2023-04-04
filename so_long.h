/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:33:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/04 01:07:54 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55
# endif

int	ft_strcmp(const char *first, const char *second);
size_t	ft_strlen(const char *str);


#endif
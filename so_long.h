/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:33:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/06 01:17:42 by rennacir         ###   ########.fr       */
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

int		ft_strcmp(const char *first, const char *second);
size_t	ft_strlen(const char *str);
void	check_extension(int argc, char **argv);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, char c);
char	*ft_strdup(char *s1);
size_t	count_lines(char **argv);
char	**read_map(char **argv);
void	check_elements(char **split);
void	error(char *str);
void	check_rectengle(char **split);
void	check_map_is_close(char **argv, char **split);



#endif
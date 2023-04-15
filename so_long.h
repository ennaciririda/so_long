/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:33:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/14 22:23:40 by rennacir         ###   ########.fr       */
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
#include <mlx.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55
# endif

typedef struct s_data{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*e_ptr;
	void	*c_ptr;
	void	*p_ptr;
	void	*zero_ptr;
	void	*one_ptr;
	int		img_width;
	int		p_x;
	int		p_y;
	int		count;
	int		col_n;
	char	**map;
}	t_data;

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
void	change_map(char **map, int i, int j);
int		*return_dim(char **map, char c);
void	valid_path(char **argv);
void	exit_valid_path(char **map);
void	coll_valid_path(char **map);
char	**free_all(char **split);
int	count_coll(char **map);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_top(t_data *data);
void	move_bottom(t_data *data);
void	draw_map(t_data *data);
void	ft_putnbr(int n);
void	ft_putchar(char c);


#endif
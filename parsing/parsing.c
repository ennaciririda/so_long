/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:34:35 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/16 16:31:27 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_extension(int argc, char **argv)
{
	char	*ext;

	if (argc == 2)
	{
		ext = argv[1] + ft_strlen(argv[1]) - 4;
		if (ft_strcmp(ext, ".ber") != 0)
			error("Error : extension\n");
	}
}

char	**free_all(char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (NULL);
}

size_t	count_lines(char **argv)
{
	char	*line;
	size_t	count;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_map_part(char **split, int fd)
{
	char	*line;
	char	*word;
	int		j;

	j = 0;
	line = get_next_line(fd);
	if (!line)
		error("map is empty\n");
	while (line)
	{
		word = ft_strdup(line);
		split[j] = word;
		if (!split[j++])
			free_all(split);
		free(line);
		line = get_next_line(fd);
	}
	split[j] = NULL;
	return (split);
}

char	**read_map(char **argv)
{
	int		j;
	int		fd;
	char	**split;

	fd = open(argv[1], O_RDONLY);
	j = 0;
	split = malloc (sizeof(char *) * (count_lines(argv) + 1));
	if (!split)
		return (NULL);
	split = read_map_part(split, fd);
	close(fd);
	return (split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:37:48 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/14 22:02:34 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_str(const char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	word = malloc(i + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**freeall(char **split)
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

static char	**spl(char **split, const char *s, char c)
{
	int	j;

	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			split[j] = get_str(s, c);
			if (!split[j])
				freeall(split);
			j++;
		}
		while (*s && *s != c)
			s++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	split = malloc (sizeof(char *) * (j + 1));
	if (!split)
		return (NULL);
	split = spl(split, s, c);
	return (split);
}

int main()
{
	char **split;
	split = ft_split("hello guys",' ');
	printf("%c\n",split[1][3]);
}

hello
guys
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:46:53 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/04 17:07:55 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	int		i;
	int		j;
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	i = 0;
	j = 0;
	lens1 = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(lens1 + 1);
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_strchr(char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*s;
	char	*t;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	t = s;
	while (i < len)
	{
		*s = *s1;
		s++;
		s1++;
		i++;
	}
	*s = '\0';
	return (t);
}

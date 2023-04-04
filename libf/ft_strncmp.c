/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:48:43 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/04 01:03:23 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strcmp(const char *first, const char *second)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *)first;
	s = (unsigned char *)second;
	i = 0;
	while ((f[i] || s[i]))
	{
		if (f[i] != s[i])
			return (f[i] - s[i]);
			i++;
	}
	return (0);
}

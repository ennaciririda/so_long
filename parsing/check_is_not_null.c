/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_not_null.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:32:09 by rennacir          #+#    #+#             */
/*   Updated: 2023/04/16 17:41:44 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_elemnt(void *m_p, void *win_p, void *e_p, void *f_p)
{
	if (!m_p)
		exit(EXIT_FAILURE);
	if (!win_p)
		exit(EXIT_FAILURE);
	if (!e_p)
		exit(EXIT_FAILURE);
	if (!f_p)
		exit(EXIT_FAILURE);
}

void	check_elemnt_1(void *c_p, void *p_p, void *z_p, void *o_p)
{
	if (!c_p)
		exit(EXIT_FAILURE);
	if (!p_p)
		exit(EXIT_FAILURE);
	if (!z_p)
		exit(EXIT_FAILURE);
	if (!o_p)
		exit(EXIT_FAILURE);
}

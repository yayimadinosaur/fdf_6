/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:53:07 by wfung             #+#    #+#             */
/*   Updated: 2017/11/28 18:35:36 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(t_env *e)
{
	int		i;
	int		j;
	int		k = 0;
	int		p = 0;
	i = 0;
	printf("w_m_y %f w_m_x %f e_x %f e_y %f\n", e->win_mid_y, e->win_mid_x / 2, e->end_x, e->end_y / 2);
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			e->pts[i][j].x = e->pts[i][j].x + e->win_mid_x - (e->end_x / 2);
			e->pts[i][j].y = e->pts[i][j].y + e->win_mid_y - (e->end_y / 2);
			j++;
		}
		i++;
	}
	while (k < e->row)
	{
		p = 0;
		while (p < e->col)
		{
			printf("e->pts[%i][%i].x = [%f] e->pts[%i][%i].y = [%f]\n", k, p, e->pts[k][p].x, k, p, e->pts[k][p].y);
			p++;
		}
		k++;
	}
}

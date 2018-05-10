/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:53:07 by wfung             #+#    #+#             */
/*   Updated: 2018/04/22 16:55:44 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(t_env *e)
{
	int		i;
	int		j;
	int		k = 0;
	int		p = 0;
	float	new_x_mid;
	float	new_y_mid;

	new_x_mid = (e->pts[e->row - 1][e->col - 1].x - e->pts[0][0].x) / 2;
	new_y_mid = (e->pts[e->row - 1][e->col - 1].y - e->pts[0][0].y) / 2;
	i = 0;
	printf("\ntranslation x = [%f] y = [%f]\n", new_x_mid, new_y_mid);
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			/*
			e->pts[i][j].x = e->pts[i][j].x + e->win_mid_x - (e->end_x / 2);
			e->pts[i][j].y = e->pts[i][j].y + e->win_mid_y - (e->end_y / 2);
			*/
			e->pts[i][j].x += (e->pts[e->row - 1][e->col - 1].x - e->pts[0][0].x) / 2;
			e->pts[i][j].y += (e->pts[e->row - 1][e->col - 1].y - e->pts[0][0].y) / 2;
			j++;
		}
		i++;
	}
	printf("\nprinting new points\n");
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

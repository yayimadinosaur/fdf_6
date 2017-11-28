/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_slope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:09:16 by wfung             #+#    #+#             */
/*   Updated: 2017/11/27 17:14:40 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_slope(t_env *e, int i, int j, int direction)
{
	if (direction == 0)
	{
		e->run = e->pts[i][j + 1].x - e->pts[i][j].x;
		e->rise = e->pts[i][j + 1].y - e->pts[i][j].y;
	}
	else
	{
		e->run = e->pts[i + 1][j].x - e->pts[i][j].x;
		e->rise = e->pts[i + 1][j].y - e->pts[i][j].y;
	}
	printf("i[%i]j[%i]run[%f]rise[%f]\n", i , j, e->run, e->rise);
}

//do too much dont need bottom
////OLD???
/*
void	set_slopex(t_env *e, int n)
{
	int		i;
	int		j;
	int		max_row;

	i = 0;
	n == 1 ? (max_row = e->row - 1) : (max_row = e->row);
	printf(" SET SLOPE AT %i\n", n);
	while (i < max_row)
	{
		j = 0;
		while (j < e->col)
		{
			set_slope2(e, n, i, j);
			if (e->run == 0 || e->rise == 0)
				e->slope = 0;
			else if (e->run > e->rise)
				e->slope = round(e->run) / round(e->rise);
			else if (e->rise > e->run)
				e->slope = round(e->rise) / round(e->run);
			printf("i[%i]j[%i]\nx[%f]\ny[%f]\nz[%f]\nrun[%f]\nrise[%f]\nslope[%f]\noffset[%f]\nadjust[%f]\n\n", i, j, e->pts[i][j].x, e->pts[i][j].y, e->pts[i][j].z, e->run, e->rise, e->slope, e->offset, e->adjust);
			j++;
		}
		i++;
	}
}
*/

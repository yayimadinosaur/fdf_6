/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_limit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:35:13 by wfung             #+#    #+#             */
/*   Updated: 2017/11/18 14:46:44 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_limit(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			e->pts[i][j].run = e->pts[i][j + 1].x - e->pts[i][j].x;
			e->pts[i][j].rise = e->pts[i][j + 1].y - e->pts[i][j].y;
			if (e->pts[i][j].run == 0 || e->pts[i][j].rise == 0)
				e->pts[i][j].m = 0;
			else if (e->pts[i][j].run > e->pts[i][j].rise)
				e->pts[i][j].m = round(e->pts[i][j].run) / round(e->pts[i][j].rise);
			else if (e->pts[i][j].rise > e->pts[i][j].run)
				e->pts[i][j].m = round(e->pts[i][j].rise) / round(e->pts[i][j].run);
			j++;
		}
		i++;
	}
}

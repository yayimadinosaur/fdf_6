/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:04:59 by wfung             #+#    #+#             */
/*   Updated: 2017/11/27 17:18:05 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_straight(t_env *e, int i, int j, int direction)
{
	float	big;
	float	tmp1;	//start
	float	tmp2;	//end

	tmp1 = 0;
	tmp2 = 0;
	direction == 0 ? tmp1 = e->pts[i][j].x : e->pts[i][j].y;
	direction == 0 ? tmp2 = e->pts[i][j + 1].x : e->pts[i + 1][j].y;
	if (tmp2 > tmp1)
	{
		big = tmp2;
		tmp1 = tmp2;
		tmp2 = big;
	}
	while (tmp1 < tmp2)
	{
		if (direction == 0)
			mlx_pixel_put(e->mlx, e->win, tmp1, tmp2, 0xff00);	//green
		else
			mlx_pixel_put(e->mlx, e->win, tmp2, tmp1, 0xff0000);	//red
		tmp1 += 1;
	}
}

void	draw_down(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i + 1 < e->col)
	{
		j = 0;
		while (j < e->row)
		{
			set_slope(e, i, j, 1);
			if (e->run == 0)
				draw_straight(e, i, j, 1);
			j++;
		}
		i++;
	}
}

void	draw_right(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->col)
	{
		j = 0;
		while (j < e->row)
		{
			set_slope(e, i, j, 0);
			j++;
		}
		i++;
	}
}

void	draw(t_env *e)
{
	printf("start draw\n");
	draw_right(e);
	printf("draw_right fin\n");
	draw_down(e);
	printf("draw_down fin\n");
}

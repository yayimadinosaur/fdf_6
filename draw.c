/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:04:59 by wfung             #+#    #+#             */
/*   Updated: 2017/11/27 19:46:56 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_straight(t_env *e, int i, int j, int direction)
{
	float	tmp;
	float	min;	//start
	float	max;	//end

	min = 0;
	max = 0;
	direction == 0 ? min = e->pts[i][j].x : e->pts[i][j].y;
	direction == 0 ? max = e->pts[i][j + 1].x : e->pts[i + 1][j].y;
	if (min > max)
	{
		printf("min [%f] is bigger than max [%f]\n", min, max);
		tmp = min;
		min = max;
		max = tmp;
		printf("flipped\n");
	}
	printf("\ndraw_straight dir [%i] min[%f]max[%f]\n", direction, min, max);	//
	while (min < max)
	{
		printf("min = [%i][%i][%f]\n", i, j, min);
		if (max > 600)
		{
			printf("ERROR! max = [%f]\n", max);
			break;
		}
		if (direction == 0)
			mlx_pixel_put(e->mlx, e->win, min, e->pts[i][j].y, 0xff00);	//green
		else
			mlx_pixel_put(e->mlx, e->win, e->pts[i][j].x, min, 0xff0000);	//red
		min += 1;
	}
}

void	draw_down(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	printf("drawdown START!\n");
	while (i + 1 < e->col)
	{
		j = 0;
		while (j < e->row)
		{
			set_slope(e, i, j, 1);
		//	if (e->run == 0)
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
		while (j + 1 < e->row)
		{
			set_slope(e, i, j, 0);
			draw_straight(e, i, j, 0);
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

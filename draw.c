/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:04:59 by wfung             #+#    #+#             */
/*   Updated: 2018/01/02 18:25:25 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// m > -1 && < 1
/*
void	draw_gradual(t_env *e, int i, int j, int direction)
{
	e->delta = fabs((float)e->run / e->rise);

}

//m < 1 || m < -1
void	draw_sharp(t_env *e, int i, int j, int direction)
{
	e->delta = fabs(e->slope);
}
*/

void	draw_straight(t_env *e, int i, int j, int direction)
{
	float	tmp;
	float	min;	//start
	float	max;	//end

	min = 0;
	max = 0;
	direction == 0 ? min = e->pts[i][j].x : (min = e->pts[i][j].y);
	direction == 0 ? max = e->pts[i][j + 1].x : (max = e->pts[i + 1][j].y);
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
		else if (direction == 1)
			mlx_pixel_put(e->mlx, e->win, e->pts[i][j].x, min, 0xff0000);	//red
		min += 1;
	}
}

//threshold 0.5
//offset 0
//slope = float(rise) / run	 - - float exception fix?
//adjust = 1 if m >= 0 else -1
void	draw_down(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	printf("drawdown START!\n");
	while (i + 1 < e->row)
	{
		j = 0;
		while (j < e->col)
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
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			set_slope(e, i, j, 0);
			if (e->slope == 0)		// downward
				draw_straight(e, i, j, 0);
			else
			{
				e->slope >= 0 ? (e->adjust = 1) : (e->adjust = -1);
				e->offset = 0;
				e->threshold = 0.5;
				if (e->slope >= 0 && e->slope <= 1)
					printf("draw_sharp %i %i 0", i, j);
			//		draw_sharp(e, i, j, 0);
				else
					printf("draw_grad %i %i 0\n", i, j);
			//		draw_gradual(e, i, j, 0);
			}
			printf("draw_right j = %i\n", j);
			j++;
		}
		printf("draw_right i = %i\n", i);
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

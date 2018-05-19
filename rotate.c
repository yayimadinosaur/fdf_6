/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:48:03 by wfung             #+#    #+#             */
/*   Updated: 2018/05/18 20:21:48 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_z(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	printf("printing rotate Z results CHECK e->row %i e->col %i\n", e->row, e->col);
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			printf("rotate_z i[%i]j[%i]\n", i, j);
			e->pts[i][j].x = (e->pts[i][j].x * cos(0.7845))
				- (e->pts[i][j].y * sin(0.7845));
			e->pts[i][j].y = (e->pts[i][j].x * sin(0.7845))
				+ (e->pts[i][j].y * cos(0.7845));
			j++;
		}
		i++;
	}
}

static void	rotate_x(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	printf("printing rotate X results\n");
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			e->pts[i][j].y = (e->pts[i][j].y * cos(0.2845))
				- (e->pts[i][j].z * sin(0.2845));
			e->pts[i][j].z = (e->pts[i][j].y * sin(0.2845))
				+ (e->pts[i][j].z * sin(0.2845));
			j++;
		}
		i++;
	}
}

static void	rotate_y(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	printf("rotating Y\n");
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			e->pts[i][j].x = (e->pts[i][j].x * cos(0.045))
				+ (e->pts[i][j].z * sin(0.045));
			e->pts[i][j].z = -(e->pts[i][j].x * sin(0.045))
				+ (e->pts[i][j].z * cos(0.045));
			j++;
		}
		i++;
	}
}

void		rotate(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	rotate_z(e);
	rotate_x(e);
	rotate_y(e);
	//rotate_z(e);
	//remove below. testing only
	printf("printing rotate results\n");
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			printf("[%i][%i][%f][%f][%f]\n", i, j, e->pts[i][j].x, e->pts[i][j].y, e->pts[i][j].z);
			j++;
		}
		i++;
	}

}
//see if values are correct of rotated

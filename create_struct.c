/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:11:07 by wfung             #+#    #+#             */
/*   Updated: 2018/05/09 17:43:29 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		free_struct(t_pts **store, int n, int col)
{
	int		i;
	int		x;

	i = 0;
	while (n > -1)
	{
		x = col;
		while (x > -1)
		{
			free(&store[n][x]);
			x--;
		}
		free(&store[n]);
		n--;
	}
}

t_pts			**create_struct(int row, int col)
{
	int		i;
	t_pts	**pts;

	i = 0;
	if (!(pts = (t_pts**)malloc(sizeof(t_pts*) * (row))))
		return (NULL);
	while (i < row)
	{
		if (!(pts[i] = (t_pts*)malloc(sizeof(t_pts) * (col))))
		{
			free_struct(pts, i, col);
			return (NULL);
		}
		i++;
	}
	return (pts);
}

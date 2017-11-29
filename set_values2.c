/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:51:20 by wfung             #+#    #+#             */
/*   Updated: 2017/11/28 18:06:14 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_values_2(t_env *e, int i, int j)
{
	e->pts[i][j].x = j * e->gap;
	e->pts[i][j].y = i * e->gap;
//	if (j + 1 < e->row && i + 1 < e->col)
//	{
		//e->pts[i][j].run = round(e->pts[i][j+1].x) - round(e->pts[i][j].x);
		//e->pts[i][j].rise = round(e->pts[i+1][j].y) - round(e->pts[i][j].y);
	//	e->pts[i][j].offset = 0;
//	}
/*
 *do slope after rotate not before
  if (e->pts[i][j].run == 0 || e->pts[i][j].rise == 0)
		e->pts[i][j].m = 0;	//draw straight
	if (e->pts[i][j].run != 0 && e->pts[i][j].rise != 0)
		e->pts[i][j].m = e->pts[i][j].rise / e->pts[i][j].run;
	e->pts[i][j].adjust = (e->pts[i][j].m >= 0 ? 1 : -1);
//	e->pts[i][j].m >= 0 ? e->pts[i][j].adjust = 1 : e->pts[i][j].adjust = -1;
	e->pts[i][j].offset = 0.5;
	*/
}

//need to add int return of -1 because of fail
static void		clean_strsplit(char **buff, char *line, t_env *e, int range)
{
	int		i;

	i = range;
	free(line);
	if (!buff)
	{
		free(e);	//remove? main gets rid of e
		ft_puterror("strsplit failed\n");
	}
	while (i > -1)
	{
		free(buff[i]);
		i--;
	}
	free(buff);
}

static int		set_window1(int n, t_env *e)
{
	if (n <= 0)
	{
		ft_putstr("window size needs to be > 0\n");
		return (-1);
	}
	e->win_size_x = n;
	e->win_size_y = n;
	e->win_mid_x = n / 2;
	e->win_mid_y = n / 2;
	e->start_x = 0;
	e->start_y = 0;
	e->end_x = n - (2 * (n / 10));
	e->end_y = n - (2 * (n / 10));
	e->h_gap = (e->end_y - e->start_y) / (e->row - 1);	//need floats?
	e->w_gap = (e->end_x - e->start_x) / (e->col - 1);	//need floats?
	e->gap = (e->h_gap >= e->w_gap ? e->w_gap : e->h_gap);
	return (1);
}

int			set_values2(int win_size, t_env *e, char **av)
{
	int		i;
	int		j;
	char	*line;
	char	**buff;
	int		fd;

	int		k = 0; //
	int		p = 0; //
	i = 0;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_puterror(".fdf file reading failed\n");
	if (set_window1(win_size, e) != 1)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		if (!(buff = ft_strsplit(line, ' ')))
			clean_strsplit(buff, line, e, e->col);	//need to break after clean str split
		while (j < e->col)
		{
			e->pts[i][j].z = ft_atoi(buff[j]);
			set_values_2(e, i, j);
			j++;
		}
		clean_strsplit(buff, line, e, e->col);
		i++;
	}
	close(fd);
	//	remove everything after
	while (k < e->row)
	{
		p = 0;
		while (p < e->col)
		{
			printf("[%i][%i]x[%f]", p, k, e->pts[k][p].x);
			printf("y[%f]", e->pts[k][p].y);
			printf("z[%f]\n", e->pts[k][p].z);
			p++;
		}
		k++;
	}
	printf("\n");
	return (0);
}

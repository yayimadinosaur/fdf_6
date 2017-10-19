/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:09:47 by wfung             #+#    #+#             */
/*   Updated: 2017/10/18 18:10:08 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_values2(t_env *e, int i, int j)
{
	e->pts[i][j].x = j * e->gap;
	e->pts[i][j].y = i * e->gap;
//	e->pts[i][j].x2 = ((j + 1 < e->col ? (j + 1) * e->gap : e->pts[i][j].x));
//	e->pts[i][j].y2 = ((i + 2 < e->col ? (i + 1) * e->gap : e->pts[i][j].y));
//	e->pts[i][j].run = round(e->pts[i][j].x2) - round(e->pts[i][j].x);
//	e->pts[i][j].rise = round(e->pts[i][j].y2) - round(e->pts[i][j].y);
	e->pts[i][j].run = round(e->pts[i][j+1].x) - round(e->pts[i][j].x);
	e->pts[i][j].rise = round(e->pts[i][j+1].y) - round(e->pts[i][j].y);
	if (e->pts[i][j].run == 0 || e->pts[i][j].rise == 0)
		e->pts[i][j].m = 0;	//draw straight
	else (e->pts[i][j].run != 0 && e->pts[i][j].rise != 0)
		e->pts[i][j].m = e->pts[i][j].rise / e->pts[i][j].run;
	e->pts[i][j].adjust = (e->pts[i][j].m >= 0 ? 1 : -1);
//	e->pts[i][j].m >= 0 ? e->pts[i][j].adjust = 1 : e->pts[i][j].adjust = -1;
	e->pts[i][j].offset = 0.5;
}

static void		clean_strsplit(char **buff, char *line, t_env *e, int range)
{
	int		i;

	i = range;
	free(line);
	if (!buff)
	{
		free(e);
		ft_puterror("strsplit failed\n");
	}
	while (i > -1)
	{
		free(buff[i]);
		i--;
	}
	free(buff);
}

static void	set_window1(int n, t_env *e)
{
//	printf("set values - set window1 1\n");
	if (n < 0)
		ft_putstr("window size needs to be positive\n");
	if (n == 0)
		ft_putstr("window size needs to be > 0\n");
	e->win_size_x = n;
	e->win_size_y = n;
	e->win_mid_x = n / 2;
	e->win_mid_y = n / 2;
	e->start_x = 0;
	e->start_y = 0;
	e->end_x = n - (2 * (n / 10));
	e->end_y = n - (2 * (n / 10));
	e->h_gap = (e->end_y - e->start_y) / (e->row - 1);
	e->w_gap = (e->end_x - e->start_x) / (e->col - 1);
	e->gap = (e->h_gap >= e->w_gap ? e->w_gap : e->h_gap);
//	printf("set values - set window done\n");
}

void			set_values(int win_size, t_env *e, char **av)
{
	int		i;
	int		j;
	char	*line;
	char	**buff;
	int		fd;

	i = 0;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_puterror(".fdf file reading failed\n");
	set_window1(win_size, e);
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		if (!(buff = ft_strsplit(line, ' ')))
			clean_strsplit(buff, line, e, e->col);
		while (j < e->col)
		{
			e->pts[i][j].z = ft_atoi(buff[j]);
			set_values_2(e, i, j);
			printf("setv i[%i]j[%i]\nx [%f] x2 [%f]\ny [%f] y2 [%f]\nz [%f]\nrun [%f]\nrise [%f]\nm [%f]\noffset [%f]\nadjust [%f]\n\n", i, j , e->pts[i][j].x, e->pts[i][j].x2,e->pts[i][j].y, e->pts[i][j].y2,e->pts[i][j].z ,e->pts[i][j].run ,e->pts[i][j].rise ,e->pts[i][j].m ,e->pts[i][j].offset ,e->pts[i][j].adjust );	//
			j++;
		}
		clean_strsplit(buff, line, e, e->col);
		i++;
	}
	close(fd);
}

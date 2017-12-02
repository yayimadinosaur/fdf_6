/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:50:09 by wfung             #+#    #+#             */
/*   Updated: 2017/12/01 17:53:22 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	*e;
	int		n = 600;//
	if (ac != 2)
		ft_puterror("Please include a .fdf file");
	e = parse_fdf(av);
	printf(".fdf parse fin\n");//
	if (set_values2(n, e, av) != 0)
	{
		free(e);
		return (0);
	}
	printf("set_values2 fin\n");
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, n, n, "42");
	printf("start rotate\n");
	rotate(e);
	printf("rotate fin\n");
	translate(e);
	printf("traslate fin\n");
	draw(e);
	mlx_loop(e->mlx);
	return (0);
}
//slope
//delta = abs of slope
//offset = add delta
//
//threshold = when to change
//adjust = 1 if slope >= 0 else -1

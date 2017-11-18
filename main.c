/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:50:09 by wfung             #+#    #+#             */
/*   Updated: 2017/11/17 19:49:41 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	*e;
	if (ac != 2)
		ft_puterror("Please include a .fdf file");
	e = parse_fdf(av);
	printf(".fdf parse fin\n");//
	if (set_values2(600, e, av) != 0)
	{
		free(e);
		return (0);
	}
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 600, 600, "42");
	rotate(e);
	mlx_loop(e->mlx);
	return (0);
}
//slope
//delta = abs of slope
//offset = add delta
//
//threshold = when to change
//adjust = +1 / -1 depending on slope

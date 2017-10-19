/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:50:09 by wfung             #+#    #+#             */
/*   Updated: 2017/10/18 17:56:32 by wfung            ###   ########.fr       */
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

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 600, 600, "42");
	mlx_loop(e->mlx);
	return (0);
}

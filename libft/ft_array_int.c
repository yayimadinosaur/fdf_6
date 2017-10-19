/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:51:36 by wfung             #+#    #+#             */
/*   Updated: 2017/08/14 19:08:37 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		clean_struct(int **array_int, int i, int j)
{
	int		n;

	while (i > 0)
	{
		n = j;
		while (n > 0)
		{
			free(&array_int[i][n]);
			n--;
		}
		free(array_int[i]);
		i--;
	}
}

int		**ft_array_int(int row, int col)
{
	int		i;
	int		j;
	int		**array_int;

	i = 0;
	if (!(array_int = (int**)malloc(sizeof(int*) * (row))))
		return (NULL);
	while (i < row)
	{
		j = 0;
		if (!(array_int[i] = (int*)malloc(sizeof(int) * (col))))
		{
			clean_struct(array_int, i, j);
			return (NULL);
		}
		while (j < col)
		{
			array_int[i][j] = 0;
			j++;
		}
		i++;
	}
	return (array_int);
}

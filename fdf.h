/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:46:24 by wfung             #+#    #+#             */
/*   Updated: 2018/05/17 20:22:46 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include <unistd.h> 
#include <stdlib.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "minilibx_macos/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define WHT 0xfffafa
#define	RED 0xff0000
#define GRN 0xff00


#include <stdio.h>	//

//values for the 3 pts; not sure if needed?
typedef struct			s_pts
{
	float					x;
	float					y;
	float					z;
}						t_pts;	//malloc for (**t_pts) row * col

typedef struct			s_env
{
	void				*mlx;
	void				*win;

	int			win_mid_x;
	int		win_mid_y;
	int					win_size_x;	//win
	int					win_size_y;	//win
	int	end_x;
	int end_y;
	int start_x;
	int start_y;

	t_pts				**pts;	//single array for future ref

	float				gap;
	float	h_gap;
	float	w_gap;
	int					row;
	int					col;
}						t_env;

// to access point (x, y) in pts we do pts[x + row * y];

t_env		*parse_fdf(char **av);

int			set_values2(int win_size, t_env *e, char **av);

t_pts		**create_struct(int row, int col);
void		array_int(char **result_str, int n, int *array);

void		draw(t_env *e);

void		draw1(t_env *e);

void		draw2(t_env *e);

void		draw3(t_env *e); //newest

void		draw_right(t_env *e);
void		draw_down(t_env *e);
void		rotate(t_env *e);
void		set_slope(t_env *e, int i, int j, int direction);
void		translate(t_env *e);
//
//ttest functions
void		print_test(t_env *e);
//theo
void		draw_points(t_env *e);
void		transform_to_screen(t_env *);
void		pixel_put(t_env *e, int x, int y, unsigned color);
#endif

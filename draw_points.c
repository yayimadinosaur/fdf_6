#include "fdf.h"

void	draw_line(t_env *e, t_pts p1, t_pts p2)
{
	float	vect_x;
	float	vect_y;
	float	dist;
	float	iter;

	iter = 0;
	vect_x = p2.x - p1.x;
	vect_y = p2.y - p1.y;
	dist = sqrt(vect_x * vect_x + vect_y * vect_y);
	vect_x /= dist;
	vect_y /= dist;
	while (iter < dist)
	{
		pixel_put(e, roundf(p1.x), roundf(p1.y), 0xff00);	//grn
		p1.x += vect_x;
		p1.y += vect_y;
		iter += 1;
	}	
}

void	draw_points(t_env *e)
{
	int i = 0;
	int j;
//	int color_x = 0;
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
		//	pixel_put(e, e->pts[i][j].x, e->pts[i][j].y, 0xff00);	//grn
			if (j + 1 < e->col)
				draw_line(e, e->pts[i][j], e->pts[i][j + 1]);
			if (i + 1 < e->row)
				draw_line(e, e->pts[i][j], e->pts[i + 1][j]);
			j += 1;
		}
		i += 1;
	}
}

//grn
		//	mlx_pixel_put(e->mlx, e->win, e->pts[i][j].x + e->win_size_x / 2, e->pts[i][j].y + e->win_size_y / 2, 0xff00);//grn
/* testing where pixels are drawn first
			if (color_x == 0)
				mlx_pixel_put(e->mlx, e->win, e->pts[i][j].x, e->pts[i][j].y, 0xff00);//grn
if (color_x == 1)
				mlx_pixel_put(e->mlx, e->win, e->pts[i][j].x, e->pts[i][j].y, 0x80);//blue
if (color_x == 2)
				mlx_pixel_put(e->mlx, e->win, e->pts[i][j].x, e->pts[i][j].y, 0xff0000);//red
if (color_x == 3)
				mlx_pixel_put(e->mlx, e->win, e->pts[i][j].x, e->pts[i][j].y, 0xffffff);//wht
color_x +=1;
*/

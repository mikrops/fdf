/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:16:22 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/17 20:29:52 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_bresenham(t_bresenham *bresenham, t_line *line)
{
    bresenham->x1 = (int)line->start.x;
    bresenham->y1 = (int)line->start.y;
    bresenham->x2 = (int)line->end.x;
    bresenham->y2 = (int)line->end.y;
	bresenham->deltax = abs(bresenham->x2 - bresenham->x1);
	bresenham->deltay = abs(bresenham->y2 - bresenham->y1);
	bresenham->deltaerror = bresenham->deltax - bresenham->deltay;
	bresenham->dirx = bresenham->x1 < bresenham->x2 ? 1 : -1;
	bresenham->diry = bresenham->y1 < bresenham->y2 ? 1 : -1;
	bresenham->error = 0;
}

void		put_line(t_mlx *mlx, t_window *win, t_line *line)
{
	int col;

	col = 0;
	t_bresenham	bresenham;
	init_bresenham(&bresenham, line);
	mlx_pixel_put(mlx->ptr, win->ptr, bresenham.x1, bresenham.y1, 0xFFFFFF);
	while (bresenham.x1 != bresenham.x2 || bresenham.y1 != bresenham.y2)
	{
//		col = line->start.z > 0 ? 8232311 + ((line->start.z + 1) * 20) : 23423 - ((line->start.z + 1) * 20);
		col = AQUAMARINE;
		mlx_pixel_put(mlx->ptr, win->ptr, bresenham.x1, bresenham.y1, col);
		//printf("pixel [%d/%d %d/%d]\t", bresenham.x1, bresenham.x2, bresenham.y1, bresenham.y2);
		bresenham.error = bresenham.deltaerror * 2;
		if (bresenham.error > -bresenham.deltay)
		{
			bresenham.deltaerror -= bresenham.deltay;
			bresenham.x1 += bresenham.dirx;
		}
		if (bresenham.error < bresenham.deltax)
		{
			bresenham.deltaerror += bresenham.deltax;
			bresenham.y1 += bresenham.diry;
		}
		//printf("pixel [%d/%d %d/%d]\n", bresenham.x1, bresenham.x2, bresenham.y1, bresenham.y2);
	}
	//printf("\n");
}

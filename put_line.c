/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:16:22 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/24 19:13:45 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int color(int themes, t_line *line)
{
	int	col;

	col = AQUAMARINE;
	if (themes % 2)
	{
		if (line->start.z != 0 && line->end.z != 0)
			col = line->start.z > 0 ? 8232311 + ((line->start.z + 1) * 20) :
					23423 - ((line->start.z + 1) * 20);
	}
	else if (themes % 3)
	{
		if (line->start.color > 0 && line->end.color > 0 &&
			line->start.color == line->end.color)
			col = line->start.color;
	}
	return(col);
}

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

	col = AQUAMARINE;
	t_bresenham	bresenham;
	init_bresenham(&bresenham, line);
	while (bresenham.x1 != bresenham.x2 || bresenham.y1 != bresenham.y2)
	{
		col = color(win->themes, line);
		mlx_pixel_put(mlx->ptr, win->ptr, bresenham.x1, bresenham.y1, col);
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
	}
	mlx_pixel_put(mlx->ptr, win->ptr, bresenham.x1, bresenham.y1, col);
}

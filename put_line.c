/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:16:22 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/10 17:24:18 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_bresenham(t_bresenham *bresenham, t_line *line)
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

void	put_line(t_mlx *mlx, t_line *line)
{
	t_bresenham	bresenham;
	init_bresenham(&bresenham, line);

	while (bresenham.x1 != bresenham.x2 || bresenham.y1 != bresenham.y2)
	{
		mlx_pixel_put(mlx->ptr, mlx->win.ptr, bresenham.x1, bresenham.y1, 0xaaFFFF);
		printf("pixel [%d/%d %d/%d]\t", bresenham.x1, bresenham.x2, bresenham.y1, bresenham.y2);
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
		printf("pixel [%d/%d %d/%d]\n", bresenham.x1, bresenham.x2, bresenham.y1, bresenham.y2);
	}
	printf("\n");
}

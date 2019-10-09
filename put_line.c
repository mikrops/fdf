/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:25:00 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/09 18:18:42 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_bresenham(t_bresenham *bresenham, t_line *line)
{
	bresenham->deltax = abs((int)(line->finish.x - line->start.x));
	bresenham->deltay = abs((int)(line->finish.y - line->start.y));
	bresenham->error = 0;
	bresenham->dirx = (int)line->start.x < (int)line->finish.x ? 1 : -1;
	bresenham->diry = (int)line->start.y < (int)line->finish.y ? 1 : -1;
	bresenham->x = (int)line->start.x;
	bresenham->y = (int)line->start.y;
	//bresenham->error = bresenham->deltax - bresenham->deltay;
}

void	line_east(void *mlx_ptr, void *win_ptr, t_line *line)
{
	t_bresenham	bresenham;
	init_bresenham(&bresenham, line);

	int			deltaerr;
	deltaerr = bresenham.deltay;
	while (bresenham.x < line->finish.x || bresenham.y < line->finish.y)
	{
		printf("pixel [%d %d]\n", bresenham.x, bresenham.y);
		mlx_pixel_put(mlx_ptr, win_ptr, bresenham.x, bresenham.y, 0xaaFFFF);
		bresenham.error += deltaerr;
		if (2 * bresenham.error > -bresenham.deltay)
		{
			bresenham.y += bresenham.diry;
			bresenham.error -= bresenham.deltax;
		}

		bresenham.x++;
	}

//	while (bresenham.x != line->finish.x || bresenham.y != line->finish.y)
//	{
//		printf("pixel [%d %d]\n", bresenham.x, bresenham.y);
//		mlx_pixel_put(mlx_ptr, win_ptr, bresenham.x, bresenham.y, 0xaaFFFF);
//		if (2 * bresenham.error > -bresenham.deltay)
//		{
//			bresenham.error -= bresenham.deltay;
//			bresenham.x += bresenham.dirx;
//		}
//		if (2 * bresenham.error < bresenham.deltax)
//		{
//			bresenham.error += bresenham.deltax;
//			bresenham.y += bresenham.diry;
//		}
//	}
}

void	put_line(void *mlx_ptr, void *win_ptr, t_line *line)
{
	line_east(mlx_ptr, win_ptr, line);
}

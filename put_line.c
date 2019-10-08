/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:25:00 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/08 20:52:19 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void put_line(void *mlx_ptr, void *win_ptr, t_line *line)
{
	double	delraerr;
	double	error;
	int		deltax;
	int 	deltay;
	int 	y;
	int 	diry;
	int		x;

	deltax = abs((int)(line->finish.x - line->start.x));
	deltay = abs((int)(line->finish.y - line->start.y));
	delraerr = (int)(deltay / deltax);
	y = (int)line->start.y;
	diry = (int)(line->finish.y - line->start.y);
	if (diry > 0)
		diry = 1;
	if (diry < 0)
		diry = -1;
	x = (int)line->start.x;
	error = 0;
	while (x < line->finish.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		delraerr += error;
		if (error >= 0.5)
		{
			y += diry;
			error -= 1.0;
		}
		x++;
	}
}

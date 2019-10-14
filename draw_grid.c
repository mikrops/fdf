/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:19:40 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/14 16:37:19 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(t_mlx *mlx, t_line *line, t_map *map)
{
	int i;
	int j;

	i = 1;
	j = 1;
	mlx->zoom = ((double)(mlx->win.width + mlx->win.width) / 2) / ((double)(map->col + map->row) / 2) * 0.8;

	line->start.x = (int)(mlx->win.width / map->col) / 1.8;
	line->start.y = (int)(mlx->win.height / map->row) / 1.8;
	line->end.x = line->start.x;
	line->end.y = line->start.y;
	while (j <= map->row + 1)
	{
		while (i <= map->col + 1)
		{
			if (j == 1 && i <= map->col)
				line->end.x += mlx->zoom;
			if (j > 1)
			{
				line->end.y -= mlx->zoom;
				put_line(mlx, line);
				//dprintf(2, "[%0.0f:%0.0f %0.0f:%0.0f]", line->start.x, line->start.y, line->end.x, line->end.y);
				line->end.y += mlx->zoom;
			}
			if (j > 1 && i <= map->col)
				line->end.x += mlx->zoom;
			put_line(mlx, line);
//			dprintf(1, "[s%0.0f:%0.0f e%0.0f:%0.0f]", line->start.x, line->start.y, line->end.x, line->end.y);
//			line->start.y += 3;
//			line->end.y += 2;
//			line->start.x += 5;
//			line->end.x += 5;
			line->start.x += mlx->zoom;
			i++;
		}

		line->start.x = (int)(mlx->win.width / map->col) / 1.8;
		line->start.y = (int)(mlx->win.height / map->row) / 1.8 + (mlx->zoom * j);
		line->end.x = line->start.x;
		line->end.y = line->start.y;
		i = 1;
		j++;
		//dprintf(2, "\n");
//		dprintf(1, "\n");
	}

}
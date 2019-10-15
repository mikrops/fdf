/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:19:40 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/15 21:02:07 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(t_mlx *mlx, t_line *line, t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
//	mlx->zoom = ((double)(mlx->win.width + mlx->win.height) / 2) / ((double)(map->col + map->row) / 2) * 0.5;
//	mlx->zoom = ((double)(mlx->win.height) / ((double)map->col)) * 0.45;


//	line->end.x = line->start.x;
//	line->end.y = line->start.y;
	int k = 25;
	line->start = map->start_p[j][i];// * k;
	line->end = map->start_p[j][i];// * k;
	printf("\nrow = %d \t col = %d\n", map->row, map->col);
	while (j < map->row)
	{
		while (i < map->col)
		{
			i++;
			if (j > 0)
			{
				line->start.x = map->start_p[j][i-1].x;
				line->end.y = map->start_p[j - 1][i].y * k;
				//line->end.x = map->start_p[j][i-1].x;
				put_line(mlx, line);
				line->end.y = map->start_p[j][i].y;
				line->start.x = map->start_p[j][i].x * k;
				printf("[%d:%d]", j, i);
			}

			if (i < map->col)
			{
				line->end.x = map->start_p[j][i].x * k;
				put_line(mlx, line);
				printf("[%d:%d]", j, i);
				//line->end.x = map->start_p[j][i].x;
			}

//			line->start.x = map->start_p[j][i].x * k;
			line->start.x = line->end.x;

		}
		i = 0;
		line->start.x = map->start_p[j][i].x;
		line->start.y = map->start_p[j][i].y * k;


		j++;
//		if (j < map->row)
//		{
//			line->start.x = map->start_p[j][i].x;
//			line->start.y = map->start_p[j][i].y * k;
//		}

		printf("\n");

//		line->start.x = map->start_p[j][i].x;
//		line->start.y = map->start_p[j][i].y;
//		line->end.x = line->start.x;
//		line->end.y = line->start.y;
	}


//	i = 1;
//	j = 1;
////	mlx->zoom = ((double)(mlx->win.width + mlx->win.height) / 2) / ((double)(map->col + map->row) / 2) * 0.5;
//	mlx->zoom = ((double)(mlx->win.height) / ((double)map->col)) * 0.45;
//
//	line->start.x = (int)(mlx->win.width / map->col) / 1.8;
//	line->start.y = (int)(mlx->win.height / map->row) / 1.8;
//	line->end.x = line->start.x;
//	line->end.y = line->start.y;
//	printf("\nrow = %d \t col = %d\n", map->row, map->col);
//	while (j <= map->row + 1)
//	{
//		while (i <= map->col + 1)
//		{
//			if (j > 1)
//			{
//				line->end.y -= mlx->zoom;
//				put_line(mlx, line);
//				line->end.y += mlx->zoom;
//			}
//			if (i <= map->col)
//				line->end.x += mlx->zoom;
//
//			put_line(mlx, line);
//			line->start.x += mlx->zoom;
//			i++;
//		}
//		line->start.x = (int)(mlx->win.width / map->col) / 1.8;
//		line->start.y = (int)(mlx->win.height / map->row) / 1.8 + (mlx->zoom * j);
//		line->end.x = line->start.x;
//		line->end.y = line->start.y;
//		i = 1;
//		j++;
//	}
}
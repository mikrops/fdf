/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:19:40 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/12 18:27:03 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(t_mlx *mlx, t_line *line, t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	mlx->zoom = ((double)(mlx->win.width+mlx->win.width)/2) / ((double)(map->col + map->row) / 2)/ 2;

	line->start.x = 50;//(int)(mlx->win.width / map->col) / 2.8;
	line->start.y = 50;//(int)(mlx->win.height / map->col) / 2.8;
	line->end.x = line->start.x;
	line->end.y = line->start.y;
	while (j < map->row)
	{
		line->end.x = mlx->zoom * map->col;
		put_line(mlx, line);
		line->end.x = 0;
		line->start.y += mlx->zoom;
		line->end.y += mlx->zoom;
		j++;
	}

	line->start.x = 50;//(int)(mlx->win.width / map->col) / 2.8;
	line->start.y = 50;//(int)(mlx->win.height / map->col) / 2.8;
	line->end.x = line->start.x;
	line->end.y = line->start.y;
	while (i < map->col)
	{
		line->end.y = mlx->zoom * map->row;
		put_line(mlx, line);
		line->end.y = 0;
		line->start.x += mlx->zoom;
		line->end.x += mlx->zoom;
		i++;
	}
}
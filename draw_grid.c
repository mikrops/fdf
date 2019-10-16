/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:19:40 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/16 19:08:12 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(t_mlx *mlx, t_line *line, t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
//	printf("\nrow = %d \t col = %d\n", map->row, map->col);
	while (j < map->row)
	{
		line->start = map->start_p[j][i];
		while (i < map->col)
		{
			i++;
			if (j > 0)
			{
				line->end = map->start_p[j - 1][i - 1];
				put_line(mlx, line);
				line->end = map->start_p[j][i];
//				printf("[%d:%d] ", j, i);
			}
			if (i < map->col)
			{
				line->end = map->start_p[j][i];
				put_line(mlx, line);
//				printf("%s[%d:%d]%s ", "\x1B[32m", j, i, "\x1B[0m");
			}
			line->start = map->start_p[j][i];
		}
		i = 0;
		j++;
//		printf("\n");
	}
}
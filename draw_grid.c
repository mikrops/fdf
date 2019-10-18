/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:19:40 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/18 12:52:10 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(t_fdf *fdf)
{
	t_line	line;
	int i;
	int j;

	i = 0;
	j = 0;
//	printf("\nrow = %d \t col = %d\n", map->row, map->col);
	while (j < fdf->map.row)
	{
		line.start = fdf->map.other_p[j][i];
		while (i < fdf->map.col)
		{
			i++;
			if (j > 0)
			{
				line.end = fdf->map.other_p[j - 1][i - 1];
				put_line(&fdf->mlx, &fdf->win, &line);
				line.end = fdf->map.other_p[j][i];
//				printf("[%d:%d] ", j, i);
			}
			if (i < fdf->map.col)
			{
				line.end = fdf->map.other_p[j][i];
				put_line(&fdf->mlx, &fdf->win, &line);
//				printf("%s[%d:%d]%s ", "\x1B[32m", j, i, "\x1B[0m");
			}
			line.start = fdf->map.other_p[j][i];
		}
		i = 0;
		j++;
	}
}

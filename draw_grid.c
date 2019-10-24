/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:19:40 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/24 16:52:32 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_line_gorizont(t_fdf *fdf, t_line *line, int j, int i)
{
	line->end = fdf->map.other[j - 1][i - 1];
	put_line(&fdf->mlx, &fdf->win, line);
	line->end = fdf->map.other[j][i];
}

void	put_line_vertical(t_fdf *fdf, t_line *line, int j, int i)
{
	line->end = fdf->map.other[j][i];
	put_line(&fdf->mlx, &fdf->win, line);
}

/*
**	Выводит сетку по матрице t_point
*/

void	draw_grid(t_fdf *fdf)
{
	t_line	line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < fdf->map.row)
	{
		line.start = fdf->map.other[j][i];
		while (i < fdf->map.col)
		{
			i++;
			if (j > 0)
				put_line_gorizont(fdf, &line, j, i);
			if (i < fdf->map.col)
				put_line_vertical(fdf, &line, j, i);
			line.start = fdf->map.other[j][i];
		}
		i = 0;
		j++;
	}
}

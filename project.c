/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:48:33 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/18 19:04:06 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void iso(double angle, double *x, double *y, double z)
{
	double	previous_x;
	double	previous_y;

	previous_x = *x;
	previous_y = *y;
	if (angle != 0.0)
	{
		*x = (previous_x - previous_y) * cos(angle);
		*y = -z + (previous_x + previous_y) * sin(angle);
	}
}

void project(t_map *map, double angle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->row)
	{
		while (i < map->col)
		{
			iso(angle, &map->other_p[j][i].x, &map->other_p[j][i].y,
					map->other_p[j][i].z);
			i++;
		}
		i = 0;
		j++;
	}
}

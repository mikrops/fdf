/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:48:33 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/16 20:44:37 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void iso(double angle, double *x, double *y, double z)
{
	double	previous_x;
	double	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(angle);
	*y = -z + (previous_x + previous_y) * sin(angle);
}

void project(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->row)
	{
		while (i < map->col)
		{
			map->start_p[j][i].x *= map->scale;
			map->start_p[j][i].y *= map->scale;;
			map->start_p[j][i].x += map->centrx;
			map->start_p[j][i].y += map->centry;
			if (map->start_p[j][i].z != 0)
				map->start_p[j][i].z *= map->height;
			iso(map->angle, &map->start_p[j][i].x, &map->start_p[j][i].y,
				map->start_p[j][i].z);
			i++;
		}
		i = 0;
		j++;
	}

}

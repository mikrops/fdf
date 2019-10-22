/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:31:07 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/22 11:26:53 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation(t_map *map, t_point *point)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_y = point->y;
	prev_z = point->z;
	point->y = prev_y * cos(map->rotation_x) + prev_z * sin(map->rotation_x);
	point->z = prev_y * -sin(map->rotation_x) + prev_z * cos(map->rotation_x);
	prev_x = point->x;
	prev_z = point->z;
	point->x = prev_x * cos(map->rotation_y) + prev_z * sin(map->rotation_y);
	point->z = -prev_x * sin(map->rotation_y) + prev_z * cos(map->rotation_y);
	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(map->rotation_z) - prev_y * sin(map->rotation_z);
	point->y = prev_x * sin(map->rotation_z) + prev_y * cos(map->rotation_z);
}

void	iso(double angle, t_point *point)
{
	double	previous_x;
	double	previous_y;

	previous_x = point->x;
	previous_y = point->y;
	if (angle != 0.0)
	{
		point->x = (previous_x - previous_y) * cos(angle);
		point->y = -point->z + (previous_x + previous_y) * sin(angle);
	}
}

void	scale(t_map *map, t_point *point, int i, int j)
{
	map->other[j][i].x = map->scale * i - map->col * map->scale / 2;
	map->other[j][i].y = map->scale * j - map->row * map->scale / 2;
	if (point->z > map->plato)
		point->z = (point->z + map->height) * map->scale;
	else if (point->z < map->plato)
		point->z = (point->z - map->height) * map->scale;
}

void	calculation(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->row)
	{
		while (i < map->col)
		{
			map->other[j][i] = map->start[j][i];
			scale(map, &map->other[j][i], i , j);
			rotation(map, &map->other[j][i]);
			iso(map->angle, &map->other[j][i]);
			map->other[j][i].x += map->centr_x;
			map->other[j][i].y += map->centr_y;
			i++;
		}
		i = 0;
		j++;
	}
}

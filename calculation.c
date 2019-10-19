/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:31:07 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/19 20:30:04 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void rotation_x(double angle, double *x, double *y, double *z)
{
	double	previous_x;
	double	previous_y;
	double	previous_z;

	previous_x = *x;
	previous_y = *y;
	previous_z = *z;
	if (angle != 0.0)
	{
//		*y = previous_y * cos(angle) + previous_z * sin(angle);
//		*x = -previous_y * sin(angle) + previous_z * cos(angle);
		*y = previous_y * cos(angle) + previous_z * sin(angle);
		*z = previous_y * -sin(angle) + previous_z * cos(angle);
	}
}
void rotation_y(double angle, double *x, double *y, double *z)
{
	double	previous_x;
	double	previous_y;
	double	previous_z;

	previous_x = *x;
	previous_y = *y;
	previous_z = *z;
	//if (angle != 0.0)
	{
//		*x = previous_x * cos(angle) + previous_z * sin(angle);
//		*z = -previous_x * sin(angle) + previous_z * cos(angle);
		*x = previous_x * cos(angle) + previous_z * sin(angle);
		*z = -previous_x * sin(angle) + previous_z * cos(angle);
	}
}
void rotation_z(double angle, double *x, double *y, double *z)
{
	double	previous_x;
	double	previous_y;
	double	previous_z;

	previous_x = *x;
	previous_y = *y;
	previous_z = *z;
	//if (angle != 0.0)
	{
//		*x = previous_x * cos(angle) - previous_y * sin(angle);
//		*y = previous_x * sin(angle) + previous_y * sin(angle);
		*x = previous_x * cos(angle) - previous_y * sin(angle);
		*y = previous_x * sin(angle) + previous_y * cos(angle);
	}
}

void	iso(double angle, double *x, double *y, double z)
{
	double	previous_x;
	double	previous_y;
	double 	radian;

	previous_x = *x;
	previous_y = *y;
	radian = ft_degtorad(angle);
	if (angle != 0.0)
	{
		*x = (previous_x - previous_y) * cos(angle);
		*y = -z + (previous_x + previous_y) * sin(angle);
	}
}

void	copy_map_point(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(j < map->row)
	{
		while (i < map->col)
		{
			map->other_p[j][i].x = map->start_p[j][i].x;
			map->other_p[j][i].y = map->start_p[j][i].y;
			map->other_p[j][i].z = map->start_p[j][i].z;
			i++;
		}
		i = 0;
		j++;
	}
}

void	calculation(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	copy_map_point(map);
	while (j < map->row)
	{
		while (i < map->col)
		{
			if (map->other_p[j][i].z != 0)
				map->other_p[j][i].z = map->start_p[j][i].z + map->height;
			map->other_p[j][i].x *= map->scale;
			map->other_p[j][i].y *= map->scale;
			map->other_p[j][i].z *= map->scale;
			rotation_x(map->rotationx, &map->other_p[j][i].x, &map->other_p[j][i].y,
					   &map->other_p[j][i].z);
			rotation_y(map->rotationy, &map->other_p[j][i].x, &map->other_p[j][i].y,
					   &map->other_p[j][i].z);
			rotation_z(map->rotationz, &map->other_p[j][i].x, &map->other_p[j][i].y,
					   &map->other_p[j][i].z);
			iso(map->angle, &map->other_p[j][i].x, &map->other_p[j][i].y,
				map->other_p[j][i].z);
			map->other_p[j][i].x += map->centrx;
			map->other_p[j][i].y += map->centry;
			i++;
		}
		i = 0;
		j++;
	}
}


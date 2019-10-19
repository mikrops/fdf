/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:27:41 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/19 14:31:18 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_map *map, double scale)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->row)
	{
		while (i < map->col)
		{
			if (scale > 0)
			{
				map->other_p[j][i].x *= scale;
				map->other_p[j][i].y *= scale;
				map->other_p[j][i].z *= scale;
			}
			i++;
		}
		i = 0;
		j++;
	}
}
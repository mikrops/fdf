/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:10:27 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/20 07:00:44 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_map *map)
{
	map->centr_x = (WIDTH - map->col) / 2;				//shift сдвиги
	map->centr_y = (HEIGHT - map->row) / 2;				//shift сдвиги
	map->scale = 20;									//масштаб
	map->height = 0;									//высоты
	map->rotation_x = ft_degtorad(0);			//угол x
	map->rotation_y = ft_degtorad(0);			//угол y
	map->rotation_z = ft_degtorad(0);			//угол z
	map->angle = ft_degtorad(0);				//угол iso
//	printf("\n----init - centr%f - %f\n-----", map->centr_x, map->centr_y);
}

void	initialization(t_fdf *fdf, char *name)
{
	fdf->mlx.ptr = mlx_init();
	fdf->win.width = WIDTH;
	fdf->win.height = HEIGHT;
	fdf->win.title = "21.fdf.mmonahan";
	fdf->win.name = name;
	fdf->win.ptr = mlx_new_window(fdf->mlx.ptr, fdf->win.width, fdf->win.height, fdf->win.title);
	init_map(&fdf->map);
}
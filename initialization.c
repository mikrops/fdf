/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:10:27 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/19 20:40:18 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_map *map)
{
	map->centrx = (HEIGHT - map->row) / 2 + 80;			//shift сдвиги
	map->centry = (WIDTH - map->col) / 2 - 200;			//shift сдвиги
	map->scale = 20;									//масштаб
	map->height = 0;									//высоты
	map->rotationx = ft_degtorad(0);				//угол x
	map->rotationy = ft_degtorad(0);				//угол y
	map->rotationz = ft_degtorad(0);				//угол z
	map->angle = ft_degtorad(0);					//угол iso
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
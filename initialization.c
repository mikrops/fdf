/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:10:27 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/19 11:30:39 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void init_map(t_map *map)
{
	map->centrx = (HEIGHT - map->row) / 2 + 80;			//shift сдвиги
	map->centry = (WIDTH - map->col) / 2 - 200;			//shift сдвиги
	map->scale = 20;										//масштаб
	map->height = 0;										//высоты
	map->angle = ft_degtorad(0);					//угол
}

void	initialization(t_fdf *fdf, char *title)
{
	fdf->mlx.ptr = mlx_init();
	fdf->win.width = WIDTH;
	fdf->win.height = HEIGHT;
	fdf->win.title = /*"21.fdf.mmonahan - " */title;
	fdf->win.ptr = mlx_new_window(fdf->mlx.ptr, fdf->win.width, fdf->win.height, fdf->win.title);
	init_map(&fdf->map);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:10:27 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/24 16:20:56 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_map *map)
{
	map->plato = 0;
	map->flag_color = 0;
	map->loger = -1;
	map->col = 0;
	map->row = 0;
	map->centr_x = WIDTH / 1.9;
	map->centr_y = HEIGHT / 1.83;
	map->scale = 1;
	map->height = 0;
	map->rotation_x = ft_degtorad(0);
	map->rotation_y = ft_degtorad(0);
	map->rotation_z = ft_degtorad(0);
	map->iso = ft_degtorad(0);
	map->str_map = ft_memalloc(1);
}

void	initialization(t_fdf *fdf, char *name)
{
	fdf->mlx.ptr = mlx_init();
	fdf->win.width = WIDTH;
	fdf->win.height = HEIGHT;
	fdf->win.title = "21.fdf.mmonahan";
	fdf->win.name = name;
	fdf->win.ptr = mlx_new_window(fdf->mlx.ptr, fdf->win.width, fdf->win.height,
		fdf->win.title);
	fdf->win.themes = 0;
	init_map(&fdf->map);
}

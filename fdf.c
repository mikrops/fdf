/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:07:14 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/19 11:30:39 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_map_project_fd(t_point **map, int row, int col, int fd);

void	copy_map_point(t_map *map, int x, int y, int z)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(j < map->row)
	{
		while (i < map->col)
		{
			if (x)
				map->other_p[j][i].x = map->start_p[j][i].x;
			if (y)
				map->other_p[j][i].y = map->start_p[j][i].y;
			if (z)
				map->other_p[j][i].z = map->start_p[j][i].z;
			i++;
		}
		i = 0;
		j++;
	}
}

static int deal_key(int key, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	mlx_clear_window(fdf->mlx.ptr, fdf->win.ptr);
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_DELETE) //сетка изометрия 0
	{
		copy_map_point(&fdf->map, 1, 1, 1);
//		altitude(&fdf->map, fdf->map.height);
//		scale(&fdf->map, fdf->map.scale);
//		move(&fdf->map, fdf->map.centrx, fdf->map.centry);
		fdf->map.angle = ft_degtorad(0);
	}
	else if (key == KEY_LEFT)
		fdf->map.centrx += -10.0;
	else if (key == KEY_RIGHT)
		fdf->map.centrx += 10.0;
	else if (key == KEY_DOWN)
		fdf->map.centry += 10.0;
	else if (key == KEY_UP)
		fdf->map.centry += -10.0;
	else if (key == KEY_EQUALS)
	{
		fdf->map.height += 1;
	}
	else if (key == KEY_MINUS)
	{
		fdf->map.height -= 1;
	}
	else if (key == KEY_HOME) // изометрия 30
	{
		fdf->map.angle = ft_degtorad(30);
	}
	copy_map_point(&fdf->map, 1, 1, 0);
	altitude(&fdf->map, fdf->map.height);
	scale(&fdf->map, fdf->map.scale);
	project(&fdf->map, fdf->map.angle);
	move(&fdf->map, fdf->map.centrx, fdf->map.centry);

	draw_grid(fdf);

	printf("----key--%d-----result--------\n", key);
	ft_put_map_project_fd(fdf->map.other_p, fdf->map.row, fdf->map.col, 1);
	return (0);
}

static int mouse_click(int key, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	mlx_clear_window(fdf->mlx.ptr, fdf->win.ptr);
	if (key == MUSE_SCROLL_BACK)
		scale(&fdf->map, 1.1);
	else if (key == MUSE_SCROLL_FORARD)
		scale(&fdf->map, 0.9);
	draw_grid(fdf);

	printf("----mouse_click--%d--y%d-x%d--result--------\n", key, x, y);
	ft_put_map_project_fd(fdf->map.other_p, fdf->map.row, fdf->map.col, 1);
	return (0);
}

static int mouse_move(int key, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (key || x || y)
		;
//	printf("----mouse_move--%d--y%d-x%d--result--------\n", key, x, y);
	return (0);
}

/*
 *
 * изменять только переменные!!!
 *
 * и одна функцию котоая рисует
 * и одна функция которая откатывает в оригинал
 *
 *
 * */








void fdf(t_fdf *fdf)
{
	copy_map_point(&fdf->map, 1, 1, 1);

	//рисуем 2D сетку
	altitude(&fdf->map, fdf->map.height);
	scale(&fdf->map, fdf->map.scale);
	move(&fdf->map, fdf->map.centrx, fdf->map.centry);
	project(&fdf->map, ft_degtorad(0));
	draw_grid(fdf);

	// информация
	mlx_string_put(fdf->mlx.ptr, fdf->win.ptr, 50, 50, 1934675, "hello");

	printf("-----------result--------\n");
	ft_put_map_project_fd(fdf->map.other_p, fdf->map.row, fdf->map.col, 1);

	//клава
	mlx_hook(fdf->win.ptr, 2, 0, deal_key, fdf);
	//мышь нажатия /4 - нажал /5 - отпустил
	mlx_hook(fdf->win.ptr, 4, 0, mouse_click, fdf);
	//мышь движение
	mlx_hook(fdf->win.ptr, 6, 0, mouse_move, fdf);

	mlx_loop(fdf->mlx.ptr);
}

void	ft_put_map_project_fd(t_point **map, int row, int col, int fd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < row)
	{
		while (i < col)
		{
			dprintf(fd, "[%.f,%.f,%.f,%d]\t", map[j][i].x, map[j][i].y, map[j][i].z, map[j][i].color);
//			ft_putnbr_fd(map[j][i].z, fd);
//			ft_putchar_fd('\t', fd);
			i++;
		}
		dprintf(fd, "\n");
//		ft_putstr_fd("\n", fd);
		i = 0;
		j++;
	}
}
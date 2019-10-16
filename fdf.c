/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:07:14 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/16 21:02:54 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_map_project_fd(t_point **map, int row, int col, int fd);

static int deal_key(int key, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (key == 53)
	{
		printf("exit = %d\n", key);
		//mlx_clear_window(mlx_ptr, win_ptr);
		exit(0);
	}
	if (key == 117)
		mlx_clear_window(mlx->ptr, mlx->win.ptr);
	printf("key = %d\n", key);
	//mix_pixet_put(mlx_ptr, win_ptr, );
	return (0);
}

static int mouse_click(int key, void *param)
{
	param = 0;
	if (key)
		;
	//printf("mouse_click = %d", key);
	//mix_pixet_put(mlx_ptr, win_ptr, );
	return (0);
}

static int mouse_move(int key, void *param)
{
	t_mlx *mlx;

	mlx = param;
	param = 0;
	if (key)
		;
//	printf("mouse move = %d\n", key);
	//mix_pixet_put(mlx_ptr, win_ptr, );
	return (0);
}

void fdf(t_mlx *mlx, t_line *line, t_map *map)
{
	mlx->ptr = mlx_init();
	mlx->win.width = WIDTH;
	mlx->win.height = HEIGHT;
	mlx->win.title = "21.fdf.mmonahan - [map]";
	mlx->win.ptr = mlx_new_window(mlx->ptr, mlx->win.width, mlx->win.height, mlx->win.title);

	//map
	map->centrx = (HEIGHT - map->row) / 2 + 80;	//shift сдвиги
	map->centry =  (WIDTH - map->col) / 2 - 200;	//shift сдвиги
	map->scale = 20;						//масштаб
	map->height = 2.3;						//высоты
	map->angle = ISO - 0.210;					//угол

	//рисуем 2D сетку
	project(map);
	draw_grid(mlx, line, map);

	printf("-----------result--------\n");
	ft_put_map_project_fd(map->start_p, map->row, map->col, 1);

	//клава
	mlx_hook(mlx->win.ptr, 2, 0, deal_key, mlx);

	//мышь нажатия /4 - нажал /5 - отпустил
	mlx_hook(mlx->win.ptr, 4, 0, mouse_click, 0);

	//мышь движение
	mlx_hook(mlx->win.ptr, 6, 0, mouse_move, 0);

	mlx_loop(mlx->ptr);
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
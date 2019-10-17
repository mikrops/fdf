/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:07:14 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/17 21:04:22 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_map_project_fd(t_point **map, int row, int col, int fd);

static void standart(t_fdf *param)
{
	mlx_clear_window(param->mlx.ptr, param->win.ptr);
	param->map.centrx = 0;
	param->map.centry = 0;
	param->map.scale = 1;
	param->map.height = 1;
}

static int deal_key(int key, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	standart(fdf);
	if (key == 53)
	{
		printf("exit = %d\n", key);
		exit(0);
	}
	if (key == KEY_LEFT)
		fdf->map.centrx = -10;
	else if (key == KEY_RIGHT)
		fdf->map.centrx = 10;
	else if (key == KEY_DOWN)
		fdf->map.centry = 10;
	else if (key == KEY_UP)
		fdf->map.centry = -10;
	else if (key == KEY_EQUALS)
		fdf->map.scale = 1.1;
	else if (key == KEY_MINUS)
		fdf->map.scale = 0.9;

	project(&fdf->map);
	draw_grid(fdf);
	printf("----key--%d-----result--------\n", key);
	ft_put_map_project_fd(fdf->map.other_p, fdf->map.row, fdf->map.col, 1);
	return (0);
}

static int mouse_click(int key, void *param)
{
	t_fdf	*fdf;

	fdf = param;
//	standart(fdf);
	if (key == MUSE_SCROLL_FORARD)
		;//fdf->map.height = 1.1;
	else if (key == MUSE_SCROLL_BACK)
		;//fdf->map.height = 0.9;
//	project(&fdf->map);
//	draw_grid(fdf);
	printf("----mouse-click--%d-----result--------\n", key);
//	ft_put_map_project_fd(fdf->map.other_p, fdf->map.row, fdf->map.col, 1);
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
	return (0);
}

void fdf(t_fdf *fdf)
{
	fdf->mlx.ptr = mlx_init();
	fdf->win.width = WIDTH;
	fdf->win.height = HEIGHT;
	fdf->win.title = "21.fdf.mmonahan - [map]";
	fdf->win.ptr = mlx_new_window(fdf->mlx.ptr, fdf->win.width, fdf->win.height, fdf->win.title);

	//map
	fdf->map.centrx = (HEIGHT - fdf->map.row) / 2 + 80;			//shift сдвиги
	fdf->map.centry = (WIDTH - fdf->map.col) / 2 - 200;			//shift сдвиги
	fdf->map.scale = 20;										//масштаб
	fdf->map.height = 1;//2.3;									//высоты
	fdf->map.angle = ISO;// - 0.210;						//угол

//	if (line->end.x)
//		;
	//рисуем 2D сетку
	project(&fdf->map);
//	draw_grid(fdf, line);
	draw_grid(fdf);

	printf("-----------result--------\n");
	ft_put_map_project_fd(fdf->map.other_p, fdf->map.row, fdf->map.col, 1);

	//клава
	mlx_hook(fdf->win.ptr, 2, 0, deal_key, fdf);//mlx);

	//мышь нажатия /4 - нажал /5 - отпустил
	mlx_hook(fdf->win.ptr, 4, 0, mouse_click, fdf);

	//мышь движение
	mlx_hook(fdf->win.ptr, 6, 0, mouse_move, 0);

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
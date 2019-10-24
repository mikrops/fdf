/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:59:14 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/24 14:46:27 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_map_project_fd(t_point **map, int row, int col, int fd);

void	start_poisition(t_map *map)
{
	int		win;
	double	fig;

	win = WIDTH < HEIGHT ? WIDTH : HEIGHT;
	fig = map->col > map->row ? map->col : map->row;
	map->scale  = win / fig / 2;
}

static int deal_key(int key, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	mlx_clear_window(fdf->mlx.ptr, fdf->win.ptr);
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_C)
		fdf->win.themes += 1;
	else if (key == KEY_DELETE)
	{
		start_poisition(&fdf->map);
		fdf->map.height = 0;
		fdf->win.themes = 0;
		fdf->map.rotation_x = ft_degtorad(0);
		fdf->map.rotation_y = ft_degtorad(0);
		fdf->map.rotation_z = ft_degtorad(0);
		fdf->map.iso = ft_degtorad(0);
	}
	else if (key == KEY_ENTER)
	{
		fdf->map.centr_x = WIDTH / 1.9;
		fdf->map.centr_y = HEIGHT / 1.83;
	}
	else if (key == KEY_LEFT)
		fdf->map.centr_x += -10.0;
	else if (key == KEY_RIGHT)
		fdf->map.centr_x += 10.0;
	else if (key == KEY_DOWN)
		fdf->map.centr_y += 10.0;
	else if (key == KEY_UP)
		fdf->map.centr_y += -10.0;
	else if (key == KEY_EQUALS)
	{
		if (fdf->map.height < MAX_HEIGTN)
			fdf->map.height += STEP_HEIGTN;
	}
	else if (key == KEY_MINUS)
	{
		if (fdf->map.height > MIN_HEIGTN)
			fdf->map.height -= STEP_HEIGTN;
	}
	// ПОВИКСИТЬ с ПЕРЕМЕННОЙ УГЛАААА!!! ГДЕ ТО СБРАСЫВАЕТСЯ
	// В ИНФО БУДЕТ ВИДНО)
	else if (key == KEY_PAGE_UP) // поворот x
		fdf->map.rotation_x += ft_degtorad(5);
	else if (key == KEY_HOME) // поворот x
		fdf->map.rotation_x -= ft_degtorad(5);
	else if (key == KEY_BACK_SPASE ) // поворот y
		fdf->map.rotation_y += ft_degtorad(5);
	else if (key == KEY_SPASE) // поворот y
		fdf->map.rotation_y -= ft_degtorad(5);
	else if (key == KEY_PAGE_DOWN) // поворот z
		fdf->map.rotation_z += ft_degtorad(5);
	else if (key == KEY_END) // поворот z
		fdf->map.rotation_z -= ft_degtorad(5);
	else if (key == KEY_ONE) // изометрия 0
		fdf->map.iso = ft_degtorad(0);
	else if (key == KEY_TWO) // изометрия 30
		fdf->map.iso = ft_degtorad(30);
	else if (key == KEY_Y) // изометрия -1
		fdf->map.iso -= ft_degtorad(1);
	else if (key == KEY_T) // изометрия +1
		fdf->map.iso += ft_degtorad(1);
	else
	{
		info(fdf, 0);
		return (0);
	}
	calculation(&fdf->map);

	draw_grid(fdf);

	printf("----key--%d-----result--------\n", key);
	info(fdf, 1);
	return (0);
}

static int mouse_click(int key, int m_x, int m_y, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	fdf->win.mouse_x = m_x;
	fdf->win.mouse_y = m_y;
	mlx_clear_window(fdf->mlx.ptr, fdf->win.ptr);
	if (key == MOUSE_SCROLL_BACKWARD)
	{
		if (fdf->map.scale < MAX_SCALE)
			fdf->map.scale += STEP_SCALE;
	}
	else if (key == MOUSE_SCROLL_FORWARD)
	{
		if (fdf->map.scale > MIN_SCALE)
			fdf->map.scale -= STEP_SCALE;
	}
	else
	{
		info(fdf, 0);
		return (0);
	}
	calculation(&fdf->map);

	draw_grid(fdf);

	printf("----mouse_click--%d--x%d-y%d--result--------\n", key, m_x, m_y);
	info(fdf, 1);

	return (0);
}

//static int mouse_move(int key, int x, int y, void *param)
//{
//	t_fdf	*fdf;
//
//	fdf = param;
////	fdf->map.x = x;
////	fdf->map.y = y;
////	info(fdf);
//	if (key || x || y)
//		;
//	printf("----mouse_move-x%d--y%d-key%d--result--------\n", key, x, y);
//	return (0);
//}

void fdf(t_fdf *fdf)
{
	start_poisition(&fdf->map);
	calculation(&fdf->map);
	info(fdf, 0);

	printf("-----------fdf--------\n");
	ft_put_map_project_fd(fdf->map.other, fdf->map.row, fdf->map.col, 1);

	//клава
	mlx_hook(fdf->win.ptr, 2, 0, deal_key, fdf);
	//мышь нажатия /4 - нажал /5 - отпустил
	mlx_hook(fdf->win.ptr, 4, 0, mouse_click, fdf);
	//мышь движение
	//mlx_hook(fdf->win.ptr, 6, 0, mouse_move, fdf);

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
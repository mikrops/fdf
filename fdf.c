/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:07:14 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/19 21:04:04 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_map_project_fd(t_point **map, int row, int col, int fd);

static int deal_key(int key, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	mlx_clear_window(fdf->mlx.ptr, fdf->win.ptr);
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_DELETE) //сетка изометрия 0
	{
		fdf->map.height = 0;
		fdf->map.scale = 20;
		fdf->map.rotationx = ft_degtorad(0);
		fdf->map.rotationy = ft_degtorad(0);
		fdf->map.rotationz = ft_degtorad(0);
		fdf->map.angle = ft_degtorad(0);
	}
	else if (key == KEY_ENTER) // центрирование
		;
	else if (key == KEY_LEFT)
		fdf->map.centrx += -10.0;
	else if (key == KEY_RIGHT)
		fdf->map.centrx += 10.0;
	else if (key == KEY_DOWN)
		fdf->map.centry += 10.0;
	else if (key == KEY_UP)
		fdf->map.centry += -10.0;
	else if (key == KEY_EQUALS)
		fdf->map.height += 0.1;
	else if (key == KEY_MINUS)
		fdf->map.height -= 0.1;
	else if (key == KEY_END) // поворот x
		fdf->map.rotationx += ft_degtorad(5);
	else if (key == KEY_HOME) // поворот x
		fdf->map.rotationx -= ft_degtorad(5);
	else if (key == KEY_BACK_SPASE ) // поворот y
		fdf->map.rotationy += ft_degtorad(5);
	else if (key == KEY_SPASE) // поворот y
		fdf->map.rotationy -= ft_degtorad(5);
	else if (key == KEY_PAGE_DOWN) // поворот z
		fdf->map.rotationz += ft_degtorad(5);
	else if (key == KEY_PAGE_UP) // поворот z
		fdf->map.rotationz -= ft_degtorad(5);
	else if (key == KEY_ONE) // изометрия 0
		fdf->map.angle = ft_degtorad(0);
	else if (key == KEY_TWO) // изометрия 30
		fdf->map.angle = ft_degtorad(30);
	else if (key == KEY_Y) // изометрия -1
		fdf->map.angle -= ft_degtorad(1);
	else if (key == KEY_T) // изометрия +1
		fdf->map.angle += ft_degtorad(1);
	else
	{
		info(fdf, 0);
		//return (0);
	}
	calculation(&fdf->map);
	info(fdf, 1);
	draw_grid(fdf);

	printf("----key--%d-----result--------\n", key);
	ft_put_map_project_fd(fdf->map.other_p, fdf->map.row, fdf->map.col, 1);
	return (0);
}

static int mouse_click(int key, int m_x, int m_y, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	fdf->win.mouse_x = m_x;
	fdf->win.mouse_y = m_y;
	mlx_clear_window(fdf->mlx.ptr, fdf->win.ptr);
	if (key == MUSE_SCROLL_BACK)
		fdf->map.scale += 1;
	else if (key == MUSE_SCROLL_FORARD)
	{
		if (fdf->map.scale)
			fdf->map.scale -= 1;
	}
	else
	{
		info(fdf, 0);
		return (0);
	}
	calculation(&fdf->map);
	info(fdf, 1);
	draw_grid(fdf);

	printf("----mouse_click--%d--x%d-y%d--result--------\n", key, m_x, m_y);
	ft_put_map_project_fd(fdf->map.other_p, fdf->map.row, fdf->map.col, 1);
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
	calculation(&fdf->map);
	info(fdf, 0);
	//draw_grid(fdf);

	printf("-----------result--------\n");
	ft_put_map_project_fd(fdf->map.other_p, fdf->map.row, fdf->map.col, 1);

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
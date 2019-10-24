/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_deal_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:43:11 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/24 20:56:59 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_start(t_fdf *fdf)
{
	int		win;
	double	fig;

	win = WIDTH < HEIGHT ? WIDTH : HEIGHT;
	fig = fdf->map.col > fdf->map.row ? fdf->map.col : fdf->map.row;
	fdf->map.scale = win / fig / 2;
	fdf->map.height = 0;
	fdf->win.themes = 0;
	fdf->map.rotation_x = ft_degtorad(0);
	fdf->map.rotation_y = ft_degtorad(0);
	fdf->map.rotation_z = ft_degtorad(0);
	fdf->map.iso = ft_degtorad(0);
}

void	deal_angle(int key, t_fdf *fdf)
{
	if (key == KEY_PAGE_UP)
		fdf->map.rotation_x += ft_degtorad(5);
	else if (key == KEY_HOME)
		fdf->map.rotation_x -= ft_degtorad(5);
	else if (key == KEY_BACK_SPASE)
		fdf->map.rotation_y += ft_degtorad(5);
	else if (key == KEY_SPASE)
		fdf->map.rotation_y -= ft_degtorad(5);
	else if (key == KEY_PAGE_DOWN)
		fdf->map.rotation_z += ft_degtorad(5);
	else if (key == KEY_END)
		fdf->map.rotation_z -= ft_degtorad(5);
	else if (key == KEY_ONE)
		fdf->map.iso = ft_degtorad(0);
	else if (key == KEY_TWO)
		fdf->map.iso = ft_degtorad(30);
	else if (key == KEY_T)
		fdf->map.iso -= ft_degtorad(1);
	else if (key == KEY_Y)
		fdf->map.iso += ft_degtorad(1);
}

void	deal_move(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_C)
		fdf->win.themes += 1;
	else if (key == KEY_L)
		fdf->map.loger *= -1;
	else if (key == KEY_LEFT)
		fdf->map.centr_x += -10.0;
	else if (key == KEY_RIGHT)
		fdf->map.centr_x += 10.0;
	else if (key == KEY_DOWN)
		fdf->map.centr_y += 10.0;
	else if (key == KEY_UP)
		fdf->map.centr_y += -10.0;
	else if (key == KEY_EQUALS)
		fdf->map.height += fdf->map.height < MAX_HEIGTN ? STEP_HEIGTN : 0;
	else if (key == KEY_MINUS)
		fdf->map.height -= fdf->map.height > MIN_HEIGTN ? STEP_HEIGTN : 0;
	else if (key == KEY_ENTER)
	{
		fdf->map.centr_x = WIDTH / 1.9;
		fdf->map.centr_y = HEIGHT / 1.83;
	}
}

int		hook_deal_key(int key, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	mlx_clear_window(fdf->mlx.ptr, fdf->win.ptr);
	if (key == KEY_DELETE)
		deal_start(fdf);
	else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN ||
			key == KEY_UP || key == KEY_EQUALS || key == KEY_MINUS ||
			key == KEY_ENTER || key == KEY_C || key == KEY_ESC || key == KEY_L)
		deal_move(key, fdf);
	else if (key == KEY_PAGE_UP || key == KEY_HOME || key == KEY_BACK_SPASE ||
			key == KEY_SPASE || key == KEY_PAGE_DOWN || key == KEY_END ||
			key == KEY_ONE || key == KEY_TWO || key == KEY_T || key == KEY_Y)
		deal_angle(key, fdf);
	else
	{
		info(fdf, INFO_START);
		return (0);
	}
	calculation(&fdf->map);
	draw_grid(fdf);
	if (fdf->map.loger > 0)
		ft_putstr("-----------key-----------\n");
	info(fdf, INFO_GAME);
	return (0);
}

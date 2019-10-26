/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:59:14 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/26 14:58:47 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	start_poisition(t_fdf *fdf)
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

static int	mouse_click(int key, int m_x, int m_y, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	fdf->win.mouse_x = m_x;
	fdf->win.mouse_y = m_y;
	mlx_clear_window(fdf->mlx.ptr, fdf->win.ptr);
	if (key == MOUSE_SCROLL_BACKWARD)
		fdf->map.scale += fdf->map.scale < MAX_SCL ? STEP_SCL : 0;
	else if (key == MOUSE_SCROLL_FORWARD)
		fdf->map.scale -= fdf->map.scale > MIN_SCL ? STEP_SCL : 0;
	else
	{
		info(fdf, INFO_START);
		return (0);
	}
	calculation(&fdf->map);
	draw_grid(fdf);
	if (fdf->map.loger > 0)
		ft_putstr("-----------mouse_click-----------\n");
	info(fdf, INFO_GAME);
	return (0);
}

void		fdf(t_fdf *fdf)
{
	fdf->mlx.ptr = mlx_init();
	fdf->win.ptr = mlx_new_window(fdf->mlx.ptr, fdf->win.width, fdf->win.height,
		fdf->win.title);
	start_poisition(fdf);
	calculation(&fdf->map);
	ft_putstr("-----------fdf-----------\n");
	info(fdf, INFO_START);
	mlx_hook(fdf->win.ptr, EVENT_KEY_DOWN, 0, hook_deal_key, fdf);
	mlx_hook(fdf->win.ptr, EVENT_MOUSE_CLICK, 0, mouse_click, fdf);
	mlx_loop(fdf->mlx.ptr);
}

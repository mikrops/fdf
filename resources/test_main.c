/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:04:43 by dheidenr          #+#    #+#             */
/*   Updated: 2019/10/05 16:04:45 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, void *param)
{
	t_fractal		*f;
	t_mlx			*mlx;

	f = (t_fractal *)param;
	mlx = &f->mlx;
	f->mouse.x = x;
	f->mouse.y = y;
	if (f->type == e_julia)
	{
		multithread(f);
		mlx_put_image_to_window(mlx->ptr, mlx->win.ptr, mlx->img.ptr, 0, 0);
		stats(f);
	}
	return (1);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_fractal		*f;

	f = (t_fractal *)param;
	f->mouse.x = x;
	f->mouse.y = y;
	if (button == 1 || button == 2)
	{
		f->scale = (button == 1) ? f->scale * 1.2 : f->scale / 1.2;
		redraw(f, f->type);
	}
	if (button == 4 || button == 5)
	{
		f->scale = (button == 5) ? f->scale * 1.2 : f->scale / 1.2;
		redraw(f, f->type);
	}
	stats(f);
	return (1);
}

int		deal_key(int key, void *param)
{
	t_fractal		*f;
	t_mlx			*mlx;

	f = (t_fractal *)param;
	mlx = &f->mlx;
	reload(key, f);
	arrow_redraw(key, f);
	digit_redraw(key, f);
	rgb_redraw(key, f);
	iteration_redraw(key, f);
	stats(f);
	if (key == 40)
		mlx_clear_window(mlx->ptr, mlx->win.ptr);
	if (key == 53)
	{
		mlx_destroy_window(mlx->ptr, mlx->win.ptr);
		exit(0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_fractal		f;

	if (ac != 2)
		help();
	else
		init_arguments(ac, av, &f);
	init_fractal(&f);
	init_mlx(&f.mlx);
	redraw(&f, f.type);
	mlx_hook(f.mlx.win.ptr, 2, 0, deal_key, &f);
	mlx_hook(f.mlx.win.ptr, 4, 0, mouse_press, &f);
	mlx_hook(f.mlx.win.ptr, 6, 0, mouse_move, &f);
	mlx_loop(f.mlx.ptr);
	return (0);
}

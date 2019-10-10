/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:12:41 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/10 17:24:18 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define GORIZONT 1000
# define VERTICAL 1000

int deal_key(int key, void *param)
{
	param = 0;
	if (key == 53)
	{
		printf("exit = %d\n", key);
		//mlx_clear_window(mlx_ptr, win_ptr);
		exit(0);
	}
	printf("key = %d\n", key);
	//mix_pixet_put(mlx_ptr, win_ptr, );
	return (0);
}

int mouse_click(int key, void *param)
{
	param = 0;
	printf("mouse_click = %d\n", key);
	//mix_pixet_put(mlx_ptr, win_ptr, );
	return (0);
}

int mouse_move(int key, void *param)
{
	param = 0;
	printf("mouse move = %d\n", key);
	//mix_pixet_put(mlx_ptr, win_ptr, );
	return (0);
}

int main()
{
	t_mlx	mlx;
	t_line	line;

	printf("Hello, fdf!\n");

	mlx.ptr = mlx_init();
	mlx.win.ptr = mlx_new_window(mlx.ptr, GORIZONT, VERTICAL, "mlx 21");

	//рисуем пиксель
	//mlx_pixel_put(mlx_ptr, win_ptr, GORIZONT/2, VERTICAL/2, 0xFFFFFF);

	//рисуем линию
	line.start.x = 100; line.start.y = 100;
	line.end.x = 100; line.end.y = 170;
	put_line(&mlx, &line);
	line.end.x = 200; line.end.y = 170;
	put_line(&mlx, &line);
    line.end.x = 100; line.end.y = 30;
    put_line(&mlx, &line);
    line.end.x = 200; line.end.y = 30;
    put_line(&mlx, &line);

	//клава
	mlx_hook(mlx.win.ptr, 2, 0, deal_key, 0);

	//мышь нажатия /4 - нажал /5 - отпустил
//	mlx_hook(win_ptr, 4, 0, mouse_click, 0);

	//мышь движение
//	mlx_hook(win_ptr, 6, 0, mouse_move, 0);

	mlx_loop(mlx.ptr);
    return 0;
}
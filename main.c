/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:12:41 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/08 14:32:39 by mmonahan         ###   ########.fr       */
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
	void	*mlx_ptr;
	void	*win_ptr;
    printf("Hello, fdf!\n");

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, GORIZONT, VERTICAL, "mlx 21");

    //рисуем пиксель
    mlx_pixel_put(mlx_ptr, win_ptr, GORIZONT/2, VERTICAL/2, 0xFFFFFF);

    //клава
	//mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_hook(win_ptr, 2, 0, deal_key, 0);

	//мышь нажатия /4 - нажал /5 - отпустил
	mlx_hook(win_ptr, 4, 0, mouse_click, 0);

	//мышь движение
	mlx_hook(win_ptr, 6, 0, mouse_move, 0);

    mlx_loop(mlx_ptr);
    return 0;
}
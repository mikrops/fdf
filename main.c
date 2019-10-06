/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:12:41 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/06 19:21:52 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minilibx_macos/mlx.h"

# define GORIZONT 1000
# define VERTICAL 1000

int dd(int key, void *param)
{
	printf("%d\n", key);
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
    mlx_pixel_put(mlx_ptr, win_ptr, GORIZONT/2, VERTICAL/2, 0xFFFFFF);

	mlx_key_hook(win_ptr, dd, (void *)0);

    mlx_loop(mlx_ptr);
    return 0;
}

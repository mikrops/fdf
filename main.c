/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:12:41 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/05 20:18:02 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minilibx_macos/mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
    printf("Hello, fdf!\n");

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx 21");
    mlx_pixel_put(mlx_ptr, win_ptr, 1000/2, 1000/2, 0xFFFFFF);
    mlx_loop(mlx_ptr);
    return 0;
}

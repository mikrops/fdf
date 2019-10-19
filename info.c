/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:57:57 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/19 19:48:01 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start(void *mptr, void *wptr)
{
	int		i;
	int		x;
	int		y;
	char	*temp[8];

	i = 7;
	x = WIDTH / 2;
	y = HEIGHT / 2 - i * 25;
	temp[0] = "INSTRUCTION";
	temp[1] = "";
	temp[2] = "Use the keys [UP], [DOWN], [LEFT], [RIGHT] to move the figure";
	temp[3] = "Use the keys [1], [2] to change the projection of the figure";
	temp[4] = "Use the keys [+], [-] to change the height of the figure";
	temp[5] = "Use the mouse scroll [FORWARD] and [BACKWARD] to zoom";
	temp[6] = "Use the keys [T], [Y] to change the isometric shape";
	temp[7] = "Use the keys [DELETE] to reset the form";
	while (i >= 0)
	{
		mlx_string_put(mptr, wptr, x - ft_strlen(temp[i]) * 5,
			y + i * 25, 293856, temp[i]);
		i--;
	}
}

//void	game(t_fdf *fdf)
void	game(t_mlx *mlx, t_window *win)
{
	int		color;
	char	*str;

	color = 293856;
	str = "map:";
	mlx_string_put(mlx->ptr, win->ptr, 5, 5, color, str);
	str = win->name;
	mlx_string_put(mlx->ptr, win->ptr, 85, 5, color, str);
//	str = "angle";
//	mlx_string_put(mlx->ptr, win->ptr, 5, 30, color, str);
//	str = ft_itoa(map->angle);
//	mlx_string_put(mlx->ptr, win->ptr, 85, 30, color, str);
}

void	info(t_fdf *fdf, int check)
{
	if (check == 1)
//		game(fdf);
		game(&fdf->mlx, &fdf->win);
	else if (check == 0)
//		start(fdf);
		start(fdf->mlx.ptr, fdf->win.ptr);
}

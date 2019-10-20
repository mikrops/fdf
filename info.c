/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:57:57 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/20 06:05:36 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start(void *mptr, void *wptr)
{
	int		i;
	int		x;
	int		y;
	int 	color;
	char	*temp[8];

	i = 7;
	color = RED;
	x = WIDTH / 2;
	y = HEIGHT / 2 - i * 25;
	temp[0] = "INSTRUCTION";
	temp[1] = "Use";
	temp[2] = "[UP], [DOWN], [LEFT], [RIGHT] to move";
	temp[3] = "[1], [2] to change the projection";
	temp[4] = "[+], [-] to change the height";
	temp[5] = "[FORWARD] and [BACKWARD] to zoom";
	temp[6] = "[T], [Y] to change the isometric";
	temp[7] = "[DELETE], [ENTER] to reset";
	while (i >= 0)
	{
		mlx_string_put(mptr, wptr, x - ft_strlen(temp[i]) * 5,
			y + i * 35, color, temp[i]);
		i--;
		color -= AQUAMARINE;
	}
}

void	game(t_mlx *mlx, t_window *win, t_map map)
{
	int		color;
	char	*str;
	int		x;
	int		y;


	x = 5;
	y = 5;

	str = "map:";
	color = PALE;
	mlx_string_put(mlx->ptr, win->ptr, x, y, color, str);
	str = win->name;
	mlx_string_put(mlx->ptr, win->ptr, x += 85, y, color, str);

	str = "scale:";
	color = PALE;
	mlx_string_put(mlx->ptr, win->ptr, 5, y += 30, color, str);
	str = ft_itoa((int)map.scale);
	color = map.scale > MIN_SCALE && map.scale < MAX_SCALE ? GREEN : RED;
	mlx_string_put(mlx->ptr, win->ptr, 90, y, color, str);

	str = "hight:";
	color = PALE;
	mlx_string_put(mlx->ptr, win->ptr, 5, y += 30, color, str);
	str = ft_itoa((int)map.height);
	color = map.height > MIN_HEIGTN && map.height < MAX_HEIGTN ? GREEN : RED;
	mlx_string_put(mlx->ptr, win->ptr, 90, y, color, str);
}

void	info(t_fdf *fdf, int check)
{
	if (check == 1)
		game(&fdf->mlx, &fdf->win, fdf->map);
	else if (check == 0)
		start(fdf->mlx.ptr, fdf->win.ptr);
}

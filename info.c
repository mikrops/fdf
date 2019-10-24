/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:57:57 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/24 20:56:59 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Инициализирует два статических массива для хранинеия значений
*/

void	arr_game(t_map map, char **game_param, char **game_value)
{
	game_param[0] = "map:";
	game_param[1] = "width";
	game_param[2] = "height";
	game_param[3] = "scale:";
	game_param[4] = "hight:";
	game_param[5] = "iso:";
	game_param[6] = "x-axis:";
	game_param[7] = "y-axis:";
	game_param[8] = "z-axis:";
	game_value[0] = "name";
	game_value[1] = ft_itoa(WIDTH);
	game_value[2] = ft_itoa(HEIGHT);
	game_value[3] = ft_itoa((int)map.scale);
	game_value[4] = ft_itoa((int)map.height);
	game_value[5] = ft_itoa((int)ft_radtodeg(map.iso));
	game_value[6] = ft_itoa((int)ft_radtodeg(map.rotation_x));
	game_value[7] = ft_itoa((int)ft_radtodeg(map.rotation_y));
	game_value[8] = ft_itoa((int)ft_radtodeg(map.rotation_z));
}

/*
**	Освобождает выделенную память после инициализации определенных значений в
**	в массиве
*/

void	arr_regame(char **game_value)
{
	ft_strdel(&game_value[1]);
	ft_strdel(&game_value[2]);
	ft_strdel(&game_value[3]);
	ft_strdel(&game_value[4]);
	ft_strdel(&game_value[5]);
	ft_strdel(&game_value[6]);
	ft_strdel(&game_value[7]);
	ft_strdel(&game_value[8]);
}

/*
**	Выводит инстркуцию на экран
*/

void	start_info(void *mptr, void *wptr)
{
	int		i;
	int		x;
	int		y;
	int		color;
	char	*temp[11];

	i = 11;
	color = RED;
	x = WIDTH / 2;
	y = HEIGHT / 2 - i * 25;
	temp[0] = "INSTRUCTION";
	temp[1] = "Use";
	temp[2] = "[UP], [DOWN], [LEFT], [RIGHT] to move";
	temp[3] = "[1], [2] to change the projection";
	temp[4] = "[+], [-] to change the height";
	temp[5] = "[FORWARD], [BACKWARD] to zoom";
	temp[6] = "[T], [Y] to change the isometric";
	temp[7] = "[BACK SPACE], [SPACE] to Y rotate";
	temp[8] = "[END], [PAGE DOWN] to Z rotate";
	temp[9] = "[HOME], [PAGE UP] to X rotate";
	temp[10] = "[DELETE], [ENTER] to reset";
	while (--i >= 0)
		mlx_string_put(mptr, wptr, x - ft_strlen(temp[i]) * 5,
			y + i * 35, color -= AQUAMARINE, temp[i]);
}

/*
**	Выводит названия и значения переменных на экран
*/

void	game_info(t_mlx *mlx, t_window *win, t_map map)
{
	int		color;
	int		y;
	int		i;
	char	*param[9];
	char	*value[9];

	arr_game(map, param, value);
	i = 0;
	y = 5;
	value[0] = win->name;
	while (i < 9)
	{
		if (i > 0)
			y += 30;
		mlx_string_put(mlx->ptr, win->ptr, 5, y, BISQUE3, param[i]);
		if (i == 3)
			color = map.scale > MIN_SCALE && map.scale < MAX_SCALE ? GREEN : RED;
		else if (i == 4)
			color = map.height > MIN_HEIGTN && map.height < MAX_HEIGTN ? GREEN : RED;
		else
			color = DEEPSKYBLUE3;
		mlx_string_put(mlx->ptr, win->ptr, 90, y, color, value[i]);
		i++;
	}
	arr_regame(value);
}

/*
**	Выводит информацию на экран
*/

void	info(t_fdf *fdf, int check)
{
	if (check == 1)
	{
		game_info(&fdf->mlx, &fdf->win, fdf->map);
		if (fdf->map.loger > 0)
			put_map_point_fd(1, fdf->map.other, fdf->map.row, fdf->map.col);
	}
	else if (check == 0)
		start_info(fdf->mlx.ptr, fdf->win.ptr);
}

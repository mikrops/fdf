/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:57:57 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/23 20:54:25 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	arr_game(t_map map, char **game_param, char **game_value)
{
	game_param[0] = "map:";
	game_param[1] = "scale:";
	game_param[2] = "hight:";
	game_param[3] = "4";
	game_param[4] = "5";

	game_value[0] = "name"; //win->name;
	game_value[1] = ft_itoa((int)map.scale);
	game_value[2] = ft_itoa((int)map.height);
	game_value[3] = "4";
	game_value[4] = "5";
}

void	start(void *mptr, void *wptr)
{
	int		i;
	int		x;
	int		y;
	int 	color;
	char	*temp[11];

	i = 10;
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
	while (i >= 0)
	{
		mlx_string_put(mptr, wptr, x - ft_strlen(temp[i]) * 5,
			y + i * 35, color -= AQUAMARINE, temp[i]);
		i--;
	}
}

void	game(t_mlx *mlx, t_window *win, t_map map)
{
	int		color;
	int		y;

	char	*param[5];
	char	*value[5];
	arr_game(map, param, value);

	y = 5;
/*
 * добваить кнопок типа углы  оюб
 * размеры окна
 * углы поворотов
 * угол изометрии
 *
 * */

	int i = 0;

	while(i < 5)
	{
		color = PALE;
		mlx_string_put(mlx->ptr, win->ptr, 5, y, color, param[i]);
		mlx_string_put(mlx->ptr, win->ptr, 90, y += 30, color, value[i]);
		i++;
	}

//	ft_strdel(&value[1]);
//	ft_strdel(&value[2]);

//	char	*str;

//	str = "map:";
//	color = PALE;
//	mlx_string_put(mlx->ptr, win->ptr, 5, y, color, str);
//	str = win->name;
//	mlx_string_put(mlx->ptr, win->ptr, 90, y, color, str);
//
//	str = "scale:";
//	color = PALE;
//	mlx_string_put(mlx->ptr, win->ptr, 5, y += 30, color, str);
//	str = ft_itoa((int)map.scale);
//	color = map.scale > MIN_SCALE && map.scale < MAX_SCALE ? GREEN : RED;
//	mlx_string_put(mlx->ptr, win->ptr, 90, y, color, str);
//	ft_strdel(&str);
//
//	str = "hight:";
//	color = PALE;
//	mlx_string_put(mlx->ptr, win->ptr, 5, y += 30, color, str);
//	str = ft_itoa((int)map.height);
//	color = map.height > MIN_HEIGTN && map.height < MAX_HEIGTN ? GREEN : RED;
//	mlx_string_put(mlx->ptr, win->ptr, 90, y, color, str);
//	ft_strdel(&str);
}

void	info(t_fdf *fdf, int check)
{
	if (check == 1)
	{
		game(&fdf->mlx, &fdf->win, fdf->map);
		//put_map_point_fd(1, fdf->map.other, fdf->map.row, fdf->map.col);
	}
	else if (check == 0)
		start(fdf->mlx.ptr, fdf->win.ptr);
}

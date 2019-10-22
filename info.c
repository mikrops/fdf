/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:57:57 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/21 17:41:48 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
//		color -= AQUAMARINE;
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

void	print(t_point **map, int row, int col, int fd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < row)
	{
		while (i < col)
		{
			dprintf(fd, "[%.f,%.f,%.f,%d]\t", map[j][i].x, map[j][i].y, map[j][i].z, map[j][i].color);
//			ft_putnbr_fd(map[j][i].z, fd);
//			ft_putchar_fd('\t', fd);
			i++;
		}
		dprintf(fd, "\n");
//		ft_putstr_fd("\n", fd);
		i = 0;
		j++;
	}
}

void	info(t_fdf *fdf, int check)
{
	if (check == 1)
	{
		game(&fdf->mlx, &fdf->win, fdf->map);
		//print(fdf->map.other_p, fdf->map.row, fdf->map.col, 1);
	}
	else if (check == 0)
		start(fdf->mlx.ptr, fdf->win.ptr);

}

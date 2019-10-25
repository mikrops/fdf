/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:06:20 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/25 16:44:32 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Возвращает длину значения числа в шестадцатиричной системе
*/

static int	hexlen(char *hex)
{
	int	length;

	length = 0;
	while (ft_isdigit(hex[length]) || ft_isalpha(hex[length]))
		length++;
	return (length);
}

/*
**	Заполнение элемента массива типа структура point
*/

static int	fill_point(t_point *point, char *str, int row, int col)
{
	int	i;

	i = 0;
	point->x = (col + 1);
	point->y = (row + 1);
	point->z = ft_atoi(&str[i]);
	i += ft_intcount((int)point->z);
	if (str[i] == ',')
	{
		i++;
		point->color = ft_atoi_base(&str[i], 16);
		i += hexlen(&str[i]);
	}
	return (i);
}

/*
**	Заполнение двумерного массива типа структура point
*/

static void	fill_map_point(t_point **point, char *str, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (*str != '\n')
		{
			if (ft_isdigit(*str))
			{
				str += fill_point(&point[j][i], str, j, i);
				i++;
			}
			else
				str++;
		}
		str++;
		i = 0;
		j++;
	}
}

/*
**	Проверяет валидность матрицы точек
*/

static int	check_point(t_map *map)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (j < map->row)
	{
		while (i < map->col)
		{
			if (map->start[j][i].x == 0 || map->start[j][i].y == 0)
				return (1);
			if (map->start[j][i].color)
				map->flag_color = 1;
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

/*
**	Заполняет матрицу точек.
**	Возвращает:	0 в случае валидности матрицы
**				-1 в случае маленькой фигуры
**				-4 в случае путсых точек
*/

int			input_map(t_fdf *fdf)
{
	int	val;

	val = validation(fdf);
	if (val != 0)
		return (val);
	if (fdf->map.col < 2 || fdf->map.row < 1)
		return (ERROR_EMPTY_FILE);
	fdf->map.start = (t_point **)ft_map_void(fdf->map.row, fdf->map.col,
		sizeof(t_point *), sizeof(t_point));
	fdf->map.other = (t_point **)ft_map_void(fdf->map.row, fdf->map.col,
		sizeof(t_point *), sizeof(t_point));
	fill_map_point(fdf->map.start, fdf->map.str_map, fdf->map.row);
	if (check_point(&fdf->map))
		return (ERROR_INCOMPLETE_FILE);
	ft_putstr("-----------start--------\n");
	put_map_point_fd(1, fdf->map.start, fdf->map.row, fdf->map.col);
	return (0);
}

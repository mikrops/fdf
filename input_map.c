/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:06:20 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/22 20:13:44 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static*/ void	ft_put_map_point_fd(t_point **map, int row, int col, int fd);

/*
**	Возвращает длину значения числа в шестадцатиричной системе
*/

static int	hexlen(char *color)
{
	int	length;

	length = 0;
	while (ft_isdigit(color[length]) || ft_isalpha(color[length]))
		length++;
	return (length);
}

int	fill_point(t_point *point, char *str, int j, int i)
{
	if (ft_isdigit(str[i]))
	{
		point->z = ft_atoi(&str[i]);
		i += ft_intcount((int)point->z);
		point->x = (i + 1);
		point->y = (j + 1);
		if (str[i] == ',')
		{
			i++;
			point->color = ft_atoi_base(&str[i], 16);
			i += hexlen(&str[i]);
		}
		i++;
		return (i);
	}
	return (1);
}

/*
**	Заполнение двумерного массива типа структура point
*/

static t_point	**fill_map_point(char *str, int y, int x)
{
	int		i;
	int		j;
	t_point	**map;

	i = 0;
	j = 0;
	map = (t_point **)ft_map_void(y, x, sizeof(t_point *), sizeof(t_point));
	if (!map)
		ft_map_void_del((void **)map, y);
	while(j < y)
	{
		while (*str != '\n')
		{
			if (ft_isdigit(*str))
			{
				map[j][i].x = (i + 1);
				map[j][i].y = (j + 1);
				map[j][i].z = ft_atoi(str);
				str += ft_intcount((int)map[j][i].z);
				if (*str == ',')
				{
					map[j][i].color = ft_atoi_base(++str, 16);
					str += hexlen(str);
				}
				i++;
			}
			else
				str++;
		}
		str++;
		i = 0;
		j++;
	}
	return (map);
}

int check_point(t_map *map)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while(j < map->row)
	{
		while(i < map->col)
		{
			if (map->start[j][i].x == 0 || map->start[j][i].y == 0)
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	input_map(t_fdf *fdf)
{
	int	val = 0;

	val = validation(fdf);
	if (val < 0)
		return (val);

	if (fdf->map.col < 2 || fdf->map.row < 1) // если файл пустой!!!!!!!!!
		return (-1);
	fdf->map.start = fill_map_point(fdf->map.str_map, fdf->map.row, fdf->map.col);

	if (check_point(&fdf->map)) // если файл неполный!!!!!!!!!!
		return (-4);

	fdf->map.other = (t_point **)ft_map_void(fdf->map.row, fdf->map.col,
											 sizeof(t_point *), sizeof(t_point));
//	printf("-----------start--------\n");
	ft_put_map_point_fd(fdf->map.start, fdf->map.row, fdf->map.col, 1);
	printf("row %d col %d\n", fdf->map.row, fdf->map.col);
	return (0);
}

/*
**	ошибки карты	|	решения
**	----------------------------------
**	пустая			|	-1
**	некорректная	|	-2
**	отсутствие ф.	|	-3
**	неполная		|	-4 дориосвать нули
**	отсутвие пар.	|	-5
**					|
**	----------------------------------
**
*/


/*	УДАЛИТЬ или для лога оставить!
**	Выводит двумерный числовой(int) массив размерами row x col в поток fd
*/

/*static */void	ft_put_map_point_fd(t_point **map, int row, int col, int fd)
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
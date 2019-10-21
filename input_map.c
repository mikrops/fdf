/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:06:20 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/21 19:51:29 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_map_point_fd(t_point **map, int row, int col, int fd);

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

/*
**	Возвращает количество чисел в строке, игнорируя цвет
*/

static int count_digit(char *str)
{
	int i;
	int digit;
	int count;

	i = 0;
	digit = 0;
	count = 0;
	while(str[i])
	{
		if (ft_isdigit(str[i]))
		{
			digit = ft_atoi(&str[i]);
			i += ft_intcount(digit);
			count++;
		}
		else if (str[i] == ',')
			i += hexlen(&str[i]) + 1;
		else
			i++;
	}
	return (count);
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
				map[j][i].z = ft_atoi(str);
				str += ft_intcount((int)map[j][i].z);
				map[j][i].x = (i + 1);
				map[j][i].y = (j + 1);
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


int	input_map(char *av, t_fdf *fdf)
{
	int		fd;
	char	*str;
	char 	*tmp;
	// можно использовать из map .col и .row,
	// но тогда надо иниг запускать раньше цыкла или передавать tmp в структуру
	int 	i;
	int 	j;

	fd = open(av, O_RDONLY);
	i = 0;
	j = 0;
	tmp = "";
//	printf("open(fd = %d)\n", fd);
	while (get_next_line(fd, &str))
	{
		i = count_digit(str);
		tmp = ft_strjoin(tmp, str);			//!!!!!исправить ft_strjoin!!!!!!!!
		free(str);
		tmp = ft_strjoin(tmp, "\n");	//!!!!!исправить ft_strjoin!!!!!!!!
		j++;
	}
//	printf("close(fd = %d) j = %d i = %d\n", close(fd), j, i);
// киевская шубенский переулок
	initialization(fdf, av);
	fdf->map.col = i;
	fdf->map.row = j;
	fdf->map.plato = 0;
	fdf->map.start_p = fill_map_point(tmp, j, i);
	fdf->map.other_p = (t_point **)ft_map_void(j, i, sizeof(t_point *), sizeof(t_point));
//	map->other_p = copy_map_point(map->start_p, j, i);
	printf("-----------start_p--------\n");
	ft_put_map_point_fd(fdf->map.start_p, j, i, 1);
	printf("\n");
	//free(tmp);
	return (0);
}

/*
**	ошибки карты	|	решения
**	----------------------------------
**	пустая			|	-1
**	некорректная	|	-2
**	отсутствие ф.	|	-3
**	неполная		|	-4 предложить действия(дориосвать или выйти)
**	отсутвие пар.	|	-5
**					|
**	----------------------------------
**
*/


/*	УДАЛИТЬ или для лога оставить!
**	Выводит двумерный числовой(int) массив размерами row x col в поток fd
*/

static void	ft_put_map_point_fd(t_point **map, int row, int col, int fd)
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
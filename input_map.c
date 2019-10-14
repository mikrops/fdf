/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:06:20 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/14 20:15:28 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Возвращает количество чисел в строке, игнорируя цвет
*/

int count_digit(char *str)
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
			i += 10;
		else
			i++;
	}
	return (count);
}

/*
**	выделение памяти под двумерный массив void
*/

void	**ft_map_void(int row, int col, int size_row, int size_col)
{
	int		i;
	void	**map;

	i = 0;
	map = (void **)ft_memalloc(size_row * (row + 1));
	map[row] = NULL;
	while (i < row)
	{
		map[i] = (void *)ft_memalloc(size_col * (col + 1));
		i++;
	}
	return (map);
}

/*
**	Заполнение двумерного массива
 */

int	**fill_map(char *str, int y, int x)
{
	int i;
	int j;
	int **map;

	i = 0;
	j = 0;
	map = ft_map_int(y, x);
	while(j < y)
	{
		while (*str != '\n')
		{
			if (ft_isdigit(*str))
			{
				map[j][i] = ft_atoi(str);
				str += ft_intcount(map[j][i]);
				i++;
			}
			else if (*str == ',')
				str += 10;
			else
				str++;
		}
		str++;
		i = 0;
		j++;
	}
	return (map);
}

/*
**	Заполнение двумерного массива
 */

t_point	**fill_map_point(char *str, int y, int x)
{
	int i;
	int j;
	t_point **map;

	i = 0;
	j = 0;
	map = (t_point **)ft_map_void(y, x, sizeof(t_point *), sizeof(t_point));
	while(j < y)
	{
		while (*str != '\n')
		{
			if (ft_isdigit(*str))
			{
				map[j][i].z = ft_atoi(str);
				str += ft_intcount((int)map[j][i].z);
				i++;
			}
			else if (*str == ',')
				str += 10;
			else
				str++;
		}
		str++;
		i = 0;
		j++;
	}
	return (map);
}

int	input_map(char *av, t_map *map)
{
	int		fd;
	char	*str;
	char 	*tmp;
	int 	i;
	int 	j;

	fd = open(av, O_RDONLY);
	i = 0;
	j = 0;
	tmp = "";
	printf("open(fd = %d)\n", fd);
	while (get_next_line(fd, &str))
	{
		i = count_digit(str);
		tmp = ft_strjoin(tmp, str);			//!!!!!исправить ft_strjoin!!!!!!!!
		free(str);
		tmp = ft_strjoin(tmp, "\n");	//!!!!!исправить ft_strjoin!!!!!!!!
		j++;
	}
	printf("close(fd = %d) j = %d i = %d\n", close(fd), j, i);
	map->col = j;
	map->row = i;
	map->start = fill_map(tmp, j, i);
	//пробуем структуры
	map->start_p = fill_map_point(tmp, j, i);
	printf("int = %lu, point = %lu\n", sizeof(map->start), sizeof(map->start_p));
	printf("%d\n", map->start[1][0]);


	dprintf(1, "%d\n", 0xFFFFFF);
//	int b = 0xFFFFFFd;
	int b = 'A';
	printf("%d\n", b - 55);
//	char *str = "0xFFFFFF";


/*
 * НОРМУУУУУ!!! atoi_base
**	Возвращает десятичное число переведенное из строки в base системе счисления
*/


	printf("atoi_base = %d\n", ft_atoi_base("0xFFFFFF", 16));



	//закончили со структурой
	ft_put_map_int_fd(map->start, j, i, 1);
	//free(tmp);
	return (0);
}

/*
**	ошибки карты	|	решения
**	----------------------------------
**	пустая			|	-1
**	неполная		|	-2 предложить действия(дориосвать или выйти)
**	некорректная	|	-3
**	отсутствие		|	-4
**					|
**	----------------------------------
**
*/

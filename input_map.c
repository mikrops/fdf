/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:06:20 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/12 18:20:04 by mmonahan         ###   ########.fr       */
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
		//printf("i = %d \t %s\n", i, str);
		j++;
	}
	printf("close(fd = %d) j = %d i = %d\n", close(fd), j, i);
	map->col = j;
	map->row = i;
	map->start = fill_map(tmp, j, i);
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

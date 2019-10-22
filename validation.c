/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:17:35 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/22 15:01:47 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Возвращает длину значения числа в шестадцатиричной системе
*/

static int	hexlen_1(char *color)
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

static int count_digit_1(char *str)
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
		{
			i++;
			i += hexlen_1(&str[i]);
		}
		else
			i++;
	}
	return (count);
}

/*
**	Проверяет на наличие валидных символов в строке
*/

int	check_str_1(char const *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'x' && str[i] != ',' && str[i] != '-' &&
			!(str[i] >= 'a' && str[i] <= 'f') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			!ft_isdigit(str[i]) &&
			!ft_isspace(str[i]))
			return (-2);
		i++;
	}
	return (0);
}

int validation(t_fdf *fdf)
{
	int		fd;
	char	*str;
	int 	tmp_col;

	tmp_col = 0;
	if ((fd = open(fdf->win.name, O_RDONLY)) < 1) // если файла нет!!!!!!!!!
		return (-3);
	while (get_next_line(fd, &str))
	{
		if (check_str_1(str)) // если файл некоректный!!!!!!!!!
			return (-2);
		fdf->map.col = count_digit_1(str);
		if (fdf->map.row == 0)
			tmp_col = fdf->map.col;
		else if (fdf->map.col != tmp_col)
			return (-4);
		fdf->map.str_map = ft_strjoin(fdf->map.str_map, str);			//!!!ФРИШИТЬ!!!
		free(str);
		fdf->map.str_map = ft_strjoin(fdf->map.str_map, "\n");		//!!!ФРИШИТЬ!!!
		fdf->map.row++;
	}
	return (0);
}


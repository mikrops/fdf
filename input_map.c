/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:06:20 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/11 16:05:16 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//int count_digit(char *str)
//{
//	int i;
//	int digit;
//
//	i = 0;
//	digit = 0;
//	while(str[i])
//	{
//		if (ft_isdigit(str[i]))
//		{
//
//		}
//		i++;
//	}
//	return (0);
//}


int	input_map(char *av)
{
	int		fd;
	char	*str;
	int 	i;
	int 	j;

	fd = open(av, O_RDONLY);
	i = 0;
	j = 0;
	printf("open(fd = %d)\n", fd);
	while (get_next_line(fd, &str))
	{
		printf("%s\n", str);
		j++;
	}
	printf("close(fd = %d) %d %d\n", close(fd), i, j);
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
*/
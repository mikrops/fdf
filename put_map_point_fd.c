/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_point_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:01:49 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/24 16:42:58 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Выводит двумерный массив типа t_point размерами row x col в поток fd
*/

void	put_map_point_fd(int fd, t_point **point, int row, int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < row)
	{
		while (i < col)
		{
			ft_putchar_fd('[', fd);
			ft_putnbr_fd((int)point[j][i].x, fd);
			ft_putchar_fd(',', 1);
			ft_putnbr_fd((int)point[j][i].y, fd);
			ft_putchar_fd(',', 1);
			ft_putnbr_fd((int)point[j][i].z, fd);
			ft_putchar_fd(',', 1);
			ft_putnbr_fd(point[j][i].color, fd);
			ft_putstr_fd("]\t", fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
		i = 0;
		j++;
	}
}

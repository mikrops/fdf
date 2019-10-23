/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_point_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:01:49 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/23 16:04:41 by mmonahan         ###   ########.fr       */
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
			dprintf(fd, "[%.f,%.f,%.f,%d]\t", point[j][i].x, point[j][i].y, point[j][i].z, point[j][i].color);
//			ft_putnbr_fd(point[j][i].z, fd);
//			ft_putchar_fd('\t', fd);
			i++;
		}
		dprintf(fd, "\n");
//		ft_putstr_fd("\n", fd);
		i = 0;
		j++;
	}
}

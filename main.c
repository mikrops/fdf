/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:12:41 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/11 17:29:21 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void usage(int error)
{
	if (error == -1)
		write(2, "Пустой файл\n", 22);
	else if (error == -2)
	{
		write(2, "В карте присутвтуеют не все значения, заполнить их нулями?\n",
			  106);
	}
	else if (error == -3)
		write(2, "Некорректный файл\n", 34);
	else if (error == -4)
		write(2, "Usage: ./fdf [name_file.fdf]\n", 29);
	else
		write(2, "Error\n", 6);
}

int main(int ac, char **av)
{
	t_mlx	mlx;
	t_line	line;

	write(1, "Привет, сын железа!\n", 35);
	if (ac != 2)
	{
		usage(-4);
		return (0);
	}

	input_map(av[1]);

	if (mlx.win.height || line.start.y)
		;
	//fdf(&mlx, &line);
    return 0;
}
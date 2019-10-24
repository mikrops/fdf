/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:12:41 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/23 13:02:36 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Выводит на консоль системное сообщение в случае ошибки
*/

static void	usage(int error)
{
	if (error == -1)
		write(2, "Ошибка -1. Пустой файл\n", 39);
	else if (error == -2)
		write(2, "Ошибка -2. Некорректный файл\n", 51); // плохие символы
	else if (error == -3)
		write(2, "Ошибка -3. Отсутвтует файл\n", 47);
	else if (error == -4)
		write(2, "Ошибка -4. Неполный файл. По возможности заполнено нулями\n", 104);
	else if (error == -5)
		write(2, "Usage: ./fdf [name_file.fdf]\n", 29);
	else
		write(2, "Error\n", 6);
}

int			main(int ac, char **av)
{
	t_fdf	tfdf;
	int		validation;

	if (ac == 2)
	{
		write(1, "Привет, сын железа!\n", 35);
		initialization(&tfdf, av[1]);
		validation = input_map(&tfdf);
		if (validation == 0)
			fdf(&tfdf);
		else
			usage(validation);
	}
	else
		usage(-5);
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:12:41 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/25 14:36:30 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Выводит на консоль системное сообщение в случае ошибки
*/

static void	usage(int error)
{
	if (error == ERROR_EMPTY_FILE)
		write(2, "Ошибка 1. Пустой файл\n", 38);
	else if (error == ERROR_INVALID_FILE)
		write(2, "Ошибка 2. Некорректный файл\n", 50);
	else if (error == ERROR_MISSING_FILE)
		write(2, "Ошибка 3. Отсутствует файл\n", 48);
	else if (error == ERROR_INCOMPLETE_FILE)
		write(2, "Ошибка 4. Неполный файл\n", 42);
	else if (error == ERROR_USAGE)
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
		usage(ERROR_USAGE);
	return (0);
}

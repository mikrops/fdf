/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:06:20 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/11 18:56:39 by mmonahan         ###   ########.fr       */
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

void pr(t_list *elem)
{
	printf("list[%zu] - %p\n", elem->content_size, elem->content);
}

void add_point(t_list *list, char *str, int size)
{
	int		i;
	int		digit;
	t_point	point;

	i = 0;
	digit = 0;
	while (size)
	{
		if (ft_isdigit(str[i]))
		{
			digit = ft_atoi(&str[i]);
			i += ft_intcount(digit);
			point.z = digit;
			ft_lstadd(&list, ft_lstnew(&point, size > 1 ? 0 : 1));
			//printf("addlist[%d] - %p - %zu\n", size, list->content, list->content_size);
			size--;
		}
		else
			i++;
	}
	ft_lstiter(list, pr);
}

int	input_map(char *av)
{
	t_list 	*list;
	t_list	*start;
	int		fd;
	char	*str;
	int 	i;
	int 	j;

	fd = open(av, O_RDONLY);
	i = 0;
	j = 0;
	list = ft_memalloc(sizeof(t_list));
	start = ft_memalloc(sizeof(t_list));

	start = list;
	printf("open(fd = %d)\n", fd);
	while (get_next_line(fd, &str))
	{
		i = count_digit(str);
		add_point(list, str, i);
		if (j == 0)
		{
			start = list;
			printf("SAVEEEEEE\n");
		}
		printf("i = %d \t %s\n", i, str);
		j++;
	}
	printf("close(fd = %d) %d %d\n", close(fd), i, j);

	ft_lstiter(start, pr);

//	printf("%zu\n", list->content_size);
//	printf("%zu\n", list->next->content_size);
//	printf("%zu\n", list->next->next->content_size);
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

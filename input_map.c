/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:06:20 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/11 21:02:27 by mmonahan         ###   ########.fr       */
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

//void pr(t_list *elem)
//{
//	printf("list[%zu] - %p\n", elem->content_size, elem->content);
//}

//void add_point(t_list *list, char *str, int size)
//{
//	int		i;
//	int		digit;
//	t_point	point;
//	if (list)
//		;
//
//	i = 0;
//	digit = 0;
//	while (size)
//	{
//		if (ft_isdigit(str[i]))
//		{
//			digit = ft_atoi(&str[i]);
//			i += ft_intcount(digit);
//			point.z = digit;
//			//ft_lstadd(&list, ft_lstnew(&point, size > 1 ? 0 : 1));
//			//printf("addlist[%d] - %p - %zu\n", size, list->content, list->content_size);
//			size--;
//		}
//		else
//			i++;
//	}
//	//ft_lstiter(list, pr);
//}

void	fill_map(char *map, int y, int x)
{
	int i;
	int j;
	int digit;
	int **arr;

	i = 0;
	j = 0;
	digit = 0;
	arr = ft_map_int(y, x);
	while(j < y)
	{
		while (i < x)
		{
			if (ft_isdigit(*map))
			{
				digit = ft_atoi(map);
				map += ft_intcount(digit);
			}
			else
				i++;
		}
		i = 0;
		j++;
	}
	ft_put_map_int_fd(arr, y, x, 1);
}

int	input_map(char *av)
{
//	t_list 	*list;
//	t_list	*start;
	int		fd;
	char	*str;
	char 	*tmp;
	int 	i;
	int 	j;

	fd = open(av, O_RDONLY);
	i = 0;
	j = 0;
	tmp = ft_memalloc(1);
//	list = ft_memalloc(sizeof(t_list));
//	start = ft_memalloc(sizeof(t_list));
//
//	start = list;
	printf("open(fd = %d)\n", fd);
	while (get_next_line(fd, &str))
	{
		i = count_digit(str);
		//add_point(list, str, i);
//		if (j == 0)
//		{
//			start = list;
//			printf("SAVEEEEEE\n");
//		}
		tmp = ft_strjoin(tmp, str);			//!!!!!исправить ft_strjoin!!!!!!!!
		free(str);
		tmp = ft_strjoin(tmp, "\n");	//!!!!!исправить ft_strjoin!!!!!!!!
		printf("i = %d \t %s\n", i, str);
		j++;
	}
	printf("close(fd = %d) j = %d i = %d\n", close(fd), j, i);
	printf("%sstring end\n", tmp);
	/*
	 * ИСПРАВИТЬ ФИЛЛ!!!
	*/
	fill_map(tmp, j, i);

	//ft_lstiter(start, pr);
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

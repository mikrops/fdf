/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:41:48 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/24 20:03:36 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Функция strcpy() копирует строку, на которую указывает src (включая
**	завершающий символ `\0'), в массив, на который указывает dest. Строки
**	не могут перекрываться, и в результирующей строке dest должно быть
**	достаточно места для копии.
**
**	Возвращают указатель на результирующую строку dest.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	char	*tmp;

	tmp = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (tmp);
}

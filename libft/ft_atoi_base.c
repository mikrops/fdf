/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:58:10 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/14 20:15:13 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * НОРМУУУУУ!!!
**	Возвращает десятичное число переведенное из строки в base системе счисления
*/

int	ft_atoi_base(char *str, int base)
{
	int	digit;
	int temp;
	int len;
	int i;

	digit = 0;
	temp = 0;
	i = 0;
	if (base == 16)
		i += 2;
	len = ft_strlen(str) - i - 1;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'F')
		{
			temp = str[i] - 55;
			digit += temp * ft_pow(base, len--);
		}
		else if (ft_isdigit(str[i]))
		{
			temp = str[i] - 48;
			digit += temp * ft_pow(base, len--);
		}
		else
			return (0);
		i++;
	}
	return (digit);
}


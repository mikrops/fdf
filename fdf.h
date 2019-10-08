/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:13:55 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/08 14:29:12 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

#include <stdlib.h>
#include <stdio.h>
#include "minilibx_macos/mlx.h"

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			c;
}				t_color;

typedef struct	s_point
{
	int			x;
	int			y;
	t_color		c;
}				t_point;

typedef struct	s_line
{
	t_point		start;
	t_point		finish;
}				t_line;

#endif

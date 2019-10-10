/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:13:55 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/10 17:26:55 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "minilibx_macos/mlx.h"

//typedef struct	s_color
//{
//	int			r;
//	int			g;
//	int			b;
//	int			c;
//}				t_color;

typedef struct	s_point
{
	double		x;
	double		y;
	//t_color		c;
}				t_point;

typedef struct	s_line
{
	t_point		start;
	t_point		end;
}				t_line;

typedef struct	s_bresenham
{
    int 		x1;
    int			y1;
    int 		x2;
    int			y2;
	int 		deltax;
	int			deltay;
	int 		deltaerror;
	int 		error;
	int 		dirx;
	int 		diry;
}				t_bresenham;

typedef struct	s_window
{
	void		*ptr;
}				t_window;

typedef struct  s_mlx
{
	void 		*ptr;
	t_window	win;
}               t_mlx;

void put_line(t_mlx *mlx, t_line *line);

#endif

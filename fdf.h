/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:13:55 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/15 14:56:08 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# define WIDTH 2000
# define HEIGHT 1000

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

//typedef struct		s_color
//{
//	unsigned char	red;
//	unsigned char	green;
//	unsigned char	blue;
//	float			brightness;
//}					t_color;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int 		color;
	//t_color		_color;
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
	int			width;
	int			height;
	char 		*title;
}				t_window;

typedef struct  s_mlx
{
	void 		*ptr;
	t_window	win;
	double		zoom;
}               t_mlx;

typedef struct	s_map
{
	int			row;
	int 		col;
	int			**start;
	int 		**other;
	double		iso;
	t_point		**start_p;
	t_point		**other_p;
}				t_map;

int				input_map(char *av, t_map *map);
void			put_line(t_mlx *mlx, t_line *line);
void			draw_grid(t_mlx *mlx, t_line *line, t_map *map);
void			fdf(t_mlx *mlx, t_line *line, t_map *map);

#endif

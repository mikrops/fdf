/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:13:55 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/19 20:48:52 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# define WIDTH 1000.0
# define HEIGHT 1000.0

/*
**	Коды клавишь
*/

# define MUSE_CLICK_LEFT 1
# define MUSE_CLICK_RIGHT 2
# define MUSE_SCROLL_BACK 4
# define MUSE_SCROLL_FORARD 5
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_EQUALS 24
# define KEY_MINUS 27
# define KEY_BACK_SPASE 49
# define KEY_SPASE 51
# define KEY_ESC 53
# define KEY_HOME 115
# define KEY_PAGE_UP 116
# define KEY_DELETE 117
# define KEY_ENTER 118
# define KEY_END 119
# define KEY_PAGE_DOWN 121
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

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
	int			mouse_x;
	int 		mouse_y;
	char 		*title;
	char 		*name;
}				t_window;

typedef struct  s_mlx
{
	void 		*ptr;
}               t_mlx;

typedef struct	s_map
{
	double		rotationx;
	double		rotationy;
	double		rotationz;
	int			row;
	int 		col;
	double		centry;
	double		centrx;
	double		scale;
	double		height;
	double		angle;

	t_point		**start_p;
	t_point		**other_p;
}				t_map;

typedef struct	s_fdf
{
	t_mlx		mlx;
	t_window	win;
	t_map		map;
}				t_fdf;

void			put_line(t_mlx *mlx, t_window *win, t_line *line);
void			draw_grid(t_fdf *fdf);
void			info(t_fdf *fdf, int check);
void			calculation(t_map *map);
void			fdf(t_fdf *fdf);
void			initialization(t_fdf *fdf, char *name);
int				input_map(char *av, t_fdf *fdf);

#endif

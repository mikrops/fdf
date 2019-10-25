/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:19:18 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/25 18:32:52 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# define WIDTH 1000.0
# define HEIGHT 1000.0

/*
**	Коды клавишь и мыши
*/

# define EVENT_KEY_DOWN 2
# define EVENT_MOUSE_CLICK 4
# define MOUSE_SCROLL_BACKWARD 4
# define MOUSE_SCROLL_FORWARD 5
# define KEY_C 8
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_3 20
# define KEY_EQUALS 24
# define KEY_MINUS 27
# define KEY_ENTER 36
# define KEY_L 37
# define KEY_BACK_SPASE 49
# define KEY_SPASE 51
# define KEY_ESC 53
# define KEY_HOME 115
# define KEY_PAGE_UP 116
# define KEY_DELETE 117
# define KEY_END 119
# define KEY_PAGE_DOWN 121
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define KEY_H 4
# define KEY_G 5
# define KEY_V 9
# define KEY_B 11

/*
**	Коды цветов
**	https://www.color-hex.com/color-names.html
*/

# define GREEN 0x32CD32
# define RED 0xff0000
# define PALE 0xafeeee
# define AQUAMARINE 0x66cdaa
# define BISQUE3 0xcdb79e
# define DEEPSKYBLUE3 0x009acd

/*
**	Минимум, максимум и шаг расчетных переменных
*/

# define MIN_SCL 1
# define MAX_SCL 50
# define STEP_SCL 1
# define MIN_HGT -35
# define MAX_HGT 20
# define STEP_HGT 1

/*
**	Ошибки
*/

# define ERROR_EMPTY_FILE 1
# define ERROR_INVALID_FILE 2
# define ERROR_MISSING_FILE 3
# define ERROR_INCOMPLETE_FILE 4
# define ERROR_USAGE 5

/*
**	Флаги
*/

# define INFO_START 0
# define INFO_GAME 1

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_line
{
	t_point		start;
	t_point		end;
}				t_line;

typedef struct	s_bresenham
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			deltax;
	int			deltay;
	int			deltaerror;
	int			error;
	int			dirx;
	int			diry;
}				t_bresenham;

typedef struct	s_window
{
	void		*ptr;
	int			width;
	int			height;
	int			themes;
	int			mouse_x;
	int			mouse_y;
	char		*title;
	char		*name;
}				t_window;

typedef struct	s_mlx
{
	void		*ptr;
}				t_mlx;

typedef struct	s_map
{
	double		rotation_x;
	double		rotation_y;
	double		rotation_z;
	double		centr_y;
	double		centr_x;
	double		scale;
	double		height;
	double		iso;
	int			plato;
	int			loger;
	int			flag_color;
	int			row;
	int			col;
	char		*str_map;
	t_point		**start;
	t_point		**other;
}				t_map;

typedef struct	s_fdf
{
	t_mlx		mlx;
	t_window	win;
	t_map		map;
}				t_fdf;

void			put_map_point_fd(int fd, t_point **point, int row, int col);
void			info(t_fdf *fdf, int check);
void			put_line(t_mlx *mlx, t_window *win, t_line *line);
void			draw_grid(t_fdf *fdf);
int				hook_deal_key(int key, void *param);
void			calculation(t_map *map);
void			fdf(t_fdf *fdf);
int				validation(t_fdf *fdf);
int				input_map(t_fdf *fdf);
void			initialization(t_fdf *fdf, char *name);

#endif

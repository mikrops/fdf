/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:48:33 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/15 19:43:11 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static void iso(int *x, int *y, int z)
//{
//	int previous_x;
//	int previous_y;
//
//	previous_x = *x;
//	previous_y = *y;
//	*x = (previous_x - previous_y) * cos(0.523599);
//	*y = -z + (previous_x + previous_y) * sin(0.523599);
//}
//
//t_point project(t_point p, t_fdf *fdf)
//{
//// ...
//	if (fdf->camera->projection == ISO)
//		iso(&p.x, &p.y, p.z);
//// ...
//}

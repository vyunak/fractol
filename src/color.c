/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:07:33 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/29 16:07:54 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			get_color(unsigned int i, t_data data)
{
	unsigned int color;
	unsigned int a;
	unsigned int r;
	unsigned int g;
	unsigned int b;

	a = (i * i) % 255;
	r = (i * data.t_rgb.r) % 255;
	g = (i * data.t_rgb.g) % 255;
	b = (i * data.t_rgb.b) % 255;
	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

int			color_irgb(unsigned int i, int r, int g, int b)
{
	unsigned int color;
	unsigned int a;

	a = (i * 2) % 255;
	r = ((r * i) * 10) % 255;
	g = ((g * i) * 10) % 255;
	b = ((b * i) * 10) % 255;
	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

int			color_argb(unsigned int a, unsigned int r,
	unsigned int g, unsigned int b)
{
	unsigned int color;

	a = (a) % 255;
	r = (r) % 255;
	g = (g) % 255;
	b = (b) % 255;
	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

int			ft_exit(void)
{
	exit(1);
}

double		min_double(double t1, double t2)
{
	if (t1 < t2)
		return (t1);
	else
		return (t2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:02:05 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/29 16:12:02 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mandelbrot(t_data *data, t_itfr *it, int i)
{
	it->cim = it->im;
	it->cre = it->re;
	it->re = 0;
	it->oldim = 0;
	it->oldre = 0;
	it->im = 0;
	while (i < data->iter)
	{
		it->oldre = it->re;
		it->oldim = it->im;
		it->re = it->oldre * it->oldre - it->oldim * it->oldim + it->cre;
		it->im = 2 * it->oldre * it->oldim + it->cim;
		i++;
		if (*data->fractol == 4)
		{
			if ((it->re * it->re * it->im * it->im) >= 4)
				break ;
		}
		else
		{
			if ((it->re * it->re + it->im * it->im) > 4)
				break ;
		}
	}
	return ((i < data->iter) ? get_color(i, (*data)) : 0x000000);
}

int			burningship(t_data *data, t_itfr *it, int i)
{
	it->cim = it->im;
	it->cre = it->re;
	it->re = 0;
	it->oldim = 0;
	it->oldre = 0;
	it->im = 0;
	while (i < data->iter)
	{
		it->oldre = fabs(it->re);
		it->oldim = fabs(it->im);
		it->re = it->oldre * it->oldre - it->oldim * it->oldim + it->cre;
		it->im = 2 * it->oldre * it->oldim + it->cim;
		i++;
		if (*data->fractol == 6)
		{
			if ((it->re * it->re * it->im * it->im) >= 4)
				break ;
		}
		else
		{
			if ((it->re * it->re + it->im * it->im) > 4)
				break ;
		}
	}
	return ((i < data->iter) ? get_color(i, (*data)) : 0x000000);
}

int			julia_set(t_data *data, t_itfr *it, int i)
{
	while (i < data->iter)
	{
		it->oldre = it->re;
		it->oldim = it->im;
		it->re = it->oldre * it->oldre - it->oldim * it->oldim + it->cre;
		it->im = 2 * it->oldre * it->oldim + it->cim;
		i++;
		if (*data->fractol == 2)
		{
			if ((it->re * it->re * it->im * it->im) >= 4)
				break ;
		}
		else
		{
			if ((it->re * it->re + it->im * it->im) >= 4)
				break ;
		}
	}
	return ((i < data->iter) ? get_color(i, (*data)) : 0x000000);
}

int			newtone(t_data *data, t_itfr *it, int i)
{
	TCOMPLEX	z;
	TCOMPLEX	r[3];

	z = it->im + it->re * I;
	r[0] = 1 + 0 * I;
	r[1] = -0.5 + sin(2 * M_PI / 3) * I;
	r[2] = -0.5 - sin(2 * M_PI / 3) * I;
	while (i < data->iter)
	{
		if (min_double(cabs((z - r[0])),
				min_double(cabs((z - r[1])), cabs((z - r[2])))) < 0.001)
			break ;
		i++;
		z = z - (z * z * z - 1.0) / (z * z * 3.0);
		if (*data->fractol == 8)
			z = z - (z * z * z - 1.0) / (z * z + 19);
		if (*data->fractol == 9)
			z = z - (z * z * z - 1.0) / (z * z * i / 3.0);
	}
	return (color_irgb(i, (int)cabs(z - r[0]),
			(int)cabs(z - r[1]), (int)cabs(z - r[2])));
}

void		calc_posix(t_data *data, t_thread **tread, int **img)
{
	int			x;
	int			ntr;
	t_thread	*tmp;

	ntr = 4;
	x = ntr + 1;
	while (--x)
	{
		if (x == ntr)
			pos_init(&*data, &(*tread), &*img, x);
		else
		{
			tmp = (*tread);
			while (tmp->next)
				tmp = tmp->next;
			pos_set_data(&*data, &*tmp, &*img, x);
		}
	}
}

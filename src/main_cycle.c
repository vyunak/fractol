/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:12:59 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/29 16:13:26 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		new_ri(t_data *data, int xy, int i, double movexy)
{
	double e;

	if (i == 1)
		e = 1.5 * (xy - W_WIDTH / 2) / (0.5 *
			*data->zoom * W_WIDTH) + movexy + ((*data->fractol >= 3 &&
				*data->fractol <= 6) ? -0.5 : 0);
	else
	{
		e = (xy - W_HEIGHT / 2) / (0.5 *
				*data->zoom * W_HEIGHT) + movexy;
	}
	return (e);
}

void		main_cycle(t_thread **tread)
{
	int			i[3];
	t_itfr		it;

	it.cre = -0.7 + (*tread)->data->mouse_x;
	it.cim = 0.27015 + (*tread)->data->mouse_y;
	i[0] = (*tread)->start_y - 1;
	while (++i[0] < (*tread)->end_y)
	{
		i[1] = (*tread)->start_x - 1;
		while (++i[1] < (*tread)->end_x)
		{
			it.re = new_ri(&*(*tread)->data, i[1], 1, *(*tread)->data->mx);
			it.im = new_ri(&*(*tread)->data, i[0], 2, *(*tread)->data->my);
			if (*(*tread)->data->fractol == 1 || *(*tread)->data->fractol == 2)
				i[2] = julia_set(&*(*tread)->data, &it, 0);
			if (*(*tread)->data->fractol == 3 || *(*tread)->data->fractol == 4)
				i[2] = mandelbrot(&*(*tread)->data, &it, 0);
			if (*(*tread)->data->fractol == 5 || *(*tread)->data->fractol == 6)
				i[2] = burningship(&*(*tread)->data, &it, 0);
			if (*(*tread)->data->fractol >= 7 && *(*tread)->data->fractol <= 9)
				i[2] = newtone(&*(*tread)->data, &it, 0);
			*(*(*tread)->img + ((i[1]) + (i[0] * ((W_WIDTH - W_HEIGHT) +
			W_HEIGHT)))) = i[2];
		}
	}
}

void		usage(void)
{
	ft_printf("Usage: ./fractol -n [1-9] -n [1-9]\n");
	ft_printf("                 -n 1 Julia\n");
	ft_printf("                 -n 2 Julia with form\n");
	ft_printf("                 -n 3 Mandelbrot\n");
	ft_printf("                 -n 4 Mandelbrot form\n");
	ft_printf("                 -n 5 Burn ship\n");
	ft_printf("                 -n 6 Burn ship form\n");
	ft_printf("                 -n 7 Newton\n");
	ft_printf("                 -n 8 Newton hollow\n");
	ft_printf("                 -n 9 Newton fireworks\n");
	exit(0);
}

void		pos_init(t_data *data, t_thread **tread, int **img, int ntr)
{
	int			wd;

	wd = W_WIDTH / ntr;
	(*tread) = (t_thread*)malloc(sizeof(t_thread));
	(*tread)->start_y = 0;
	(*tread)->start_x = wd * (ntr - 1);
	(*tread)->end_y = W_HEIGHT;
	(*tread)->end_x = wd * ntr;
	(*tread)->img = &(*img);
	(*tread)->data = data;
	(*tread)->next = NULL;
}

void		pos_set_data(t_data *data, t_thread *tmp, int **img, int x)
{
	int			wd;

	wd = W_WIDTH / 4;
	tmp->next = (t_thread*)malloc(sizeof(t_thread));
	tmp->next->start_y = 0;
	tmp->next->start_x = wd * (x - 1);
	tmp->next->end_y = W_HEIGHT;
	tmp->next->end_x = wd * x;
	tmp->next->img = &(*img);
	tmp->next->data = data;
	tmp->next->next = NULL;
}

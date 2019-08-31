/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:11:12 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/29 16:13:53 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_move(int x, int y, t_data *data)
{
	if (x > 0 && x <= W_WIDTH && y > 0 && y <= W_HEIGHT &&
		data->mouse_mod1 == 1 && (*data->fractol == 1 || *data->fractol == 2))
	{
		data->mouse_y = ((double)(y - W_HEIGHT / 2) / W_HEIGHT);
		data->mouse_x = ((double)(x - W_WIDTH / 2) / W_WIDTH);
		paint_fractal(&(*data), 1);
	}
	return (0);
}

int			mouse_zoom(int g, int x, int y, t_data *data)
{
	double	t1;
	double	t2;

	if (g == 5 || g == 4)
	{
		if ((g == 4 && data->zoom_w1 && data->zoom_w1 < 112457189287942) ||
		(g == 5 && data->zoom_w1 > 0.5))
		{
			t1 = *data->mx;
			t2 = *data->my;
			*data->mx += new_ri(&*data, x, 1, *data->mx);
			*data->my += new_ri(&*data, y, 2, *data->my);
			if (g == 4 && data->zoom_w1 && data->zoom_w1 < 112457189287942)
				data->zoom_w1 += 0.1 * (data->zoom_w1 * 0.7);
			if (g == 5 && data->zoom_w1 > 0.5)
				data->zoom_w1 -= 0.1 * (data->zoom_w1 * 0.7);
			*data->mx -= new_ri(&*data, x, 1, t1);
			*data->my -= new_ri(&*data, y, 2, t2);
			paint_fractal(&(*data), 1);
		}
	}
	return (1);
}

int			mouse_zoom2(int g, int x, int y, t_data *data)
{
	double	t1;
	double	t2;

	if (g == 5 || g == 4)
	{
		if ((g == 4 && data->zoom_w2 && data->zoom_w2 < 112457189287942) ||
		(g == 5 && data->zoom_w2 > 0.5))
		{
			t1 = *data->mx;
			t2 = *data->my;
			*data->mx += new_ri(&*data, x, 1, *data->mx);
			*data->my += new_ri(&*data, y, 2, *data->my);
			if (g == 4 && data->zoom_w2 && data->zoom_w2 < 112457189287942)
				data->zoom_w2 += 0.1 * (data->zoom_w2 * 0.7);
			if (g == 5 && data->zoom_w2 > 0.5)
				data->zoom_w2 -= 0.1 * (data->zoom_w2 * 0.7);
			*data->mx -= new_ri(&*data, x, 1, t1);
			*data->my -= new_ri(&*data, y, 2, t2);
			paint_fractal(&(*data), 2);
		}
	}
	return (1);
}

int			mouse_move2(int x, int y, t_data *data)
{
	if (x > 0 && x <= W_WIDTH && y > 0 && y <= W_HEIGHT &&
	data->mouse_mod2 == 1 && (*data->fractol == 1 || *data->fractol == 2))
	{
		data->mouse_y = ((double)(y - W_HEIGHT / 2) / W_HEIGHT);
		data->mouse_x = ((double)(x - W_WIDTH / 2) / W_WIDTH);
		paint_fractal(&(*data), 2);
	}
	return (0);
}

void		reset_w1(t_data *data)
{
	data->zoom_w1 = 0.5;
	data->movey_w1 = 0;
	data->movex_w1 = 0;
	data->mouse_y = 0;
	data->mouse_x = 0;
	data->iter = 100;
}

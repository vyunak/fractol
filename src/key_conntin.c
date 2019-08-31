/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_conntin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:10:29 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/29 16:10:52 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		reset_w2(t_data *data)
{
	data->zoom_w2 = 0.5;
	data->movey_w2 = 0;
	data->movex_w2 = 0;
	data->mouse_y = 0;
	data->mouse_x = 0;
	data->iter = 100;
}

void		reset_color(t_data *data)
{
	data->t_rgb.r = 0;
	data->t_rgb.g = 8;
	data->t_rgb.b = 0;
}

void		next_lvl(int keycode, t_data *data)
{
	(keycode == 12 && data->t_rgb.r < 253) ? data->t_rgb.r += 1 : 0;
	(keycode == 13 && data->t_rgb.g < 253) ? data->t_rgb.g += 1 : 0;
	(keycode == 14 && data->t_rgb.b < 253) ? data->t_rgb.b += 1 : 0;
	(keycode == 0 && data->t_rgb.r > 0) ? data->t_rgb.r -= 1 : 0;
	(keycode == 1 && data->t_rgb.g > 0) ? data->t_rgb.g -= 1 : 0;
	(keycode == 2 && data->t_rgb.b > 0) ? data->t_rgb.b -= 1 : 0;
	(keycode == 53) ? ft_exit() : 0;
}

void		kwrite(int keycode, t_data *data)
{
	if (keycode == 69 && data->zoom_w1 < 112457189287942)
		data->zoom_w1 += 0.1 * (data->zoom_w1 * 0.3);
	else if ((keycode == 78) && data->zoom_w1 > 0.5)
		data->zoom_w1 -= 0.1 * (data->zoom_w1 * 0.3);
	else if (keycode == 126 && data->movey_w1 > -((W_WIDTH / W_HEIGHT) * 1.5))
		data->movey_w1 -= 0.01 / (data->zoom_w1 * 0.3);
	else if (keycode == 125 && data->movey_w1 < ((W_WIDTH / W_HEIGHT) * 1.5))
		data->movey_w1 += 0.01 / (data->zoom_w1 * 0.3);
	else if (keycode == 123 && data->movex_w1 > -((W_WIDTH / W_HEIGHT) * 1.5))
		data->movex_w1 -= 0.01 / (data->zoom_w1 * 0.3);
	else if (keycode == 124 && data->movex_w1 < ((W_WIDTH / W_HEIGHT) * 1.5))
		data->movex_w1 += 0.01 / (data->zoom_w1 * 0.3);
	else if (keycode == 46)
		data->mouse_mod1 = (data->mouse_mod1 == 1) ? 0 : 1;
	else if (keycode == 45)
		data->menu_show1 = (data->menu_show1 == 1) ? 0 : 1;
	(keycode == 43 && data->iter > 10) ? data->iter -= 1 : 0;
	(keycode == 47 && data->iter < 200) ? data->iter += 1 : 0;
	(keycode == 49) ? reset_w1(&(*data)) : 0;
	(keycode == 8) ? reset_color(&(*data)) : 0;
	next_lvl(keycode, &(*data));
}

void		kwrite_2(int keycode, t_data *data)
{
	if (keycode == 69 && data->zoom_w2 < 112457189287942)
		data->zoom_w2 += 0.1 * (data->zoom_w2 * 0.3);
	else if ((keycode == 78) && data->zoom_w2 > 0.5)
		data->zoom_w2 -= 0.1 * (data->zoom_w2 * 0.3);
	else if (keycode == 126 && data->movey_w2 > -((W_WIDTH / W_HEIGHT) * 1.5))
		data->movey_w2 -= 0.01 / (data->zoom_w2 * 0.3);
	else if (keycode == 125 && data->movey_w1 < ((W_WIDTH / W_HEIGHT) * 1.5))
		data->movey_w2 += 0.01 / (data->zoom_w2 * 0.3);
	else if (keycode == 123 && data->movex_w1 > -((W_WIDTH / W_HEIGHT) * 1.5))
		data->movex_w2 -= 0.01 / (data->zoom_w2 * 0.3);
	else if (keycode == 124 && data->movex_w1 < ((W_WIDTH / W_HEIGHT) * 1.5))
		data->movex_w2 += 0.01 / (data->zoom_w2 * 0.3);
	else if (keycode == 46)
		data->mouse_mod2 = (data->mouse_mod2 == 1) ? 0 : 1;
	else if (keycode == 45)
		data->menu_show2 = (data->menu_show2 == 1) ? 0 : 1;
	(keycode == 43 && data->iter > 10) ? data->iter -= 1 : 0;
	(keycode == 47 && data->iter < 200) ? data->iter += 1 : 0;
	(keycode == 49) ? reset_w2(&(*data)) : 0;
	(keycode == 8) ? reset_color(&(*data)) : 0;
	next_lvl(keycode, &(*data));
}

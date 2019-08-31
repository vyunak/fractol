/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:10:06 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/29 16:10:49 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_press(int keycode, t_data *data)
{
	if (keycode < 128 && data->key_array[keycode])
	{
		kwrite(keycode, &*data);
		paint_fractal(&(*data), 1);
	}
	return (1);
}

int			key_press_w2(int keycode, t_data *data)
{
	if (keycode < 128 && data->key_array[keycode])
	{
		kwrite_2(keycode, &*data);
		paint_fractal(&(*data), 2);
	}
	return (1);
}

void		init_key_array(t_data *data)
{
	ft_bzero(&data->key_array, sizeof(data->key_array));
	data->key_array[43] = 1;
	data->key_array[126] = 1;
	data->key_array[125] = 1;
	data->key_array[123] = 1;
	data->key_array[124] = 1;
	data->key_array[69] = 1;
	data->key_array[78] = 1;
	data->key_array[46] = 1;
	data->key_array[45] = 1;
	data->key_array[8] = 1;
	data->key_array[12] = 1;
	data->key_array[53] = 1;
	data->key_array[13] = 1;
	data->key_array[14] = 1;
	data->key_array[0] = 1;
	data->key_array[1] = 1;
	data->key_array[2] = 1;
	data->key_array[47] = 1;
	data->key_array[49] = 1;
}

void		hook_and_paint(t_data *data)
{
	calc_posix(&(*data), &data->win_thread1, &data->idata_ptr);
	mlx_hook(data->win_ptr, 6, (1L << 6), mouse_move, &(*data));
	mlx_hook(data->win_ptr, 4, (1L << 2), mouse_zoom, &(*data));
	mlx_hook(data->win_ptr, 2, 0, key_press, &(*data));
	mlx_hook(data->win_ptr, 17, (1L << 17), ft_exit, 0);
	paint_fractal(&(*data), 1);
}

void		hook_and_paint_w2(t_data *data)
{
	calc_posix(&(*data), &data->win_thread2, &data->idata_ptr2);
	mlx_hook(data->win_ptr2, 6, (1L << 6), mouse_move2, &(*data));
	mlx_hook(data->win_ptr2, 4, (1L << 2), mouse_zoom2, &(*data));
	mlx_hook(data->win_ptr2, 2, 0, key_press_w2, &(*data));
	mlx_hook(data->win_ptr2, 17, (1L << 17), ft_exit, 0);
	paint_fractal(&(*data), 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:26:07 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/29 16:13:37 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		paint_menu(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < W_HEIGHT)
	{
		x = 0;
		while (++x < W_WIDTH)
			data->idata_ptr_menu[x + (y * ((W_WIDTH - W_HEIGHT) + W_HEIGHT))] =
		color_argb(255 / 100 * (x / (W_WIDTH / 100)), 0, 0, 0);
	}
}

void		show_menu(t_data *data)
{
	int		i;

	i = ((W_WIDTH / 4) - 45) / 2;
	mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr,
		(*data).img_ptr_menu, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, (W_WIDTH / 4) - 45, 45,
		0xffffff, "INFO");
	mlx_string_put(data->mlx_ptr, data->win_ptr, i, (W_WIDTH / 3) - (45 * 4),
		0xffffff, "Q/W/E:           R/G/B PLUS COLOR");
	mlx_string_put(data->mlx_ptr, data->win_ptr, i, (W_WIDTH / 3) - (45 * 3),
		0xffffff, "A/S/D:           R/G/B MINUS COLOR");
	mlx_string_put(data->mlx_ptr, data->win_ptr, i, (W_WIDTH / 3) - (45 * 2),
		0xffffff, "+/-:             ZOOM");
	mlx_string_put(data->mlx_ptr, data->win_ptr, i, (W_WIDTH / 3) - (45 * 1),
		0xffffff, "ARROWS:          CHANGE POSITION ON XY");
	mlx_string_put(data->mlx_ptr, data->win_ptr, i, (W_WIDTH / 3) - (45 * 0),
		0xffffff, "C:               RESET COLOR");
	mlx_string_put(data->mlx_ptr, data->win_ptr, i, (W_WIDTH / 3) - (45 * -1),
		0xffffff, "SPACE:           RESET POSITION, ZOOM AND ITERATION");
	mlx_string_put(data->mlx_ptr, data->win_ptr, i, (W_WIDTH / 3) - (45 * -2),
		0xffffff, "M:               TOGGLE MOUSE MOVE (ONLY JULIA)");
	mlx_string_put(data->mlx_ptr, data->win_ptr, i, (W_WIDTH / 3) - (45 * -3),
		0xffffff, "MOUSE WHEEL:     ZOOM ON CURSOR");
	show_menu_connt(&*data);
}

void		show_menu2(t_data *data)
{
	int		i;

	i = ((W_WIDTH / 4) - 45) / 2;
	mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr2,
		(*data).img_ptr_menu, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr2, (W_WIDTH / 4) - 45, 45,
		0xffffff, "INFO");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, i, (W_WIDTH / 3) - (45 * 4),
		0xffffff, "Q/W/E:           R/G/B PLUS COLOR");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, i, (W_WIDTH / 3) - (45 * 3),
		0xffffff, "A/S/D:           R/G/B MINUS COLOR");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, i, (W_WIDTH / 3) - (45 * 2),
		0xffffff, "+/-:             ZOOM");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, i, (W_WIDTH / 3) - (45 * 1),
		0xffffff, "ARROWS:          CHANGE POSITION ON XY");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, i, (W_WIDTH / 3) - (45 * 0),
		0xffffff, "C:               RESET COLOR");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, i, (W_WIDTH / 3) - (45 * -1),
		0xffffff, "SPACE:           RESET POSITION, ZOOM AND ITERATION");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, i, (W_WIDTH / 3) - (45 * -2),
		0xffffff, "M:               TOGGLE MOUSE MOVE (ONLY JULIA)");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, i, (W_WIDTH / 3) - (45 * -3),
		0xffffff, "MOUSE WHEEL:     ZOOM ON CURSOR");
	show_menu_2_connt(&*data);
}

void		otrisovka_all(t_data *data, t_thread *tr)
{
	if (data->win_thread1 == tr)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr,
			(*data).img_ptr, 0, 0);
		if (data->menu_show1 == 1)
			show_menu(&(*data));
		else
			mlx_string_put(data->mlx_ptr, data->win_ptr, 5, W_HEIGHT - 25,
				0xffffff, "N - KEY INFO");
	}
	else
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr2);
		mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr2,
			(*data).img_ptr2, 0, 0);
		if (data->menu_show2 == 1)
			show_menu2(&(*data));
		else
			mlx_string_put(data->mlx_ptr, data->win_ptr2, 5, W_HEIGHT - 25,
				0xffffff, "N - KEY INFO");
	}
}

void		paint_fractal(t_data *data, int win)
{
	if (win == 1)
	{
		data->zoom = &data->zoom_w1;
		data->mx = &data->movex_w1;
		data->my = &data->movey_w1;
		data->fractol = &data->fractol_w1;
		data->win_thread = data->win_thread1;
	}
	else if (win == 2)
	{
		data->zoom = &data->zoom_w2;
		data->mx = &data->movex_w2;
		data->my = &data->movey_w2;
		data->fractol = &data->fractol_w2;
		data->win_thread = data->win_thread2;
	}
	create_tread_to_print((void*)main_cycle, &(*data), (*data).win_thread);
}

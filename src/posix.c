/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:14:23 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/30 12:43:26 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		create_tread_to_print(void (*fractal), t_data *data, t_thread *tr)
{
	pthread_create(&(*data).tread[0].tread, NULL,
		fractal, &(tr));
	pthread_create(&(*data).tread[1].tread, NULL,
		fractal, &(tr)->next);
	pthread_create(&(*data).tread[2].tread, NULL,
		fractal, &(tr)->next->next);
	pthread_create(&(*data).tread[3].tread, NULL,
		fractal, &(tr)->next->next->next);
	pthread_join((*data).tread[0].tread, NULL);
	pthread_join((*data).tread[1].tread, NULL);
	pthread_join((*data).tread[2].tread, NULL);
	pthread_join((*data).tread[3].tread, NULL);
	otrisovka_all(&(*data), &*tr);
}

void		show_menu_2_connt(t_data *data)
{
	int		i;
	char	*str;

	i = ((W_WIDTH / 4) - 45) / 2;
	mlx_string_put(data->mlx_ptr, data->win_ptr2, i, (W_WIDTH / 3) - (45 * -4),
		0xffffff, "N:               SHOW/HIDE KEY INFO");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, i, (W_WIDTH / 3) - (45 * -5),
		0xffffff, "</>:             CHANGE ITERATION");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 5, W_HEIGHT - 25,
		0xffffff, "I:");
	str = ft_itoa(data->iter);
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 30, W_HEIGHT - 25,
		color_irgb(data->iter, data->t_rgb.r,
		data->t_rgb.g, data->t_rgb.b), str);
	free(str);
}

void		show_menu_connt(t_data *data)
{
	int		i;
	char	*str;

	i = ((W_WIDTH / 4) - 45) / 2;
	mlx_string_put(data->mlx_ptr, data->win_ptr, i, (W_WIDTH / 3) - (45 * -4),
		0xffffff, "N:               SHOW/HIDE KEY INFO");
	mlx_string_put(data->mlx_ptr, data->win_ptr, i, (W_WIDTH / 3) - (45 * -5),
		0xffffff, "</>:             CHANGE ITERATION");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, W_HEIGHT - 25,
		0xffffff, "I:");
	str = ft_itoa(data->iter);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, W_HEIGHT - 25,
		color_irgb(data->iter, data->t_rgb.r,
		data->t_rgb.g, data->t_rgb.b), str);
	free(str);
}

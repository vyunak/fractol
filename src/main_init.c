/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:09:13 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/29 16:12:31 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		create_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	(*data).iter = 100;
	data->img_ptr_menu = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->idata_ptr_menu = (int*)mlx_get_data_addr(data->img_ptr_menu,
		&data->bpp, &data->size_line, &data->endian);
	paint_menu(&(*data));
	init_key_array(&(*data));
	if (data->fractol_w1 != 0)
	{
		data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, "1");
		data->img_ptr = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
		data->idata_ptr = (int*)mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->size_line, &data->endian);
		hook_and_paint(&*data);
	}
	if (data->fractol_w2 != 0)
	{
		data->win_ptr2 = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, "2");
		data->img_ptr2 = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
		data->idata_ptr2 = (int*)mlx_get_data_addr(data->img_ptr2, &data->bpp,
			&data->size_line, &data->endian);
		hook_and_paint_w2(&*data);
	}
	mlx_loop(data->mlx_ptr);
}

int			set_data_fractol(t_data *data, char *av)
{
	if (!av[1] && av[0] >= '1' && av[0] <= '9')
	{
		if (data->fractol_w1 == 0)
			data->fractol_w1 = ft_atoi(av);
		else if (data->fractol_w2 == 0)
			data->fractol_w2 = ft_atoi(av);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

void		validate_avc(int ac, char **av, t_data *data)
{
	int		x;

	x = 0;
	if (ac > 1)
	{
		while (++x < ac)
		{
			if (ft_strcmp("-n", av[x]) == 0 && av[x + 1])
				x++;
			else
				usage();
			if (av[x][1] || set_data_fractol(&(*data), av[x]) == 0)
				usage();
		}
	}
	else
		usage();
}

void		init_tread(t_data *data)
{
	pthread_t	tread1;
	pthread_t	tread2;
	pthread_t	tread3;
	pthread_t	tread4;

	ft_bzero(&tread1, sizeof(tread1));
	ft_bzero(&tread2, sizeof(tread2));
	ft_bzero(&tread3, sizeof(tread3));
	ft_bzero(&tread4, sizeof(tread4));
	data->tread[0].tread = tread1;
	data->tread[1].tread = tread2;
	data->tread[2].tread = tread3;
	data->tread[3].tread = tread4;
}

int			main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	data.zoom_w1 = 0.5;
	data.t_rgb.r = 0;
	data.t_rgb.g = 8;
	data.t_rgb.b = 0;
	data.zoom_w2 = 0.5;
	validate_avc(ac, av, &data);
	if (W_WIDTH < 300 || W_WIDTH < W_HEIGHT)
		usage();
	init_tread(&data);
	create_window(&data);
	return (1);
}

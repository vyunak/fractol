/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:11:09 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/30 12:43:50 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_WIDTH 1000
# define W_HEIGHT 700
# define TCOMPLEX complex double
# include <math.h>
# include <pthread.h>
# include <mlx.h>
# include <complex.h>
# include "../libft/libft.h"

typedef struct			s_thread
{
	int					start_x;
	int					start_y;
	int					end_x;
	int					end_y;
	struct s_data		*data;
	int					**img;
	struct s_thread		*next;
}						t_thread;

typedef struct			s_ntrd
{
	pthread_t			tread;
}						t_ntrd;

typedef struct			s_data
{
	int					*fractol;
	int					fractol_w1;
	int					fractol_w2;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*win_ptr2;
	void				*img_ptr;
	void				*img_ptr_menu;
	int					*idata_ptr_menu;
	void				*img_ptr2;
	int					*idata_ptr;
	int					*idata_ptr2;
	int					bpp;
	int					size_line;
	int					endian;
	double				mouse_x;
	double				mouse_y;
	double				*mx;
	double				movex_w1;
	double				movex_w2;
	double				*my;
	double				movey_w1;
	double				movey_w2;
	double				*zoom;
	double				zoom_w1;
	double				zoom_w2;
	int					iter;
	int					mouse_mod1;
	int					mouse_mod2;
	int					key_array[128];
	int					menu_show1;
	int					menu_show2;
	t_ntrd				tread[4];
	struct s_thread		*win_thread;
	struct s_thread		*win_thread1;
	struct s_thread		*win_thread2;
	struct				s_rgb
	{
		int				r;
		int				g;
		int				b;
	}					t_rgb;
}						t_data;

typedef struct			s_julia
{
	double				cre;
	double				cim;
	double				re;
	double				im;
	double				oldre;
	double				oldim;
}						t_itfr;

int						mandelbrot(t_data *data, t_itfr *it, int i);
int						burningship(t_data *data, t_itfr *it, int i);
int						julia_set(t_data *data, t_itfr *it, int i);
int						newtone(t_data *data, t_itfr *it, int i);
int						get_color(unsigned int i, t_data data);
int						color_irgb(unsigned int i, int r, int g, int b);
int						color_argb(unsigned int a, unsigned int r,
	unsigned int g, unsigned int b);
double					min_double(double t1, double t2);
int						ft_exit(void);
void					create_window(t_data *data);
int						set_data_fractol(t_data *data, char *av);
void					validate_avc(int ac, char **av, t_data *data);
void					init_tread(t_data *data);
void					calc_posix(t_data *data, t_thread **tread, int **img);
void					paint_menu(t_data *data);
void					show_menu(t_data *data);
void					show_menu2(t_data *data);
void					otrisovka_all(t_data *data, t_thread *tr);
void					paint_fractal(t_data *data, int win);
double					new_ri(t_data *data, int xy, int i, double movexy);
void					main_cycle(t_thread **tread);
void					usage(void);
void					pos_init(t_data *data, t_thread **tread, int **img,
	int ntr);
void					pos_set_data(t_data *data, t_thread *tmp, int **img,
	int x);
int						mouse_move(int x, int y, t_data *data);
int						mouse_zoom(int g, int x, int y, t_data *data);
int						mouse_zoom2(int g, int x, int y, t_data *data);
int						mouse_move2(int x, int y, t_data *data);
void					reset_w1(t_data *data);
int						key_press(int keycode, t_data *data);
int						key_press_w2(int keycode, t_data *data);
void					init_key_array(t_data *data);
void					hook_and_paint(t_data *data);
void					hook_and_paint_w2(t_data *data);
void					reset_w2(t_data *data);
void					reset_color(t_data *data);
void					next_lvl(int keycode, t_data *data);
void					kwrite(int keycode, t_data *data);
void					kwrite_2(int keycode, t_data *data);
void					create_tread_to_print(void (*fractal), t_data *data,
	t_thread *tr);
void					show_menu_connt(t_data *data);
void					show_menu_2_connt(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:43:21 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/26 19:44:35 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define KEY_ESC 65307
# define DESTROY_NOTIFY 17
# define WIDTH 700
# define HEIGHT 700
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP
}			t_ftype;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_ftype		fractal_type;
	t_img		img;
	int			mx_it;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		julia_c_r;
	double		julia_c_i;
	double		z_r_tmp;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
}				t_data;

void	ft_error(char *msg, int code, t_data *data);
void	print_help(void);
int		handle_keypress(int keysym, void *d);
int		handle_destroy(void *d);
int		get_color(int iterations, int max_iterations);
void	parse_arguments(int c, char **v, t_data *data);
void	put_pixel(t_img *img, int x, int y, int color);
void	render_fractal(t_data *data);
void	cleanup(t_data *data);
int		mouse_hook(int button, int x, int y, t_data *d);
void	fractal_logic(t_data *d, int *iter);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:31:41 by ridoming          #+#    #+#             */
/*   Updated: 2025/07/23 12:31:43 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

# define KEY_ESC 65307
# define DESTROY_NOTIFY 17
# define WIDTH 750
# define HEIGHT 750
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define BUTTON_PRESS_MASK (1L<<2)

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "./minilibx-linux/mlx.h"
#include "libft/libft.h"

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
} t_ftype;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_ftype		fractal_type;
	t_img		img;
	int			max_iter;
	double		zoom;
	double		offset_x;
	double		offset_y;
} t_data;

void	ft_error(char *msg, int code);
void	print_help(void);
int		handle_keypress(int keysym, void *d);
int		handle_destroy(void *d);
void	parse_arguments(int c, char **v, t_data *data);
void	put_pixel(t_img *img, int x, int y, int color);
void	render_fractal(t_data *data);


# endif
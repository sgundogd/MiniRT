/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:36:36 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/24 04:29:21 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
#include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "./get_next_line.h"
# include "./vector.h"
#include "./keys.h"

# define TOL 1E-4
# define INF INFINITY
# define SHIFT_VAL 2

# define WIDTH 800
# define HEIGHT 600
# define V_D 2

#define IS_OBJECT(type) (type == SPHERE || type == PLANE || type == CYLINDER)

typedef struct s_mlx
{
	void	*mlx_p;
	void	*win_p;
	void	*img_p;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_roots
{
	double	t1;
	double	t2;
}	t_roots;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

typedef enum e_type
{
	PLANE,
	SPHERE,
	CYLINDER,
}	t_type;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_sphere
{
	t_color			color;
	t_vec3			center;
	double			r;
}	t_sphere;

typedef struct s_plane
{
	t_color			color;
	t_vec3			normal;
	t_vec3			point;
}	t_plane;

typedef struct s_cylinder
{
	t_color				color;
	t_vec3				origin;
	t_vec3				dir;
	double				r;
	double				height;
}	t_cylinder;


typedef struct s_obj
{
	void			*obj;
	t_type			type;
	unsigned int	idx;
}	t_obj;

typedef struct s_light
{
	t_vec3	origin;
	double	brightness;
}	t_light;

typedef struct s_ambient
{
	double			brightness;
	t_color			color;
}	t_ambient;

typedef struct s_cam
{
	t_vec3	origin;
	t_vec3	dir;
	double	fov;
}	t_cam;

typedef struct t_screen
{
	double	aspect_ratio;
	double	half_height;
	double	half_width;
	double	viewport_height;
	double	viewport_width;
}	t_screen;

typedef struct s_data
{
	int			fd;
	int			a;
	int			c;
	int			l;
	int			obj_count;
	t_mlx		*mlx;
	t_cam		*cam;
	t_screen	*screen;
	t_ambient	*ambient_light;
	t_light		*light;
	t_obj		*obj_set;
}	t_data;

int		control_extension(char *str);
void	initialize(t_data *data, char *str);
void	init_fd(t_data *data, char *str);
void	close_fd(t_data *data);
void	init_elements(t_data *data);
int		find_and_direct(char *line, t_data *data);
void	allocate(t_data *d);

int		init_ambient(t_data *data, char *line);
int		init_cam(t_data *data, char *line);
int		init_light(t_data *data, char *line);
int		init_sp(t_data *data, char *line, int index);
int		init_pl(t_data *data, char *line, int index);
int		init_cy(t_data *data, char *line, int index);
int		init_obj(t_data *data, char *line, int type);

int		size_2d(char **ptr);
int		ft_strcmp(char *s1, char *s2);
void	control_elements(t_data *data);
void	free_2d(char **d);
void	obj_counter(t_data *data);

void	set_sphere(t_data *d, t_sphere *s, int i);
void	set_stuffs(t_data *d);
void	main_loop(t_data *d);

#endif

#ifndef RT_H
# define RT_H

#include "keys.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vector.h"
#include "../lib/mlx/mlx.h"


#include <stdio.h>

#define TOL 1E-4
#define INF INFINITY
#define SHIFT_VAL 2

#define V_WIDTH 800
#define V_HEIGHT 600
#define V_D 2

#define IS_OBJECT(type) (type == SPHERE || type == PLANE || type == CYLINDER)

typedef struct	s_roots {
	double t1;
	double t2;
} t_roots;

typedef struct	s_ray {
	t_vec3	origin;
	t_vec3	dir;
} t_ray;

typedef struct	s_cam {
	t_vec3	origin;
	t_vec3	dir;
	double	fov;
} t_cam;

typedef enum type {
	PLANE,
	SPHERE,
	CYLINDER,
	LIGHT,
} e_type;

typedef struct s_color {
	int r;
	int g;
	int b;
}	t_color;

typedef struct s_sphere {
	t_vec3			center;
	double			r;
	t_color			color;
} t_sphere;

typedef struct s_plane {
	t_vec3			normal;
	t_vec3			point;
	t_color			color;
} t_plane;

typedef struct s_cylinder {
	t_vec3			origin;
	t_vec3			dir;
	double			r;
	t_color			color;
} t_cylinder;

typedef struct s_triangle {
	t_vec3			p1;
	t_vec3			p2;
	t_vec3			p3;
	t_color			color;
} t_triangle;

typedef struct s_light {
	t_vec3			origin;
	t_color			color;
} t_light;

typedef struct s_mlx {
	void	*mlx_p;
	void	*win_p;
	void	*img_p;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_parsed_objs {
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
} t_parsed_objs;

typedef struct s_obj {
	void			*obj;
	e_type			type;
	unsigned int	idx;
} t_obj;

typedef struct t_screen {
	double	aspect_ratio;
	double	half_height;
	double	half_width;
	double	viewport_height;
	double	viewport_width;
} t_screen;

typedef struct s_general {
	t_mlx			*mlx;
	t_cam			*cam;
	t_screen		*screen;
	unsigned int	obj_count;
	t_obj			*obj_set;
	t_light			*light;

}	t_general;

void	allocate(t_general *d);
void	set_sphere(t_general *d, t_sphere *s, int i);
void	set_stuffs(t_general *d);
void	main_loop(t_general *d);

#endif

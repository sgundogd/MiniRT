/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:36:36 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/22 15:39:10 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_xyz//kordinat için ortak struct
{
	double	x;
	double	y;
	double	z;
}	t_xyz;

typedef struct s_sphere //sphere için struct
{
	t_color			sp_rgb; //rengi
	t_xyz			sp_xyz; //koordinatları
	double			sp_diameter; //çapı
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane //plane için struct
{
	t_color			pl_rgb;//rengi
	t_xyz			pl_xyz;//koordinatları
	t_xyz			pl_xyz_3d;//normal doğrusu gibi bişi
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder//cylinder için struct
{
	t_color				cy_rgb;//renk
	t_xyz				cy_xyz;//koordinat
	t_xyz				cy_xyz_3d;//normal doğrusu
	double				cy_diameter;//çapı
	double				cy_height;//boyu
	struct s_cylinder	*next;
}	t_cylinder;

//typedef struct s_obj//cylinder için struct
// {
// 	void *data;
// 	struct s_obj	*next;
// }	t_obj;

typedef struct s_plane //plane için struct
{
	t_color			pl_rgb;//rengi
	t_xyz			pl_xyz;//koordinatları
	t_xyz			pl_xyz_3d;//normal doğrusu gibi bişi
	struct s_plane	*next;
}	t_plane;

typedef struct s_file//genel map
{
	int			fd;
	int			a;
	double		a_ratio;
	t_color		a_rgb;
	int			c;
	t_xyz		c_xyz;
	t_xyz		c_xyz_3d;
	double		c_horizon;
	int			l;
	t_xyz		l_xyz;
	double		l_ratio;
	t_color		l_rgb;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
}	t_file;

int		control_extension(char *str);
void	initialize(t_file *file, char *str);
void	init_fd(t_file *file, char *str);
void	init_elements(t_file *file);
int		find_and_direct(char *line, t_file *file);

int		init_a(t_file *file, char *line);
int		init_c(t_file *file, char *line);
int		init_l(t_file *file, char *line);
int		init_sp(t_file *file, char *line);
int		init_pl(t_file *file, char *line);
int		init_cy(t_file *file, char *line);

int		size_2d(char **ptr);
int		ft_strcmp(char *s1, char *s2);
void	control_elements(t_file *file);
void	free_2d(char **d);

#endif

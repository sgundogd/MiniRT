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

typedef struct s_color{ //renkler için ortak struct
    double r;
    double g;
    double b;
} t_color;

typedef struct s_xyz{ //kordinat için ortak struct
    double x;
    double y;
    double z;
} t_xyz;

typedef struct  s_sphere{ //sphere için struct
    t_color sp_rgb; //rengi
    t_xyz sp_xyz;  //koordinatları
    double sp_diameter; //çapı
    struct s_sphere	*next;
} t_sphere;

typedef struct  s_plane{//plane için struct
    t_color pl_rgb;//rengi
    t_xyz pl_xyz;//koordinatları
    t_xyz pl_xyz_3d;//normal doğrusu gibi bişi
    struct s_plane	*next;
} t_plane;

typedef struct  s_cylinder{//cylinder için struct
    t_color cy_rgb;//renk
    t_xyz cy_xyz;//koordinat
    t_xyz cy_xyz_3d;//normal doğrusu
    double cy_diameter;//çapı
    double cy_height;//boyu
    struct s_cylinder	*next;
} t_cylinder;

typedef struct  s_file{//genel map
    int fd;
    int A;
    double A_ratio;
    t_color A_rgb;
    int C;
    t_xyz C_xyz;
    t_xyz C_xyz_3d;
    double C_Horizon;
    int L;
    t_xyz L_xyz;
    double L_ratio;
    t_color L_rgb;
    t_sphere *sp;
    t_plane *pl;
    t_cylinder *cy;
} t_file;


int control_extension(char *str);
void initialize(t_file *file, char *str);
void init_fd(t_file *file, char *str);
void init_elements(t_file *file);
int find_and_direct(char *line,t_file *file);

int init_A (t_file *file, char *line);
int init_C (t_file *file, char *line);
int init_L (t_file *file, char *line);
int init_sp(t_file *file, char *line);
int init_pl (t_file *file, char *line);
int init_cy (t_file *file, char *line);


int size_2d(char **ptr);
int	ft_strcmp(char *s1, char *s2);
void control_elements(t_file* file);
void	free_2d(char **d);

#endif
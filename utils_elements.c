#include "minirt.h"

int init_A (t_file *file, char *line)
{
    char **ptr;
    char **ptr_2;

    ptr = ft_split(line, ' ');
    if(size_2d(ptr) != 3)
        return(printf("Wrong Definition"),0);
    ptr_2 = ft_split(ptr[2], ',');
    if(size_2d(ptr_2) != 3)
        return(printf("Wrong Definition"),0);
    file->A_ratio = atof(ptr[1]);
    file->A_rgb.r = atof(ptr_2[0]);
    file->A_rgb.g = atof(ptr_2[1]);
    file->A_rgb.b = atof(ptr_2[2]);
    file->A += 1;
    free_2d(ptr);
    free_2d(ptr_2);
    return(1);
}

int init_C (t_file *file, char *line)
{
    char **ptr;
    char **ptr_2;
    char **ptr_3;

    ptr = ft_split(line, ' ');
    if(size_2d(ptr) != 4)
        return(printf("Wrong Definition"),0);
    ptr_2 = ft_split(ptr[1], ',');
    ptr_3 = ft_split(ptr[2], ',');
    if(size_2d(ptr_2) != 3 || size_2d(ptr_3) != 3)
        return(printf("Wrong Definition"),0);
    file->C_xyz.x = atof(ptr_2[0]);
    file->C_xyz.y = atof(ptr_2[1]);
    file->C_xyz.z = atof(ptr_2[2]);
    file->C_xyz_3d.x = atof(ptr_3[0]);
    file->C_xyz_3d.y = atof(ptr_3[1]);
    file->C_xyz_3d.z = atof(ptr_3[2]);
    file->C_Horizon = atof(ptr[3]);
    file->C += 1;
    free_2d(ptr);
    free_2d(ptr_2);
    free_2d(ptr_3);
    return(1);
}

int init_L (t_file *file, char *line)
{
    char **ptr;
    char **ptr_2;
    char **ptr_3;
    

    ptr = ft_split(line, ' ');
    if(size_2d(ptr) != 4)
        return(printf("Wrong Definition"),0);
    ptr_2 = ft_split(ptr[1], ',');
    ptr_3 = ft_split(ptr[3], ',');
    if(size_2d(ptr_2) != 3 || size_2d(ptr_3) != 3)
        return(printf("Wrong Definition"),0);
    file->L_xyz.x = atof(ptr_2[0]);
    file->L_xyz.y = atof(ptr_2[1]);
    file->L_xyz.z = atof(ptr_2[2]);
    file->L_rgb.r = atof(ptr_3[0]);
    file->L_rgb.g = atof(ptr_3[1]);
    file->L_rgb.b = atof(ptr_3[2]);
    file->L_ratio = atof(ptr[2]);
    file->L += 1;
    free_2d(ptr);
    free_2d(ptr_2);
    free_2d(ptr_3);
    return(1);
}

#include "minirt.h"
int main(int ac, char **av)
{
    if(ac!=2 || control_extension(av[1]))
        return(printf("Error: Wrong argument"),1);
    t_file file;
    initialize(&file,av[1]);
    system("leaks MiniRT");
    printf("A: %f %f,%f,%f\n",file.A_ratio, file.A_rgb.r,file.A_rgb.g,file.A_rgb.b);
    printf("C: %f,%f,%f %f\n",file.C_xyz.x, file.C_xyz.y,file.C_xyz.z,file.C_xyz_3d.x);
    printf("sp: %f and %f\n",file.sp->sp_diameter, file.sp->next->sp_diameter);
}

#include "minirt.h"
static t_cylinder	*ft_create(char *line)
{
	t_cylinder	*new;

	new = ft_calloc(sizeof(t_cylinder), 1);
    char **ptr;
    char **ptr_2;
    char **ptr_3;
    char **ptr_4;

    ptr = ft_split(line, ' ');
    if(size_2d(ptr) != 6)
        return(printf("Wrong Definition"),NULL);
    ptr_2 = ft_split(ptr[1], ',');
    ptr_3 = ft_split(ptr[2], ',');
    ptr_4 = ft_split(ptr[5], ',');
    if(size_2d(ptr_2) != 3 || size_2d(ptr_3) != 3 || size_2d(ptr_4) != 3)
        return(printf("Wrong Definition"),NULL);
    new->cy_xyz.x = atof(ptr_2[0]);
    new->cy_xyz.y = atof(ptr_2[1]);
    new->cy_xyz.z = atof(ptr_2[2]);
    new->cy_xyz_3d.x = atof(ptr_3[0]);
    new->cy_xyz_3d.y = atof(ptr_3[1]);
    new->cy_xyz_3d.z = atof(ptr_3[2]);
    new->cy_rgb.r = atof(ptr_4[0]);
    new->cy_rgb.g = atof(ptr_4[1]);
    new->cy_rgb.b = atof(ptr_4[2]);
    new->cy_diameter = atof(ptr[3]);
    new->cy_height = atof(ptr[4]);
	new->next = NULL;
    free_2d(ptr);
    free_2d(ptr_2);
    free_2d(ptr_3);
    free_2d(ptr_4);
	return (new);
}

static t_cylinder *ft_last(t_cylinder *lst)
{
	while (lst)
	{
		if (lst->next)
			lst = lst->next;
		else
			return (lst);
	}
	return (NULL);
}
int init_cy (t_file *file, char *line)
{
	t_cylinder	*tmp;

		if (file->cy)
		{
			tmp = ft_last(file->cy);
			tmp->next = ft_create(line);
            if(tmp->next == 0)
                return(0);
		}
		else
        {
			file->cy = ft_create(line);
            if(file->cy == 0)
                return(0);
        }
        return(1);
}



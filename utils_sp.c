#include "minirt.h"

static t_sphere *ft_create(char *line)
{
	t_sphere *new;
    char **ptr;
    char **ptr_2;
    char **ptr_3;
    
    new = ft_calloc(sizeof(t_sphere), 1);
    ptr = ft_split(line, ' ');
    if(size_2d(ptr) != 4)
        return(printf("Wrong Definition"),NULL);
    ptr_2 = ft_split(ptr[1], ',');
    ptr_3 = ft_split(ptr[3], ',');
    if(size_2d(ptr_2) != 3 || size_2d(ptr_3) != 3 )
        return(printf("Wrong Definition"),NULL);
    new->sp_xyz.x = atof(ptr_2[0]);
    new->sp_xyz.y = atof(ptr_2[1]);
    new->sp_xyz.z = atof(ptr_2[2]);
    new->sp_diameter = atof(ptr[2]);
    new->sp_rgb.r = atof(ptr_3[0]);
    new->sp_rgb.g = atof(ptr_3[1]);
    new->sp_rgb.b = atof(ptr_3[2]);
    free_2d(ptr);
    free_2d(ptr_2);
    free_2d(ptr_3);
	new->next = NULL;
	return (new);
}

static t_sphere *ft_last(t_sphere *lst)
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

int init_sp (t_file *file, char *line)
{
    
	t_sphere	*tmp;

		if ((file->sp))
		{
            
			tmp = ft_last(file->sp);
			tmp->next = ft_create(line);
            if(tmp->next == 0)
                return(0);
		}
		else
        {
			file->sp = ft_create(line);
            if(file->sp == 0)
                return(0);
        }
        return(1);
}
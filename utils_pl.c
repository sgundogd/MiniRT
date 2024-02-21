#include "minirt.h"
static t_plane	*ft_create(char *line)
{
	t_plane	*new;
    char **ptr;
    char **ptr_2;
    char **ptr_3;
    char **ptr_4;
    
    new = ft_calloc(sizeof(t_plane), 1);
    ptr = ft_split(line, ' ');
    if(size_2d(ptr) != 4)
    {
        free_2d(ptr);
        return(printf("Wrong Definition"),NULL);
    }
    ptr_2 = ft_split(ptr[1], ',');
    ptr_3 = ft_split(ptr[2], ',');
    ptr_4 = ft_split(ptr[3], ',');
    if(size_2d(ptr_2) != 3 || size_2d(ptr_3) != 3 || size_2d(ptr_4) != 3)
        return(printf("Wrong Definition"),NULL);
    new->pl_xyz.x = atof(ptr_2[0]);
    new->pl_xyz.y = atof(ptr_2[1]);
    new->pl_xyz.z = atof(ptr_2[2]);
    new->pl_xyz_3d.x = atof(ptr_3[0]);
    new->pl_xyz_3d.y = atof(ptr_3[1]);
    new->pl_xyz_3d.z = atof(ptr_3[2]);
    new->pl_rgb.r = atof(ptr_4[0]);
    new->pl_rgb.g = atof(ptr_4[1]);
    new->pl_rgb.b = atof(ptr_4[2]);
	new->next = NULL;
    free_2d(ptr);
    free_2d(ptr_2);
    free_2d(ptr_3);
    free_2d(ptr_4);
	return (new);
}

static t_plane *ft_last(t_plane *lst)
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
int init_pl (t_file *file, char *line)
{
	t_plane	*tmp;

		if (file->pl)
		{
			tmp = ft_last(file->pl);
			tmp->next = ft_create(line);
            if(tmp->next == 0)
                return(0);
		}
		else
        {
			file->pl = ft_create(line);
            if(file->pl == 0)
                return(0);
        }
        return(1);
}

#include "minirt.h"

int control_extension(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(ft_strcmp(ft_substr(str,i-4,4),".res"));
}
void initialize(t_file *file, char *str)
{
    file->sp = NULL;
    file->cy = NULL;
    file->pl = NULL;
    file->A = 0;
    file->C = 0;
    file->L = 0;
    init_fd(file, str);
    init_elements(file);
    control_elements(file);
}
void init_fd(t_file *file, char *str)
{
    int a;

    a = open(str, O_RDONLY);
    if (a == -1)
    {
        perror("Error");
        exit(1);
    }
    file->fd = a;
}

void init_elements(t_file *file)
{
    char *line;

    line = get_next_line(file->fd);
    while (line)
    {
        if(!find_and_direct(line, file))
        {
            free(line);
            exit(1);
        }
        free(line);
        line = get_next_line(file->fd);
    }
}

int find_and_direct(char *line,t_file *file)
{
    int i;

    i = 0;
    while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
        i++;
    if(line[i] == '\0')
        return(1);
    else if (!ft_strcmp(ft_substr(line,i,2),"A "))
        return(init_A (file, line));
    else if (!ft_strcmp(ft_substr(line,i,2),"C "))
        return(init_C (file, line));
    else if (!ft_strcmp(ft_substr(line,i,2),"L "))
        return(init_L (file, line));   
    else if (!ft_strcmp(ft_substr(line,i,3),"sp "))
        return(init_sp (file, line));
    else if (!ft_strcmp(ft_substr(line,i,3),"pl "))
        return(init_pl (file, line));
    else if (!ft_strcmp(ft_substr(line,i,3),"cy "))
        return(init_cy (file, line));
    else
    {
        printf("An incorrect element or definiton was detected");
        exit(1);
    }
}

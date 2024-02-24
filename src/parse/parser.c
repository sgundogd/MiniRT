/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:27:25 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/24 04:15:21 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	control_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (ft_strcmp(ft_substr(str, i - 3, 3), ".rt"));
}

void	allocate(t_data *d)
{
	d->mlx = malloc(sizeof(t_mlx));
	d->cam = malloc(sizeof(t_cam));
	//d->obj_set = malloc(sizeof(t_obj) * d->obj_count + 1);
	d->screen = malloc(sizeof(t_screen));
	d->light = malloc(sizeof(t_light));
	d->ambient_light = malloc(sizeof(t_ambient));
}

void	initialize(t_data *data, char *str)
{
	data->a = 0;
	data->c = 0;
	data->l = 0;
	data->obj_count = 0;
	data->obj_set = NULL;
	init_fd(data, str);
	obj_counter(data);
	close_fd(data);
	allocate(data);
	init_fd(data, str);
	init_elements(data);
	control_elements(data);
}

void	init_fd(t_data *data, char *str)
{
	int	a;

	a = open(str, O_RDONLY);
	if (a == -1)
	{
		perror("Error");
		exit(1);
	}
	data->fd = a;
}

void	close_fd(t_data *data)
{
	int	a;

	a = close(data->fd);
	if (a == -1)
	{
		perror("Error");
		exit(1);
	}
}

void	init_elements(t_data *data)
{
	char	*line;

	line = get_next_line(data->fd);
	while (line)
	{
		if (!find_and_direct(line, data))
		{
			free(line);
			exit(1);
		}
		free(line);
		line = get_next_line(data->fd);
	}
}

int	find_and_direct(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	if (line[i] == '\0')
		return (1);
	else if (!ft_strcmp(ft_substr(line, i, 2), "A "))
		return (init_ambient (data, line));
	else if (!ft_strcmp(ft_substr(line, i, 2), "C "))
		return (init_cam (data, line));
	else if (!ft_strcmp(ft_substr(line, i, 2), "L "))
		return (init_light (data, line));
	else if (!ft_strcmp(ft_substr(line, i, 3), "sp "))
		return (init_obj (data, line, SPHERE));
	else if (!ft_strcmp(ft_substr(line, i, 3), "pl "))
		return (init_obj (data, line, PLANE));
	else if (!ft_strcmp(ft_substr(line, i, 3), "cy "))
		return (init_obj (data, line, CYLINDER));
	else
	{
		printf ("ERROR!\nAn incorrect element or definiton was detected");
		exit (1);
	}
}

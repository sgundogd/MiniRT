/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:27:25 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/28 16:12:45 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	allocate(t_data *d)
{
	d->mlx = malloc(sizeof(t_mlx));
	d->cam = malloc(sizeof(t_cam));
	new_mlx(d);
	d->screen = malloc(sizeof(t_screen));
	d->light = malloc(sizeof(t_light));
	d->ambient_light = malloc(sizeof(t_ambient));
}

static void	obj_counter(t_data *data)
{
	char	*line;
	int		i;

	line = get_next_line(data->fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		if (line[i] == 'c' || line[i] == 'p' || line[i] == 's')
			data->obj_count += 1;
		free(line);
		line = get_next_line(data->fd);
	}
}

static int	find_and_direct(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	if (line[i] == '\0' || line[i] == '#')
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

static void	init_elements(t_data *data)
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
	close_fd(data);
	control_elements(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:39:23 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/24 03:02:40 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	init_ambient(t_data *data, char *line)
{
	char	**ptr;
	char	**ptr_2;

	ptr = ft_split(line, ' ');
	if (size_2d(ptr) != 3)
		return (printf("Wrong Definition"), 0);
	ptr_2 = ft_split(ptr[2], ',');
	if (size_2d(ptr_2) != 3)
		return (printf("Wrong Definition"), 0);
	data->ambient_light->brightness = atof(ptr[1]);
	data->ambient_light->color.r = atof(ptr_2[0]);
	data->ambient_light->color.g = atof(ptr_2[1]);
	data->ambient_light->color.b = atof(ptr_2[2]);
	data->a += 1;
	free_2d(ptr);
	free_2d(ptr_2);
	return (1);
}

int	init_cam(t_data *data, char *line)
{
	char	**ptr;
	char	**ptr_2;
	char	**ptr_3;

	ptr = ft_split(line, ' ');
	if (size_2d(ptr) != 4)
		return (printf("Wrong Definition"), 0);
	ptr_2 = ft_split(ptr[1], ',');
	ptr_3 = ft_split(ptr[2], ',');
	if (size_2d(ptr_2) != 3 || size_2d(ptr_3) != 3)
		return (printf("Wrong Definition"), 0);
	data->cam->origin.x = atof(ptr_2[0]);
	data->cam->origin.y = atof(ptr_2[1]);
	data->cam->origin.z = atof(ptr_2[2]);
	data->cam->dir.x = atof(ptr_3[0]);
	data->cam->dir.y = atof(ptr_3[1]);
	data->cam->dir.z = atof(ptr_3[2]);
	data->cam->fov = atof(ptr[3]);
	data->c += 1;
	free_2d(ptr);
	free_2d(ptr_2);
	free_2d(ptr_3);
	return (1);
}

int	init_light(t_data *data, char *line)
{
	char	**ptr;
	char	**ptr_2;
	char	**ptr_3;

	ptr = ft_split(line, ' ');
	if (size_2d(ptr) != 4)
		return (printf("Wrong Definition"), 0);
	ptr_2 = ft_split(ptr[1], ',');
	ptr_3 = ft_split(ptr[3], ',');
	if (size_2d(ptr_2) != 3 || size_2d(ptr_3) != 3)
		return (printf("Wrong Definition"), 0);
	data->light->origin.x = atof(ptr_2[0]);
	data->light->origin.y = atof(ptr_2[1]);
	data->light->origin.z = atof(ptr_2[2]);
	data->light->brightness = atof(ptr[2]);
	data->l += 1;
	free_2d(ptr);
	free_2d(ptr_2);
	free_2d(ptr_3);
	return (1);
}

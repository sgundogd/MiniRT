/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:32:43 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/26 13:37:13 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void print_data(t_data data)
{
	printf("Ambient Light Ratio:%f\n", data.ambient_light->brightness);
	printf("\tColor-> r:%d g:%d b:%d\n", data.ambient_light->color.r, data.ambient_light->color.g, data.ambient_light->color.b);
	printf("\nLight Source Ratio: %f\n", data.light->brightness);
	printf("\tPosition: x:%f y:%f z:%f\n", data.light->origin.x, data.light->origin.y, data.light->origin.z);
	printf("\nCamera Position:  x:%f y:%f z:%f\n", data.cam->origin.x, data.cam->origin.y, data.cam->origin.z);
	printf("Camera Direction: x:%f y:%f z:%f\n", data.cam->dir.x, data.cam->dir.y, data.cam->dir.z);
	printf("Camera FOV: %f\n", data.cam->fov);
	printf("\nNumber of Objects: %d\n", data.obj_count);
	for (int i = 0; i < data.obj_count; i++)
	{
		printf("%d.Object Type: %d\n", i + 1 , data.obj_set[i].type);
		printf("\tSphere Radius: %.0f\n", ((t_sphere *)data.obj_set[i].obj)->r);
		printf("\tSphere Position: x:%.0f y:%.0f z:%.0f\n", ((t_sphere *)data.obj_set[i].obj)->center.x, ((t_sphere *)data.obj_set[i].obj)->center.y, ((t_sphere *)data.obj_set[i].obj)->center.z);
		printf("\tSphere Color: r:%d g:%d b:%d\n", ((t_sphere *)data.obj_set[i].obj)->color.r, ((t_sphere *)data.obj_set[i].obj)->color.g, ((t_sphere *)data.obj_set[i].obj)->color.b);
		printf("\n");
	}
}

// https://graphics.cs.wisc.edu/WP/cs559-fall2016/files/2016/12/shirley_chapter_4.pdf

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || control_extension(av[1]))
		return (printf("Error: Wrong argument"), 1);
	initialize(&data, av[1]);
	
	print_data(data);
	

	main_loop(&data);
	return (0);
}


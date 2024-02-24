/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:32:43 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/24 03:59:42 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
//#include "../inc/rt.h"



int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || control_extension(av[1]))
		return (printf("Error: Wrong argument"), 1);
	initialize(&data, av[1]);
	printf("A: %f %d\n",data.ambient_light->brightness, data.ambient_light->color.r);
	printf("C: %f,%f\n",data.cam->origin.x, data.cam->fov);
	printf("sp: %d and %d\n",data.obj_set[0].type, data.obj_set[1].idx);
}

/*int main() {
	t_data genel;

	unsigned short sphere_count = 3;
	genel.obj_count = sphere_count + 0;

	allocate(&genel);
	t_sphere *sphere_set = malloc(sizeof(t_sphere) * sphere_count);
	sphere_set[0] = (t_sphere) { (t_vec3){0, 0, 5}, 1, (t_color){255, 0, 0} };
	sphere_set[1] = (t_sphere) { (t_vec3){0, 0, 5}, 1, (t_color){255, 0, 0} };
	sphere_set[2] = (t_sphere) { (t_vec3){0, 0, 5}, 1, (t_color){255, 0, 0} };
	// unsigned short plane_count = 2;
	// t_plane *plane_set = malloc(sizeof(t_plane) * plane_count);
	// plane_set[0] = (t_plane) { (t_vec3){0, 0, 5}, (t_vec3){0, 1, 0}, (t_color){255, 0, 0} };
	// plane_set[1] = (t_plane) { (t_vec3){0, 0, 5}, (t_vec3){0, 1, 0}, (t_color){255, 0, 0} };

	unsigned short k = -1;
	int i = -1;	while (++i < sphere_count) set_sphere(&genel, &sphere_set[i], ++k);
	//	i = -1;	while (++i < plane_count) set_plane(&genel, &plane_set[i], ++k);


	set_stuffs(&genel);

	main_loop(&genel);
	//mlx_stuffs( &genel);

}*/

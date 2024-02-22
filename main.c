/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:32:43 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/22 14:49:18 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_file	file;

	if (ac != 2 || control_extension(av[1]))
		return (printf("Error: Wrong argument"), 1);
	initialize(&file, av[1]);
	printf("A: %f %f,%f,%f\n",file.a_ratio, file.a_rgb.r,file.a_rgb.g,file.a_rgb.b);
	printf("C: %f,%f,%f %f\n",file.c_xyz.x, file.c_xyz.y,file.c_xyz.z,file.c_xyz_3d.x);
	printf("sp: %f and %f\n",file.sp->sp_diameter, file.sp->next->sp_diameter);
}

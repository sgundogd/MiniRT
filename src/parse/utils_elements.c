/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:39:23 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/23 21:18:22 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	init_a(t_parse *file, char *line)
{
	char	**ptr;
	char	**ptr_2;

	ptr = ft_split(line, ' ');
	if (size_2d(ptr) != 3)
		return (printf("Wrong Definition"), 0);
	ptr_2 = ft_split(ptr[2], ',');
	if (size_2d(ptr_2) != 3)
		return (printf("Wrong Definition"), 0);
	file->a_ratio = atof(ptr[1]);
	file->a_rgb.r = atof(ptr_2[0]);
	file->a_rgb.g = atof(ptr_2[1]);
	file->a_rgb.b = atof(ptr_2[2]);
	file->a += 1;
	free_2d(ptr);
	free_2d(ptr_2);
	return (1);
}

int	init_c(t_parse *file, char *line)
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
	file->c_xyz.x = atof(ptr_2[0]);
	file->c_xyz.y = atof(ptr_2[1]);
	file->c_xyz.z = atof(ptr_2[2]);
	file->c_xyz_3d.x = atof(ptr_3[0]);
	file->c_xyz_3d.y = atof(ptr_3[1]);
	file->c_xyz_3d.z = atof(ptr_3[2]);
	file->c_horizon = atof(ptr[3]);
	file->c += 1;
	free_2d(ptr);
	free_2d(ptr_2);
	free_2d(ptr_3);
	return (1);
}

int	init_l(t_parse *file, char *line)
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
	file->l_xyz.x = atof(ptr_2[0]);
	file->l_xyz.y = atof(ptr_2[1]);
	file->l_xyz.z = atof(ptr_2[2]);
	file->l_rgb.r = atof(ptr_3[0]);
	file->l_rgb.g = atof(ptr_3[1]);
	file->l_rgb.b = atof(ptr_3[2]);
	file->l_ratio = atof(ptr[2]);
	file->l += 1;
	free_2d(ptr);
	free_2d(ptr_2);
	free_2d(ptr_3);
	return (1);
}

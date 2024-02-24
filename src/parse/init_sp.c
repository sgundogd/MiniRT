/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:42:56 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/24 03:17:25 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	init_sp(t_data *data, char *line, int index)
{
	t_sphere	*new;
	char		**ptr;
	char		**ptr_2;
	char		**ptr_3;

	new = ft_calloc(sizeof(t_sphere), 1);
	ptr = ft_split(line, ' ');
	if (size_2d(ptr) != 4)
		return (printf("Wrong Definition"), 0);
	ptr_2 = ft_split(ptr[1], ',');
	ptr_3 = ft_split(ptr[3], ',');
	if (size_2d(ptr_2) != 3 || size_2d(ptr_3) != 3)
		return (printf("Wrong Definition"), 0);
	new->center.x = atof(ptr_2[0]);
	new->center.y = atof(ptr_2[1]);
	new->center.z = atof(ptr_2[2]);
	new->r = atof(ptr[2]);
	new->color.r = atof(ptr_3[0]);
	new->color.g = atof(ptr_3[1]);
	new->color.b = atof(ptr_3[2]);
	free_2d(ptr);
	free_2d(ptr_2);
	free_2d(ptr_3);
	data->obj_set[index].obj = new;
	return (1);
}

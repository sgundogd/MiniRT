/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:41:12 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/24 03:13:46 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	init_pl(t_data *data, char *line, int index)
{
	t_plane	*new;
	char	**ptr;
	char	**ptr_2;
	char	**ptr_3;
	char	**ptr_4;

	new = ft_calloc(sizeof(t_plane), 1);
	ptr = ft_split(line, ' ');
	if (size_2d(ptr) != 4)
	{
		free_2d(ptr);
		return (printf("Wrong Definition"), 0);
	}
	ptr_2 = ft_split(ptr[1], ',');
	ptr_3 = ft_split(ptr[2], ',');
	ptr_4 = ft_split(ptr[3], ',');
	if (size_2d(ptr_2) != 3 || size_2d(ptr_3) != 3 || size_2d(ptr_4) != 3)
		return (printf("Wrong Definition"), 0);
	new->point.x = atof(ptr_2[0]);
	new->point.y = atof(ptr_2[1]);
	new->point.z = atof(ptr_2[2]);
	new->normal.x = atof(ptr_3[0]);
	new->normal.y = atof(ptr_3[1]);
	new->normal.z = atof(ptr_3[2]);
	new->color.r = atof(ptr_4[0]);
	new->color.g = atof(ptr_4[1]);
	new->color.b = atof(ptr_4[2]);
	free_2d(ptr);
	free_2d(ptr_2);
	free_2d(ptr_3);
	free_2d(ptr_4);
	data->obj_set[index].obj = new;
	return (1);
}

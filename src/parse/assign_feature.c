/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_feature.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:17:41 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/28 18:08:21 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	ft_assign_color(char **ptr, t_color *clr)
{
	if (size_2d(ptr) != 3)
		return (free_2d(ptr), 0);
	clr->r = atof(ptr[0]);
	clr->g = atof(ptr[1]);
	clr->b = atof(ptr[2]);
	if (control_rgb(*clr) == 0)
		return (free_2d(ptr), 0);
	free_2d(ptr);
	return (1);
}

int	ft_assign_vec(char **ptr, t_vec3 *vec)
{
	if (size_2d(ptr) != 3)
	{
		free_2d(ptr);
		return (0);
	}
	vec->x = atof(ptr[0]);
	vec->y = atof(ptr[1]);
	vec->z = atof(ptr[2]);
	if (vec->x == INFINITY || vec->y == INFINITY || vec->z == INFINITY)
		return (free_2d(ptr), 0);
	free_2d(ptr);
	return (1);
}

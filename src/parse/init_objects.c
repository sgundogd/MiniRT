/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:52:24 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/24 04:08:37 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	init_obj(t_data *data, char *line, int type)
{
	int	i;

	i = 0;
	if (data->obj_count == 0)
		return (1);
	if ((data->obj_set))
	{
		while (data->obj_set[i].obj)
			i++;
	}
	else
		data->obj_set = ft_calloc(sizeof(t_obj), data->obj_count + 1);
	data->obj_set[i].idx = i;
	data->obj_set[i + 1].obj = NULL;
	data->obj_set[i].type = type;
	if (type == 0)
		return (init_pl(data, line, i));
	if (type == 1)
		return (init_sp(data, line, i));
	if (type == 2)
		return (init_cy(data, line, i));
	return (0);
}

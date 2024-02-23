/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:47:32 by ogcetin           #+#    #+#             */
/*   Updated: 2024/02/23 21:44:33 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"


t_vec3	v_add(const t_vec3 *u, const t_vec3 *v)
{
	return ((t_vec3){u->x + v->x, u->y + v->y, u->z + v->z});
}

t_vec3	v_substract(const t_vec3 *u, const t_vec3 *v)
{
	return ((t_vec3){u->x - v->x, u->y - v->y, u->z - v->z});
}

double	v_dot(const t_vec3 *u, const t_vec3 *v)
{
	return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

t_vec3	v_cross(const t_vec3 *u, const t_vec3 *v)
{
	return ((t_vec3){(u->y * v->z - u->z * v->y), (u->z * v->x - u->x * v->z), (u->x * v->y - u->y * v->x)});
}

double	v_length(const t_vec3 *u)
{
	return(sqrtf(u->x * u->x + u->y * u->y + u->z + u->z));
}

double	r_squared_distance(const t_vec3 *p, const t_vec3 *c)
{
	return ((p->x - c->x * p->x - c->x) + (p->y - c->y * p->y - c->y) + (p->z - c->z * p->z - c->z));
}

double	r_distance(const t_vec3 *p, const t_vec3 *c)
{
	return (sqrtf(r_squared_distance(p, c)));
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:47:32 by ogcetin           #+#    #+#             */
/*   Updated: 2024/02/26 10:10:57 by ogcetin          ###   ########.fr       */
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
t_vec3	v_multiply(const t_vec3 *u, double s)
{
	if (s == INFINITY)
		return ((t_vec3){INFINITY, INFINITY, INFINITY});
	return ((t_vec3){u->x * s, u->y * s, u->z * s});
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
	return(sqrtf(u->x * u->x + u->y * u->y + u->z * u->z));
}

t_vec3	v_normalize(const t_vec3 *u)
{
	double	len;

	len = v_length(u);
	if (len == 0)
		return ((t_vec3){0, 0, 0});
	return ((t_vec3){u->x / len, u->y / len, u->z / len});
}

double	r_squared_distance(const t_vec3 *p, const t_vec3 *c)
{
	return ((p->x - c->x * p->x - c->x) + (p->y - c->y * p->y - c->y) + (p->z - c->z * p->z - c->z));
}

double	r_distance(const t_vec3 *p, const t_vec3 *c)
{
	return (sqrtf(r_squared_distance(p, c)));
}


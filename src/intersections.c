/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 23:20:08 by ogcetin           #+#    #+#             */
/*   Updated: 2024/02/26 02:23:22 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	f_get_color(const t_obj *obj)
{
	if (obj->type == SPHERE)
		return (((t_sphere *)obj->obj)->color);
	// else if (obj->type == PLANE)
	// 	return (((t_plane *)obj->obj)->color);
	// else if (obj->type == CYLINDER)
	// 	return (((t_cylinder *)obj->obj)->color);
	// else if (obj->type == SQUARE)
	// 	return (((t_square *)obj->obj)->color);
	return ((t_color){0, 0, 0});
}

double	intersects_sphere(const t_ray *ray, const t_sphere *sp);

double	f_intersects(const t_ray *ray, const t_obj *obj)
{
	if (obj->type == SPHERE)
		return (intersects_sphere(ray, (t_sphere *)obj->obj));
	// else if (obj->type == PLANE)
	// 	return (intersects_plane(ray, (t_plane *)obj->obj));
	// else if (obj->type == CYLINDER)
	// 	return (intersects_cylinder(ray, (t_cylinder *)obj->obj));
	// else if (obj->type == SQUARE)
	// 	return (intersects_square(ray, (t_square *)obj->obj));
	
	return (0.0);
}

double	intersects_sphere(const t_ray *ray, const t_sphere *sp)
{
	t_vec3	o_to_c;
	double	b;
	double	c;
	double	h;
	double	t;

	o_to_c = v_substract(&ray->origin, &sp->center);
	b = v_dot(&o_to_c, &ray->dir);
	c = v_dot(&o_to_c, &o_to_c) - sp->r * sp->r;
	h = b * b - c;
	if (h < 0.0)
		return (INF);
	h = sqrt(h);
	t = -b - h;
	if (t < TOL)
		return (0.0); // Inside the sphere
	return (t);
}

